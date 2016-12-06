//Owned Pointers -- String 
//.cpp file

#include "Owned.h"
#include <iostream>
using namespace std;


String_Owned::String_Owned() //default constructor
{
	cout << "\tString_Copied Default Constructor..." << endl;
	this->_str = new Buffer_Owned();
}

// destructor
String_Owned::~String_Owned()
{
	cout << "\tString_copied Destructor..." << endl;
	delete this->_str;
}

String_Owned::String_Owned(const String_Owned& newStringObject) {//creates new buffer class oject and passes buffer type parameter after extracting it from the input
	cout << "\tString_Copied Contructor with 1 param..." << endl;
	this->_str = new Buffer_Owned(*newStringObject._str);
	delete newStringObject._str;
}


String_Owned::String_Owned(char* newString, int length)//creates new buffer oject and passes parameters provided
{
	this->_str = new Buffer_Owned(newString, length);
}


void String_Owned::append(char newChar) //calls append of Buffer class
{
	this->_str->append(newChar);
}


int String_Owned::len() const {
	//cout << "length..." << endl;
	return this->_str->len();
}


//returns char placed at the provided index
char String_Owned::charAt(int bufferindex) const
{
	//cout << "charAt" << endl;
	if (this->_str == NULL) {
		cout << "\n\tInvalid access!\t";
	}
	else if (bufferindex < this->_str->len()) {
		return this->_str->charAt(bufferindex);
	}
	else {
		cout << "\n\tINVALID INDEX PROVIDED!\n";
	}
	return ' ';
}

