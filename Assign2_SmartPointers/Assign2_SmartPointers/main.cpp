//Advanced Programing
//Assignment 3
//Smart Pointers
/***************************
//Eman Fatima
//BSCS 4C
//34648
***************************/
#include<iostream>
#include"COW_RefCount.h"
#include"Copied.h"
#include"Owned.h"



using namespace std;


int main() {

	cout << "\n\tWelcome to Smart Pointers Library for Strings!" << endl;
	cout << "\n\tFollowing are some test cases on this implementation" << endl;
	char* myString = "Eman";

	cout << "\n\n\t%%%%%%%%%%%%%%%  Copied Pointers %%%%%%%%%%%%%%%%%%%%" << endl;


	String_Copied* copied1 = new String_Copied("Eman", 4);
	String_Copied* copied2 = new String_Copied(*copied1); //copying first pointer to second -- deep copying

    //All indices start from 0
	cout << "\tLength of copied1 Buffer: " << copied1->len() << endl;
	cout << "\tLength of copied2 Buffer: " << copied2->len() << endl;

	cout << "\tChar at copied1[3]: " << copied1->charAt(3) << endl;
	cout << "\tChar at copied2[3]: " << copied2->charAt(3) << endl;

	copied1->append('F');
	copied1->append('a');

	cout << "\tLength of copied1 after appending 2 chars to copied1:" << copied1->len() << endl;
	cout << "\tLength of copied2 after appending 2 chars to copied1: " << copied2->len() << endl;

	cout << "\tChar at copied1[4] after appending 2 chars to copied1: " << copied1->charAt(4) << endl;// will be the new char 'F' appended
	cout << "\tChar at copied2[4] after appending 2 chars to copied1: " << copied2->charAt(4) << endl;//will be garbage since length-1 is the last index location

	cout << "\n\n\t%%%%%%%%%%%%%%%  Owned Pointers   %%%%%%%%%%%%%%%%%%%%" << endl;

	String_Owned* owned1 = new String_Owned("Eman", 4);
	cout << "\tChar at copied1[3]: " << owned1->charAt(3) << endl;
	String_Owned* owned2 = new String_Owned(*owned1);
	cout << "\tChar at copied2[3]: " << owned2->charAt(3) << endl;
	owned2->append('F');
	cout << "\tChar at copied2[4]: " << owned2->charAt(4) << endl;

	cout <<"\n\n\t%%%%%%%%%%%%%%%  Reference Counting   %%%%%%%%%%%%%%%%%%%%"<< endl;

	COW_RefCount* string1 = new COW_RefCount(myString, strlen(myString));//using 2 param constructor
	
	//COW_RefCount* string2 = new COW_RefCount(); //default constructor
    COW_RefCount* string2 = new COW_RefCount(*string1); //using 1 param constructor

	cout << "\tChar at string1[0]: " << string1->charAt(0) << endl;
	cout << "\tChar at string1[1]: " << string1->charAt(1) << endl;
	cout << "\tChar at string1[2]: " << string1->charAt(2) << endl;
	cout << "\tChar at string1[3]: " << string1->charAt(3) << endl;


	cout << "\tReference count of String1 BEFORE modifying String2: " << string1->get_str()->_refcount << endl;
	cout << "\tReference count of String2: " << string2->get_str()->_refcount << endl;

	string2->append('F');
	string2->append('a');
	string2->append('t');
	string2->append('i');
	string2->append('m');
	string2->append('a');
	
	cout << "\tReference count of String1 AFTER modifying String2: " << string1->get_str()->_refcount << endl;
	cout << "\tReference count of String2: " << string2->get_str()->_refcount << endl;
	cout << "\tChar at string2[0]: " << string2->charAt(0) << endl;
	cout << "\tChar at string2[1]: " << string2->charAt(1) << endl;
	cout << "\tChar at string2[2]: " << string2->charAt(2) << endl;
	cout << "\tChar at string2[3]: " << string2->charAt(3) << endl;
	cout << "\tChar at string2[4]: " << string2->charAt(4) << endl;
	cout << "\tChar at string2[5]: " << string2->charAt(5) << endl;
	cout << "\tChar at string2[9]: " << string2->charAt(9) << endl; //should have char 'a'

	cout << "\n\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;


	int x;
	cin >> x;
	return 0;
}