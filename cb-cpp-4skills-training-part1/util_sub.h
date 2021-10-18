#pragma once

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <functional>

using namespace std;
//

class Node {
public:
    Node(int id, string key, string text){
     _id = id; _key = key; _text = text;
    }
    void setFunc(function<int()> f) {
	       this->pF = f;
	}
    virtual ~Node() {}
    int getId() { return _id; }
    string getKey () { return _key; }
    string getText( ) { return _text; }
    const static int ROOT_ID;
    const static int LEAF_ID;
   function<int()> pF;
private:
    int _id;
    string _text;
    string _key;
	

};

const static int Node::ROOT_ID = 0;
const static int Node::LEAF_ID = 11111111;

void generateLeafNodes(map<int,Node*> &nodes){
//  create new node
//  emplace into map
Node* node100301 = new Node(100301,"10marrays0301h", " 10marrays0301h - Node function 100301 " );
node100301->setFunc(exec10marrays0301h);
nodes.emplace(100301,node100301);
Node* node100502 = new Node(100502,"10marrays0501_shorterh", " 10marrays0501_shorterh - Node function 100502 " );
node100502->setFunc(exec10marrays0501_shorterh);
nodes.emplace(100301,node100301);
Node* node100501 = new Node(100501,"10marrays0501h", " 10marrays0501h - Node function 100501 " );
node100501->setFunc(exec10marrays0501h);
nodes.emplace(100501,node100501);
Node* node100203 = new Node(100203,"10marrays0203h", " 10marrays0203h - Node function 100203 " );
node100203->setFunc(exec10marrays0203h);
nodes.emplace(100203,node100203);
Node* node100202 = new Node(100202,"10marrays0202h", " 10marrays0202h - Node function 100202 " );
node100202->setFunc(exec10marrays0202h);
nodes.emplace(100202,node100202);
Node* node100201 = new Node(100201,"10marrays0201h", " 10marrays0201h - Node function 100201 " );
node100201->setFunc(exec10marrays0201h);
nodes.emplace(100201,node100201);
Node* node100403 = new Node(100403,"10marrays0403h", " 10marrays0403h - Node function 100403 " );
node100403->setFunc(exec10marrays0403h);
nodes.emplace(100403,node100403);
Node* node100402 = new Node(100402,"10marrays0402h", " 10marrays0402h - Node function 100402 " );
node100402->setFunc(exec10marrays0402h);
nodes.emplace(100402,node100402);
Node* node100401 = new Node(100401,"10marrays0401h", " 10marrays0401h - Node function 100401 " );
node100401->setFunc(exec10marrays0401h);
nodes.emplace(100401,node100401);
Node* node100103 = new Node(100103,"10marrays0103h", " 10marrays0103h - Node function 100103 " );
node100103->setFunc(exec10marrays0103h);
nodes.emplace(100103,node100103);
Node* node100102 = new Node(100102,"10marrays0102h", " 10marrays0102h - Node function 100102 " );
node100102->setFunc(exec10marrays0102h);
nodes.emplace(100102,node100102);
Node* node100101 = new Node(100101,"10marrays0101h", " 10marrays0101h - Node function 100101 " );
node100101->setFunc(exec10marrays0101h);
nodes.emplace(100101,node100101);
Node* node12031 = new Node(12031,"12recfunc031h", " 12recfunc031h - Node function 12031 " );
node12031->setFunc(exec12recfunc031h);
nodes.emplace(12031,node12031);
Node* node12051 = new Node(12051,"12recfunc051h", " 12recfunc051h - Node function 12051 " );
node12051->setFunc(exec12recfunc051h);
nodes.emplace(12051,node12051);
Node* node12021 = new Node(12021,"12recfunc021h", " 12recfunc021h - Node function 12021 " );
node12021->setFunc(exec12recfunc021h);
nodes.emplace(12021,node12021);
Node* node12042 = new Node(12042,"12recfunc042h", " 12recfunc042h - Node function 12042 " );
node12042->setFunc(exec12recfunc042h);
nodes.emplace(12042,node12042);
Node* node12012 = new Node(12012,"12recfunc012h", " 12recfunc012h - Node function 12012 " );
node12012->setFunc(exec12recfunc012h);
nodes.emplace(12012,node12012);
Node* node12011 = new Node(12011,"12recfunc011h", " 12recfunc011h - Node function 12011 " );
node12011->setFunc(exec12recfunc011h);
nodes.emplace(12011,node12011);
Node* node13011 = new Node(13011,"13project101hospital_v1h", " 13project101hospital_v1h - Node function 13011 " );
node13011->setFunc(exec13project101hospital_v1h);
nodes.emplace(13011,node13011);
 return nodes;
 }
