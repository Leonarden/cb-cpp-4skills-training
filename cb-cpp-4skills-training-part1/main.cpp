#include <iostream>
#include <exception>
#include <assert.h>
#include <map>
#include"util.h"

using namespace std;


int main()
{  int s = -1;

    try{

   map<int,Node*>  nodes = generateIndex();

    assert(nodes.size()>0);

    while(true){
        int v = SelectFromRange(10,200000);
        if(v==-1){
            cout << "Exiting application:" << endl;
            break;

        }
        try{

            Node* n = nodes.at(v);
             n->pF();

            

            s = 0;
        }catch( exception& ex){
            cout << " The function code you inserted doesn't exist" << endl;
        s = -1;
        }


    }




    }catch(const exception& e) {

        cout << " Exception occurred in main: " << e.what() << endl;
    }



    return s;
}
