//Copied Pointers
//.cpp file

#include "Copied_Buff.h"
#include <iostream>
using namespace std;


Copied_Buff::Copied_Buff() //default constructor
{
	cout << "\tDefault Constructor..." << endl;
	_length = 0;
	_strbuf = NULL;	
}

// destructor
Copied_Buff::~Copied_Buff()
{
	cout << "\tDestructor..." << endl;
	delete[] _strbuf;
}

Copied_Buff::Copied_Buff(const Copied_Buff& newObject) {
	cout << "\tContructor with 1 param..." << endl;
	_length = newObject.len();
	_strbuf = new char[_length];
	int count = 0;
	while (count < _length) {
		_strbuf[count] = newObject.charAt(count);
		count++;
	}
}


//creates a new buffer and copies the data into the new buffer
Copied_Buff::Copied_Buff(char* newString, int length)
{
	cout << "\tContructor with 2 parameters..." << endl;
	_strbuf = new char[length];
	_length = length;
	int count = 0;
	while (count < length) {
		_strbuf[count] = newString[count];
		count++;
	}

}

void Copied_Buff::append(char newChar)
{
	cout << "\tAppending..." << endl;
	char* newstr = this->_strbuf;
	this->_strbuf = new char[++_length];//increase length to cater for new char and then create new buffer
	int count = 0;
	while (count < this->_length - 1) {
		_strbuf[count] = newstr[count];
		count++;
	}
	_strbuf[_length - 1] = newChar; // the appended item will be at the last index position i.e length-1 since indices start from 0
	delete[] newstr;

}


int Copied_Buff::len() const {
	//cout << "length..." << endl;
	return _length;
}


//returns char placed at the provided index
char Copied_Buff::charAt(int bufferindex) const
{
	//cout << "charAt" << endl;
	return _strbuf[bufferindex];
}


void Copied_Buff::reserve(int length)
{
	//cout << "reserve" << endl;
	_strbuf = new char[length];
}
