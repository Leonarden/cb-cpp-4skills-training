#!/bin/bash

#Variable declaration
cur_path="$PWD"
#cur_path_len=$(#$cur_path)

#echo "Cur path len: $cur_path_len"

to_rep="int main()"
rep_prefix1="int "
rep_prefix2="exec"
rep_infix=""
rep_posfix="() "
#actual replacing variable
rep=""
#for adding include files to appheaders
m_include="$cur_path/appheaders.h"
#for help function code menu "./funcodelist.txt
fcl_list="$cur_path/funcodelist.txt"
#Leaf nodes generation
templateFile="$cur_path/util_sub.templ"
to_generate="$cur_path/util_sub.h"
#specific to leaf node generation
node_id="0"
node_key=""  # it will be rep_infix
node_text="" # \"rep_infix - Node fuction\"
node_func="" # &exec$rep_infix
# generated node counter
n_counter=0
#lines calling a function optional: write to utilfile function(counter, node_id,node_key,node_text
n_line1="" # 
n_line2=""
n_line3=""

cd $cur_path

#1st change filename extension from *.cpp to *.h

find -P . -mindepth 1 | grep "[a-zA-Z0-9].cpp" > tmp1.file

while IFS= read -r line; do

echo "Line cpp: $line"

  if [[ -f $line ]]; then
    #modifying files
 
    fdir="$(dirname "${line}")"
    echo "Relative dir:$fdir"
    fname="$(basename "${line}")"
    echo "Relative Fname:$fname"    
    from_path=$line
    echo "From path:$from_path"
    echo ${fname} > tmp2.file
    pre_fname=$(cat tmp2.file | cut -d. -f1)
    pos_fname="h"
    to_path= "$fdir/${pre_fname}.${pos_fname}"
    echo "To path: $to_path"
   
    #move file
     mv $from_path $to_path
     echo "Moving files from $from_path  to $to_path "
  fi


done < tmp1.file


cd $cur_path
#2nd refactoring: main()-> exec(posfix)()
find -P . -mindepth 2 | grep "[a-zA-Z0-9].h" > tmp.file

cur_line_len=0
to_path_len=0
from_path=""
to_path=""
gen_node_id=0
func_cnter=0

while IFS= read -r line; do

    echo "full path: $line "
    
    cur_line_len=$(expr length $line)
    echo "Cur line len: $cur_line_len"
    fdir="$(dirname "${line}")"
    echo "Relative dir:$fdir"
    fname="$(basename "${line}")"
    echo "Relative Fname:$fname"    
    #getting node id
    echo ${line} > tmp0.line
    cat tmp0.line | cut -d. -f2 > tmp1.line
    cat tmp1.line | cut -d/ -f2 > tmp2.line
    cat tmp2.line | cut -d- -f1 > tmp3.line
    part_line1=$(tail -1 tmp3.line)  #in the form : 12-Recursive functions
    echo "Part line 1 $part_line1"
    cat tmp1.line | cut -d/ -f3 >tmp3.line  
    part_line2=$(tail -1 tmp3.line) #in the form 01 (first section)
    echo "Part line 2 $part_line2"
    cat tmp1.line | cut -d/ -f4 > tmp4.line
    part_line3=$(tail -1 tmp4.line)
    echo "Part line 3 $part_line3"
   cat tmp1.line | cut -d/ -f5 > tmp5.line
   part_line4=$(tail -1 tmp5.line)
   echo "Part line 4 $part_line4"
    
    
    let "gen_node_id=$part_line1$part_line2$part_line3$part_line4"
    echo "Gen node Id: $gen_node_id"
    
    rm -f tmp2.line tmp3.line tmp4.line tmp5.line
    
  #  if [[ $func_cnter==0 ]]; then
   #     rm -f $fcl_list
	#	touch $fcl_list
    #fi
    
    let "func_cnter=(func_cnter+1)"
    clist_line="Function$func_cnter Section="
    clist_tmp=""
    #building index and functcodelist.txt file
    echo ${line} > tmp0.line
    cat tmp0.line | tr "./" "\0" > tmp1.line
    cat tmp1.line | cut -d/ -f1 > tmp11.line # in the form "10-Arrays"
    clist_tmp=$(tail -1 tmp11.line)
    echo "Code list temp:$clist_tmp"
    clist_line="$clist_line$clist_tmp#Code=$gen_node_id" # "Function5 Section=10-Arrays#Code=10011"  that indicates:section10 chapter 01 example 1
	echo "Function code list line:$clist_line"
    echo $clist_line >> $fcl_list
    cat tmp1.line | tr "/" "\0" > tmp2.line
    cat tmp2.line | tr "-" "\0" > tmp3.line
    cat tmp3.line | cut -d. -f1 > tmp4.line
    rep_infix=$(tail -1 tmp4.line)
    echo "Rep infix:$rep_infix"
    rep_infix_len=$(expr length $rep_infix)
    echo "Rep infix len:$rep_infix_len"
    rep="$rep_prefix1$rep_prefix2$rep_infix$rep_posfix"
    
    rm -f tmp11.line tmp4.line
    
    #creating new  paths for the new files
    from_path="$fdir/$fname"
    echo "From path: $from_path"
    echo ${fname} > tmp2.file
    pre_fname=$(cat tmp2.file | cut -d. -f1)
    echo "Pre fname:$pre_fname"
    pos_fname=$(cat tmp2.file | cut -d. -f2)
     echo "Post fname: $pos_fname"

#    touch $fdir/$pre_name$rep_infix.$pos_fname 
   # touch $fdir/$rep_infix.$pos_fname 

    #echo "To path: $to_path"
    #touch $to_path
#    chmod 775 $fdir/$pre_name$rep_infix.$pos_fname
    #chmod 775 $fdir/$rep_infix.$pos_fname
   
    #to_path_len=$(expr length $to_path)
    #echo "To path len: $to_path_len"   
       
    if [[ -f $from_path ]]; then
      if [[ $rep_infix_len > 0 ]]; then
       #modifying files
       sed -i "s/$to_rep/$rep/" $from_path
       #adding leaf nodes to $
       if [[ $n_counter == 0 ]]; then
         rm -f $to_generate
	 touch $to_generate
	 #we create file from template
         cat $templateFile > $to_generate
       fi
       
       let "n_counter=(n_counter + 1)" 

       echo "n_counter = $n_counter"
       
       node_key="\"$rep_infix\""
       node_text=" \" $rep_infix - Node function $gen_node_id \" "
       node_func="$rep_prefix2$rep_infix"

       #auto generated code
       n_line1=" Node* node$gen_node_id = new Node($gen_node_id,$node_key,$node_text);"
       n_line2=" node$gen_node_id->setFunc($node_func); "
       # nodes is the vector container
       n_line3=" nodes.emplace($gen_node_id,node$gen_node_id); "       
       echo $n_line1 >> $to_generate
       echo $n_line2 >> $to_generate
       echo $n_line3 >> $to_generate
       #adding dependency containing file .h to appheaders.h
       echo "#include \"$from_path\"" >> $m_include
          
    
     fi
   fi




done < tmp.file

echo " return nodes; " >> $to_generate
echo " } " >> $to_generate
#adding app includes to include_util 
#echo $to_generate   $m_include


rm -f tmp.file
rm -f tmp.index
rm -f tmp0.line
rm -f tmp1.line    
rm -f tmp2.line
rm -f tmp3.line
rm -f tmp1.file
rm -f tmp2.file

