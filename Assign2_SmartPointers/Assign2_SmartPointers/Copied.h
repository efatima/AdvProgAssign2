//Copied Pointer
//.h files

//buffer class
class Buffer_Copied {

public:

	Buffer_Copied();  //default constructor
	~Buffer_Copied(); //destructor; would delete the allocated buffer

	Buffer_Copied(const Buffer_Copied&);
	Buffer_Copied(char*, int);
	
	void append(char);        //appends a single character at the end
	char charAt(int) const;   //returns the character at the passed index
	int len() const;			//returns the length of the buffer
	void reserve(int);        //allocates memory for the string, according to the passed character length
	
private:
	int _length;                //length of the string
	char* _strbuf;             //buffer to store the original string
};

//String enveloping class
class String_Copied
{
private:
	Buffer_Copied* _str;
public:
	String_Copied();
	~String_Copied();
	String_Copied(const String_Copied&);
	String_Copied(char*, int);
	void append(char);
	int len() const;
	char charAt(int) const;
};