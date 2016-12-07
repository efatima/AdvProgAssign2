//COW with Reference Linking
//.h file


class Buffer_COW_RefLinking {
private:
	int _length;
	char* _strbuf;
	Buffer_COW_RefLinking* _prev;
	Buffer_COW_RefLinking* _next;
public:
	Buffer_COW_RefLinking();  //default constructor
	~Buffer_COW_RefLinking();		 //destructor that deletes the allocated buffer
	Buffer_COW_RefLinking(Buffer_COW_RefLinking&);
	Buffer_COW_RefLinking(char*, int);
	char charAt(int) const;   //returns the character at the passed index
	int len() const;       //returns the length of the buffer
	void reserve(int);        //allocates memory for the string, according to the passed character length
	void append(char);        //appends a single character at the end	
	void printLinkedList(); //to display the doubly linked list after different operations on an object


};

class String_COW_RefLinking
{
private:
	Buffer_COW_RefLinking* _str;
public:
	String_COW_RefLinking();
	~String_COW_RefLinking();
	String_COW_RefLinking(String_COW_RefLinking&);
	String_COW_RefLinking(char*, int);
	void append(char);
	int len() const;
	char charAt(int) const;

};

