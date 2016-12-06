//COW with Reference Counting
//.h files

class String
{
public:
	int _length;
	int _refcount;
	char* _strbuf;
	String();
};

class COW_RefCount {

public:
	COW_RefCount();  //default constructor
	~COW_RefCount();		 //destructor that deletes the allocated buffer
	COW_RefCount(const COW_RefCount&); 
	COW_RefCount(char*, int); 
	char charAt(int) const;   //returns the character at the passed index
	int len() const;       //returns the length of the buffer
	void reserve(int);        //allocates memory for the string, according to the passed character length
	void append(char);        //appends a single character at the end
	String* get_str();

private:
	String* _str;
}; 
