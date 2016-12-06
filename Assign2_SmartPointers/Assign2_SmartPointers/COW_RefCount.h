//COW with Reference Counting
//.h files


class Buffer_COW_RefCount {
private:
	int _length;
	char* _strbuf;
public:
	int _refcount;
	Buffer_COW_RefCount();  //default constructor
	~Buffer_COW_RefCount();		 //destructor that deletes the allocated buffer
	Buffer_COW_RefCount(const Buffer_COW_RefCount&);
	Buffer_COW_RefCount(char*, int);
	char charAt(int) const;   //returns the character at the passed index
	int len() const;       //returns the length of the buffer
	void reserve(int);        //allocates memory for the string, according to the passed character length
	void append(char);        //appends a single character at the end	
	int get_refCount();


}; 

class String_COW_RefCount
{
private:
	Buffer_COW_RefCount* _str;
public:
	String_COW_RefCount();
	~String_COW_RefCount();
	String_COW_RefCount(const String_COW_RefCount&);
	String_COW_RefCount(char*, int);
	void append(char);
	int len() const;
	char charAt(int) const;
	int get_refCount();

};

