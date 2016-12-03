//Copied Pointers
//.h file

class Copied_Buff {

public:

	Copied_Buff();  //default constructor
	~Copied_Buff(); //destructor; would delete the allocated buffer

	Copied_Buff(const Copied_Buff&); 
	Copied_Buff(char*, int);   
	
	void append(char);        //appends a single character at the end
	char charAt(int) const;   //returns the character at the passed index
	int len() const;			//returns the length of the buffer
	void reserve(int);        //allocates memory for the string, according to the passed character length
	
private:
	int _length;                //length of the string
	char* _strbuf;             //buffer to store the original string
};

