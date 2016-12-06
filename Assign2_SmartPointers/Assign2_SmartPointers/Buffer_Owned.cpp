//Owned Pointer Buffer file

#include "Owned.h"
#include <iostream>
using namespace std;


Buffer_Owned::Buffer_Owned() //default constructor
{
	cout << "\tBuffer_Copied Default Constructor..." << endl;
	_length = 0;
	_strbuf = NULL;
}

// destructor
Buffer_Owned::~Buffer_Owned()
{
	cout << "\tBuffer_Copied Destructor..." << endl;
	delete[] _strbuf;
	_strbuf = NULL;
}

Buffer_Owned::Buffer_Owned(const Buffer_Owned& newObject) {
	cout << "\tBuffer_copied Contructor with 1 param..." << endl;
	_length = newObject.len();
	//_strbuf = new char[_length];
	this->reserve(_length);
	int count = 0;
	while (count < _length) {
		_strbuf[count] = newObject.charAt(count);
		count++;
	}
}


//creates a new buffer and copies the data into the new buffer
Buffer_Owned::Buffer_Owned(char* newString, int length)
{
	cout << "\tBuffer_Copied Contructor with 2 parameters..." << endl;
	//_strbuf = new char[length];
	this->reserve(length);
	_length = length;
	int count = 0;
	while (count < length) {
		_strbuf[count] = newString[count];
		count++;
	}

}

void Buffer_Owned::append(char newChar)
{
	cout << "\tAppending..." << endl;
	char* newstr = this->_strbuf;
	this->reserve(++_length);//increase length to cater for new char and then create new buffer using reserve
	int count = 0;
	while (count < this->_length - 1) {
		_strbuf[count] = newstr[count];
		count++;
	}
	_strbuf[_length - 1] = newChar; // the appended item will be at the last index position i.e length-1 since indices start from 0
	delete[] newstr;
	newstr = NULL;

}


int Buffer_Owned::len() const {
	//cout << "length..." << endl;
	return this->_length;
}


//returns char placed at the provided index
char Buffer_Owned::charAt(int bufferindex) const
{
	//cout << "charAt" << endl;
	return _strbuf[bufferindex];
}


void Buffer_Owned::reserve(int length)
{
	//cout << "reserve" << endl;
	this->_strbuf = new char[length];
}