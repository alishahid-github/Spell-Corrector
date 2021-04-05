//.cpp file of the Node class 

#include<iostream>
#include"BST.h"
using namespace std;


Node::Node()
{
	data = 0;
	word = "\0";
	Left = NULL;
	Right = NULL;
	Parent = NULL;
}

Node::Node(int d,string w)
{
	data = d;
	word = w;
	Left = NULL;
	Right = NULL;
	Parent = NULL;
}

void Node::set_data(int d) { 
	data = d;
}
void Node::set_word(string w)
{
	word = w;
}
void Node::set_Left(Node* l)
{
	Left = l;
}
void Node::set_Right(Node* r)
{
	Right = r;
}

void Node::set_Parent(Node* p)
{
	Parent = p;
}

int Node::get_data() 
{ 
	return data; 
}

string Node::get_word()
{
	return word;
}

Node* Node::get_Left()
{
	return Left;
}

Node* Node::get_Right()
{
	return Right;
}

Node* Node::get_Parent()
{
	return Parent;
}
