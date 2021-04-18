#include<iostream>
#include<fstream>
#include<string>
#include "Spell_Correcter.h"
using namespace std;


string suggestion[100];
int c = 0;  // counter for the suggestion variable

// function to calculate Hamming distance 
int hammingDist(string str1, string str2)
{
	int i = 0, count = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			count++;
		
		i++;
	}
	return count;
}

void Spell_Correcter ::get_suggestion(Node* t, string word)
{

	if (t != NULL)
	{
		get_suggestion(t->get_Left(),word);

		string w = t->get_word(); 
		int r = hammingDist(word, w);
		if ( r< 2 )
		{
			if (word.length() > 2)
			{
				if (w[0] == word[0] && w[1] == word[1] && w.length() > word.length() - 2)
					suggestion[c++] = w;
				if (c > 100)
					c = 50;
			}
			else
			{
				if (w[0] == word[0] && w.length() > word.length() - 2)
					suggestion[c++] = w;
				if (c > 100)
					c = 50;
			}
		}
		
		get_suggestion(t->get_Right(),word);
	}
}

void Spell_Correcter::load_dict()
{
	ifstream file;
	file.open("../Manual & Files/dict.txt");
	if (file.is_open())
	{
		string word=" ";
		while (!(file.eof()))
		{
			file>>word;
			tree.insert(word);
		}
	}
	else
		cout << "Unable to fetch Doctionary";
}

string Spell_Correcter::spell_checker(string address)
{
	bool error = false; 
	string word; 
	int error_count = 0;
	ifstream f;
	f.open(address);
	if (f.is_open())
	{
		Node* res;  int count = 0;
		while (!(f.eof()))
		{
			f >> word;
		again:
			word = word;
			res = tree.search(word);
			if (res == NULL)
			{
				if (count >=0 && count<=2)
				{
					word = preprocessing(word); 
					count ++;
					goto again;
				}
				else
				{
					error = true;
					count = 0;
					error_count++;
				}
					
			}
		}

		if (error == true)
			return "There are " + to_string(error_count) + " errors in the file";
		else
			return "There is no error in the file";
	}
	else
		return + "Unable to fetch file";
}

bool Spell_Correcter::spell_correcor(string address)
{
	string word;
	bool new_line = false;
	ifstream f;
	f.open(address);
	if (f.is_open())
	{
		Node* res;  
		int count = 0; 
		ofstream corr_file("../Manual & Files/correct.txt");
		while (!(f.eof()))
		{
			f >> word;
			if (word[word.length() - 1] == '.' || word[word.length() - 1] == ',')
			{
				if (word[word.length() - 1] == '.')
					new_line = true;
				word.pop_back();
				
			}
		again:
			word = word;
			res = tree.search(word);
			if (res == NULL)
			{
				if (count >= 0 && count <= 2)
				{
					word = preprocessing(word);
					count++;
					goto again;
				}
				else
				{
					cout << "\nThe following word is spelled incorrected \''" << word <<"\''"<< endl;
					cout << "There are some suggestions:" << endl;
					c = 0;				//suggestion counter
					get_suggestion(res = tree.get_root(), word);
					for (int i = 0; i < 5; i++)
						cout << suggestion[i]<<endl;
					cout << "Enter the correct word\n"; 
					string opt;
					cin >> opt;
					word = opt;
				}
				
			}
			count = 0;
			if (new_line != true)
				corr_file << word << " ";
			else
			{
				new_line = false;
				corr_file << word << ".\n";
			}
		}
		f.close();
		corr_file.close();
		return true;
	}
	else
		return false;
}

string Spell_Correcter::preprocessing(string word)
{
	bool upper_case = false;
	for (unsigned int i = 0; i < word.length(); i++)
	{
		if (word[i] >= 'A' && word[i] <= 'Z')
		{
			word[i] = word[i] + 32;
			upper_case = true;
		}
	}
	if (upper_case == true)
		return word;
	if (word.length() >= 3)
	{
		int len = word.length();
		string temp = word.substr(len - 3, 3);
		if (temp == "ing")
		{
			word.resize(len - 3);
			Node* res = tree.search(word);
			if (res == NULL)
			{
				word.append("e");
				return word;
			}
			else
				return word;
		}
		else if (temp == "ies")
		{
			word.resize(len - 3);
			word.append("y");
			return word;
		}
		else
		{
			temp = word.substr(len - 2, 2);
			if (temp == "es"||temp=="ly" || temp=="ed")
			{
				word.resize(len - 2);
				Node* res = tree.search(word);
				if (res == NULL)
				{
					if (temp == "es" || temp == "ed")
						word.append("e");
					return word;
				}
				else
					return word;
			}
			else
			{
				char temp = word[len-1];
				if (temp == 's')
					word.pop_back();
				return word;
			}
		}
	}
	return word;
}

