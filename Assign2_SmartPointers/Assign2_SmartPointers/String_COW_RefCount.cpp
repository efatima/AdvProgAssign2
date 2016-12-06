//COW with Ref Count -- String
//.cpp file

#include "COW_refCount.h"
#include <iostream>
using namespace std;


String_COW_RefCount::String_COW_RefCount() //default constructor
{
	cout << "\tString_COW_RefCount Default Constructor..." << endl;
	this->_str = new Buffer_COW_RefCount();
}

// destructor
String_COW_RefCount::~String_COW_RefCount()
{
	cout << "\tString_COW_RefCount Destructor..." << endl;
	delete this->_str;
}

String_COW_RefCount::String_COW_RefCount(const String_COW_RefCount& newStringObject) {//creates new buffer class oject and passes buffer type parameter after extracting it from the input
	cout << "\tString_COW_RefCount Contructor with 1 param..." << endl;
	this->_str = newStringObject._str;
	++this->_str->_refcount;
}


String_COW_RefCount::String_COW_RefCount(char* newString, int length)//creates new buffer oject and passes parameters provided
{
	this->_str = new Buffer_COW_RefCount(newString, length);
	this->_str->_refcount = 1;
}


void String_COW_RefCount::append(char newChar) //calls append of Buffer class
{
	this->_str->append(newChar);
}


int String_COW_RefCount::len() const {
	//cout << "length..." << endl;
	return this->_str->len();
}


//returns char placed at the provided index
char String_COW_RefCount::charAt(int bufferindex) const
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

int String_COW_RefCount::get_refCount() {
	return this->_str->get_refCount();
}

