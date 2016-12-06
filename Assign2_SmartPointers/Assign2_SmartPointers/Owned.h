//Copied Pointer
//.h files

//buffer class
class Buffer_Owned {

public:

	Buffer_Owned();  //default constructor
	~Buffer_Owned(); //destructor; would delete the allocated buffer

	Buffer_Owned(const Buffer_Owned&);
	Buffer_Owned(char*, int);

	void append(char);        //appends a single character at the end
	char charAt(int) const;   //returns the character at the passed index
	int len() const;			//returns the length of the buffer
	void reserve(int);        //allocates memory for the string, according to the passed character length

private:
	int _length;                //length of the string
	char* _strbuf;             //buffer to store the original string
};

//String enveloping class
class String_Owned
{
private:
	Buffer_Owned* _str;
public:
	String_Owned();
	~String_Owned();
	String_Owned(const String_Owned&);
	String_Owned(char*, int);
	void append(char);
	int len() const;
	char charAt(int) const;
};