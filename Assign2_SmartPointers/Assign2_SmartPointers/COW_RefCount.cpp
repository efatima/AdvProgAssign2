//COW with Reference Counting
//.cpp file

#include "COW_RefCount.h"
#include <iostream>
using namespace std;

//default constructor of String class
String::String()
{
	cout << "String class Default Constructor..." << endl;
	this->_length = 0;
	this->_refcount = 1;
	this->_strbuf = 0;
}


String* COW_RefCount::get_str() {
	return _str;
}


//default constructor that sets the string buffer to NULL
COW_RefCount::COW_RefCount() 
{
	cout << "COW_RefCount class default Constructor..." << endl;
	this->_str = NULL; 

}

// destructor 
COW_RefCount::~COW_RefCount()
{
	cout << "Destructor..." << endl;

	if (this->_str->_refcount == 1) //if one pointer is pointing to the object being deleted
	{ //delete the object
		delete[] _str->_strbuf;
		delete _str;
	}
	else//if more than one references are pointing to the object being deleted
	{
		this->_str->_refcount--; //simply decrement the reference count
	}
}



COW_RefCount::COW_RefCount(const COW_RefCount& stringObjectToCopy){
	cout << "COW_RefCount Contructor with 1 parameter..." << endl;
	this->_str = stringObjectToCopy._str; //copies the address -- the new pointer of COW_RefCount type points to same location as stringObjectToCopy
	this->_str->_refcount++; //increases ref count -- since both pointers share the same _str, both refCounts will appear as incremented but they'll technically be the same
}

//in this function we copy the whole data passed and save it into a new String object and fill it's parameters
COW_RefCount::COW_RefCount(char* newString ,int length)
{
	cout << "COW_RefCount Contructor with 2 parameters..." << endl;
	_str = new String;
	_str->_strbuf= new char[length];
	_str->_length= length;
	
	int count = 0;
	while(count < length) 
	{	
		_str->_strbuf[count] = newString[count];
		 count++;
	}

}


void COW_RefCount::append(char newChar)
{
	//cout << "append" << endl;
	//cout << newChar << endl;

	if (this->_str->_refcount == 1)
	{
		//cout <<"if: refcount:1" << endl;
		char* newstr = this->_str->_strbuf;
		this->_str->_strbuf = new char[++this->_str->_length];//increase length to cater for new char and then create new buffer
		int count = 0;
		while (count < (this->_str->_length)) {
			this->_str->_strbuf[count] = newstr[count];
			count++;
		}
		this->_str->_strbuf[this->_str->_length - 1] = newChar;
		delete[] newstr;
	}
	else if (this->_str->_refcount>1)
	{
		//cout << "else if"<< endl;
		String* _newstr = new String;
		_newstr->_strbuf = new char[this->_str->_length + 1];//_str->length (to accomodate original string length) and +1 to accommodate new char 
		_newstr->_length = this->_str->_length + 1;

		int count = 0;
		while (count < (this->_str->_length)) {
			//cout << this->_str->_strbuf[count] << endl;
			_newstr->_strbuf[count] = this->_str->_strbuf[count];
			//cout << _newstr->_strbuf[count] << endl;
			count++;
		}

		_newstr->_strbuf[count] = newChar; //value at last index will be the new char that is being appended
		this->_str->_refcount--;
		//cout << _newstr->_strbuf[count] << endl;
		_str = _newstr;
		//cout << "done" << endl;
	}


}

char COW_RefCount::charAt (int bufferindex) const
{
	//cout << "charAt..." << endl;
		return _str->_strbuf[bufferindex];
}


void COW_RefCount::reserve(int length)
{
	cout << "reserve" << endl;
	this->_str= new String;
	this->_str->_strbuf= new char[length];
}


//returns length of String buffer
int COW_RefCount::len() const {
	cout << "length..." << endl;
	return _str->_length;
}





