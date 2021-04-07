//Header file for the Linked List with Basic funtions

#include<iostream>
#include"Node.h"
#ifndef LIST
#define LIST
using namespace std;
class BST
{
private:
	 Node* Root;
public:
	BST();
	void insert(string w);		
	Node* search(string w);       
	Node* search_data(string w);
	void set_root(Node* h);
	Node* get_root();		
	int node_count = 0;
};

#endif
