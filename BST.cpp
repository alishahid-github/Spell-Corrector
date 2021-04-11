//.cpp file to implement the Binary Search Tree

#include<iostream>
#include"BST.h"
using namespace std;

BST::BST()
{
	Root = NULL;
}

Node* BST::get_root()
{
	return Root; 
}

void  BST::set_root(Node* r)
{ 
	Root = r; 
}

void BST::insert(string w) 
{
	int data = 0;
	for (unsigned int i = 0; i < w.length(); i++)
		data = data + w[i];

	Node * new_element = new Node(data,w);
	if (Root == NULL)
	{
		new_element->set_Parent(NULL);
		Root = new_element;	
	}
		
	else
	{
		Node* previous = Root; 
		Node* current  = Root;
		while (current != NULL)
		{
			previous = current;
			if (data > current->get_data())
				current = current->get_Right();
			else
				current = current->get_Left();
		}
		if (data > previous->get_data())
		{
			new_element->set_Parent(previous);
			previous->set_Right(new_element);
		}
			
		else
		{
			new_element->set_Parent(previous);
			previous->set_Left(new_element);
		}
	}

}


Node* BST::search(string w)
{
	int d = 0;
	for (unsigned int i = 0; i < w.length(); i++)
		d = d + w[i];

	if (Root == NULL)
		return NULL;
	else if (Root->get_data() == d && Root->get_word()==w)
		return Root;
	else
	{
		Node* current = Root;
		while (current != NULL)
		{
			if (d > current->get_data())
				current = current->get_Right();
			else
				current = current->get_Left();
			if (current != NULL && current->get_word() == w && current->get_data() == d  )
				return current;

		}
		return NULL;
	}

}
