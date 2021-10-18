#pragma once
#include "appheaders.h"
#include "util_sub.h"
#include <string>
#include <sstream>
#include <fstream>

using namespace std;


void printFunctionList() {
string helpfile="./funcodelist.txt";
fstream fs(helpfile);
string line;
ostringstream oss;
     while(std::getline(fs,line)){
		 oss << line << endl;
	 }
	 fs.close();

	 cout << oss.str();

}

int SelectFromRange(int begin, int end){

int r = 1000;
int i = 1;
do {
    cout << "\n Number of trials: " << i;
    cout << "Select a number between: "  << begin  << " and " << end << "( 99 to print the list of fucntions and -1 to exit)"<< endl;
    cin >> r;
    i++;
    if(r==99){
		printFunctionList();
		continue;
	}
    
}while( r!= -1 && (r<begin || r>end));

return r;

}


map<int,Node*> generateIndex(){

map<int,Node*> nodes;

Node root(Node::ROOT_ID,"0","0-Root");
Node node10(10,"10","10-Multidimensional Arrays");
Node node12(12,"12","12-Recursive Functions");
Node node13(13,"13","13-Project 1");
Node node14(14,"14","14-Structures");
//
Node node1001(1001,"1001","");
Node node1002(1002,"1002","");
Node node1003(1003,"1003","03-Position neighbours");
//
Node node1201(121,"1201","");
Node node1202(122,"1202","");
Node node1203(123,"1203","");
Node node1204(124,"1204","");
Node node1205(125,"1205","");


 generateLeafNodes(nodes);

return nodes;

}

