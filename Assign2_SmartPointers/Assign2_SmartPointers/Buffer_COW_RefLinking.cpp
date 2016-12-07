//COW with Reference Linking -- Buffer
//.cpp file

#include "COW_RefLinking.h"
#include <iostream>
using namespace std;


//default constructor of Buffer Class
Buffer_COW_RefLinking::Buffer_COW_RefLinking()
{
	cout << "\tBuffer_COW_RefLinking class default Constructor..." << endl;
	this->_length = 0;
	this->_strbuf = NULL;
	this->_prev = NULL;
	this->_next = NULL;
}

// destructor of buffer class
Buffer_COW_RefLinking::~Buffer_COW_RefLinking()
{
	cout << "\tDestructor..." << endl;
	if ((this->_prev == NULL && this->_next==NULL) || (this->_prev == this->_next)) 
	{ // simply delete the object
		delete[] _strbuf;
		_strbuf = NULL;
		delete this;
	}
}



Buffer_COW_RefLinking::Buffer_COW_RefLinking(Buffer_COW_RefLinking& stringObjectToCopy){
	cout << "\tCOW_RefLinking Contructor with 1 parameter..." << endl;
	//cout << *stringObjectToCopy._strbuf << endl;
	this->_strbuf = stringObjectToCopy._strbuf; //copies the address -- the new pointer of COW_RefCount type points to same location as stringObjectToCopy
	this->_length = stringObjectToCopy.len();

	if (stringObjectToCopy._prev == stringObjectToCopy._next)
	{
		//cout << "1" << endl;
		this->_prev = &stringObjectToCopy;
		//cout << _prev << endl;
		this->_next = NULL;
		this->_prev->_next = this;
		//cout << stringObjectToCopy._next << endl;
		stringObjectToCopy._next = this;

	}
	else if (stringObjectToCopy._next == NULL) {
		//cout << "2" << endl;
		this->_prev = &stringObjectToCopy;
		this->_prev->_next = this;
		this->_next = NULL;

		stringObjectToCopy._next = this;
		//cout << stringObjectToCopy._next << endl;




	}
	else if (stringObjectToCopy._next != NULL) {
		//cout << "3" << endl;
		Buffer_COW_RefLinking* tmp = NULL;
		for (tmp = stringObjectToCopy._next; tmp->_next != NULL; tmp = tmp->_next) {
			//do nothing
		}
		//	//exits loop after temp->next == null
		this->_prev = tmp;
		this->_prev->_next = this;
		this->_next = NULL;
	}

	//cout <<"here"<< endl;
	//this->printLinkedList();
}


//in this function we copy the whole data passed and save it into a new String object and fill it's parameters
Buffer_COW_RefLinking::Buffer_COW_RefLinking(char* newString ,int length)
{
	cout << "\tCOW_RefLinking Contructor with 2 parameters..." << endl;
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
	this->_prev = NULL;
	this->_next = NULL;

}


void Buffer_COW_RefLinking::append(char newChar)
{
	cout << "\tAppending..." << endl;
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

	 if (this->_prev == NULL && this->_next != NULL)//case 1: object being appended is at the head
	{
		 this->_next->_prev = NULL;
		 this->_next = NULL;
	}
	 else if (this->_prev != NULL && this->_next == NULL) {//case 2: object being appended is at the tail of the doubly linked list
		 this->_prev->_next = NULL;
		 this->_prev = NULL;
	 }
	 else if (this->_prev != NULL && this->_next != NULL) {//case 3: object being appended is not at the edge of the doubly linked list
		 this->_prev->_next = this->_next;
		 this->_next->_prev = this->_prev;
		 this->_prev = NULL;
		 this->_next = NULL;
	 }

	 //this->printLinkedList();
}

char Buffer_COW_RefLinking::charAt (int bufferindex) const
{
	//cout << "charAt..." << endl;
		return this->_strbuf[bufferindex];
}

//reserve
void Buffer_COW_RefLinking::reserve(int length)
{
	//cout << "reserve" << endl;
	this->_strbuf= new char[length];
}


//returns length of String buffer
int Buffer_COW_RefLinking::len() const {
	//cout << "length..." << endl;
	return this->_length;
}


void Buffer_COW_RefLinking::printLinkedList() {
	/*cout << "in print" << endl;
	if (this == NULL)
	{
		cout << "List empty,nothing to display" << endl;
		return;
	}
	Buffer_COW_RefLinking* q = this;
	cout << "The Doubly Link List is :" << endl;
	while (q != NULL)
	{
		cout <<q << endl;
		cout << q->_next << " <---> ";
		cout << q->_prev << " <---> ";
		q = q->_next;
	}
	cout << "NULL\n" << endl;*/
	
}



