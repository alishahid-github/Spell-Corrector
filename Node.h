//A node class which creates the nodes for the Spell Corrector

#include<iostream>
using namespace std;
#ifndef NODE
#define NODE
class Node
{
private:
	int data;
	string word;
	Node* Left;
	Node* Right;
	Node* Parent;
public:
	Node();
	Node(int d,string w);			
	void set_data(int d);
	void set_word(string w);
	void set_Left(Node* l);		
	void set_Right(Node* r);
	void set_Parent(Node* p);
	Node* get_Left();
	Node* get_Right();
	Node* get_Parent();
	int get_data();
	string get_word();
};

#endif


