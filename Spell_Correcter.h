#include<iostream>
#include"BST.h"
#ifndef SPELL
#define SPELL
using namespace std;

class Spell_Correcter
{
private:
	BST tree;
public:
	void load_dict();
	string spell_checker(string address);
	bool spell_correcor(string address);
	string preprocessing(string s);
	void get_suggestion(Node* t, string word);

};

#endif
