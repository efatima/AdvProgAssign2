//COW with Reference Counting
//.cpp file

#include "COW_RefCount.h"
#include <iostream>
using namespace std;


//default constructor of Buffer Class
Buffer_COW_RefCount::Buffer_COW_RefCount()
{
	cout << "\tBuffer_COW_RefCount class default Constructor..." << endl;
	//this->_str = NULL; 
	this->_length = 0;
	this->_strbuf = NULL;
	this->_refcount = 1;
}

// destructor of buffer class
Buffer_COW_RefCount::~Buffer_COW_RefCount()
{
	cout << "\tDestructor..." << endl;
	if (this->_refcount == 1) //if one pointer is pointing to the object being deleted
	{ // simply delete the object
		delete[] _strbuf;
		_strbuf = NULL;
		delete this;
	}
	else//if more than one pointers are pointing to the object being deleted
	{
		this->_refcount--; //simply decrement the reference count and don't delete the object
	}
}



Buffer_COW_RefCount::Buffer_COW_RefCount(const Buffer_COW_RefCount& stringObjectToCopy){
	cout << "\tCOW_RefCount Contructor with 1 parameter..." << endl;
	this->_strbuf = stringObjectToCopy._strbuf; //copies the address -- the new pointer of COW_RefCount type points to same location as stringObjectToCopy
	this->_refcount++; //increases ref count -- since both pointers share the same _str, both refCounts will appear as incremented but they'll technically be the same
}

//in this function we copy the whole data passed and save it into a new String object and fill it's parameters
Buffer_COW_RefCount::Buffer_COW_RefCount(char* newString ,int length)
{
	cout << "\tCOW_RefCount Contructor with 2 parameters..." << endl;
	//this = new Buffer_COW_RefCount;
	this->_strbuf= new char[length];
	this->_length= length;
	
	int count = 0;
	while(count < length) 
	{	
		this->_strbuf[count] = newString[count];
		//cout << this->_strbuf[count] << endl;
		 count++;
	}

}


void Buffer_COW_RefCount::append(char newChar)
{
	//cout << "append" << endl;
	char* _newstr = new char[this->_length + 1];//_length (to accomodate original string length) and +1 to accommodate new char 
	int count = 0;
	while (count < (this->_length)) {
		//cout << this->_strbuf[count] << endl;
		_newstr[count] = this->_strbuf[count];
		//cout << _newstr[count] << endl;
		count++;
	}
	_newstr[count] = newChar; //value at last index will be the new char that is being appended
	this->_length = _length + 1;
	this->_strbuf = _newstr;

	 if (this->_refcount > 1)
	{
		this->_refcount--;
	}
}

char Buffer_COW_RefCount::charAt (int bufferindex) const
{
	//cout << "charAt..." << endl;
		return this->_strbuf[bufferindex];
}

//reserve
void Buffer_COW_RefCount::reserve(int length)
{
	cout << "reserve" << endl;
	this->_strbuf= new char[length];
}


//returns length of String buffer
int Buffer_COW_RefCount::len() const {
	//cout << "length..." << endl;
	return this->_length;
}

int Buffer_COW_RefCount::get_refCount() {
	return this->_refcount;
}





