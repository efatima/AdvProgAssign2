//Copied Pointers
//.cpp file

#include "Copied.h"
#include <iostream>
using namespace std;


String_Copied::String_Copied() //default constructor
{
	cout << "String_Copied Default Constructor..." << endl;
	this->_str = new Buffer_Copied();
}

// destructor
String_Copied::~String_Copied()
{
	cout << "String_copied Destructor..." << endl;
	delete this->_str;
}

String_Copied::String_Copied(const String_Copied& newStringObject) {//creates new buffer class oject and passes buffer type parameter after extracting it from the input
	cout << "String_Copied Contructor with 1 param..." << endl;
	this->_str = new Buffer_Copied(*newStringObject._str);
}


String_Copied::String_Copied(char* newString, int length)//creates new buffer oject and passes parameters provided
{
	this->_str = new Buffer_Copied(newString, length);
}


void String_Copied::append(char newChar) //calls append of Buffer class
{
	this->_str->append(newChar);	
}


int String_Copied::len() const {
	//cout << "length..." << endl;
	return this->_str->len();
}


//returns char placed at the provided index
char String_Copied::charAt(int bufferindex) const
{
	//cout << "charAt" << endl;
	if (bufferindex < this->_str->len()) {
		return this->_str->charAt(bufferindex);
	}
	else {
		cout << "\nINVALID INDEX PROVIDED!\n";
		return ' ';
	}
}

