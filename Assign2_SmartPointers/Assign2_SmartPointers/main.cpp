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

using namespace std;


int main() {

	cout << "\nWelcome to Smart Pointer Libarary for Strings!" << endl;

	cout <<"\n%%%%%%%%%%%%%%%  Reference Counting   %%%%%%%%%%%%%%%%%%%%"<< endl;
	char* myString = "Eman";
	COW_RefCount* string1 = new COW_RefCount(myString, strlen(myString));//using 2 param constructor
	
	//COW_RefCount* string2 = new COW_RefCount(); //default constructor
    COW_RefCount* string2 = new COW_RefCount(*string1); //using 1 param constructor

	cout << "Char at string1[0]: " << string1->charAt(0) << endl;
	cout << "Char at string1[1]: " << string1->charAt(1) << endl;
	cout << "Char at string1[2]: " << string1->charAt(2) << endl;
	cout << "Char at string1[3]: " << string1->charAt(3) << endl;


	cout << "Reference count of String1 BEFORE modifying String2: " << string1->get_str()->_refcount << endl;
	cout << "Reference count of String2: " << string2->get_str()->_refcount << endl;

	string2->append('F');
	string2->append('a');
	string2->append('t');
	string2->append('i');
	string2->append('m');
	string2->append('a');
	
	cout << "Reference count of String1 AFTER modifying String2: " << string1->get_str()->_refcount << endl;
	cout << "Reference count of String2: " << string2->get_str()->_refcount << endl;
	cout << "Char at string2[0]: " << string2->charAt(0) << endl;
	cout << "Char at string2[1]: " << string2->charAt(1) << endl;
	cout << "Char at string2[2]: " << string2->charAt(2) << endl;
	cout << "Char at string2[3]: " << string2->charAt(3) << endl;
	cout << "Char at string2[4]: " << string2->charAt(4) << endl;
	cout << "Char at string2[5]: " << string2->charAt(5) << endl;
	cout << "Char at string2[9]: " << string2->charAt(9) << endl; //should have char 'a'

	cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;


	int x;
	cin >> x;
	return 0;
}