//COW with Ref Linking -- String
//.cpp file

#include "COW_RefLinking.h"
#include <iostream>
using namespace std;

String_COW_RefLinking::String_COW_RefLinking() //default constructor
{
	cout << "\tString_COW_RefLinking Default Constructor..." << endl;
	this->_str = new Buffer_COW_RefLinking();
}

// destructor
String_COW_RefLinking::~String_COW_RefLinking()
{
	cout << "\tString_COW_RefLinking Destructor..." << endl;
	delete this->_str;
}

String_COW_RefLinking::String_COW_RefLinking(String_COW_RefLinking& newStringObject) {//creates new buffer class oject and passes buffer type parameter after extracting it from the input
	cout << "\tString_COW_RefLinking Contructor with 1 param..." << endl;
	this->_str = new Buffer_COW_RefLinking(*newStringObject._str);
}


String_COW_RefLinking::String_COW_RefLinking(char* newString, int length)//creates new buffer oject and passes parameters provided
{
	this->_str = new Buffer_COW_RefLinking(newString, length);
}


void String_COW_RefLinking::append(char newChar) //calls append of Buffer class
{
	this->_str->append(newChar);
}


int String_COW_RefLinking::len() const {
	//cout << "length..." << endl;
	return this->_str->len();
}


//returns char placed at the provided index
char String_COW_RefLinking::charAt(int bufferindex) const
{
	//cout << "charAt" << endl;
	if (bufferindex < this->_str->len()) {
		return this->_str->charAt(bufferindex);
	}
	else {
		cout << "\n\tINVALID INDEX PROVIDED!\n";
		return ' ';
	}
}

