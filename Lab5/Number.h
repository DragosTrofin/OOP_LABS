class Number
{
	char* sir;
	int nrBase;
	unsigned int sirLen;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(unsigned int value);

	// add operators and copy/move constructor
	Number(const Number& d);
	Number(Number&& d);
	char operator[](int index) const;
	Number& operator=(const Number& other);
	unsigned int GetBase10Number()const;
	bool operator <(const Number& otherNumber);
	bool operator <=(const Number& otherNumber);
	bool operator >(const Number& otherNumber);
	bool operator >=(const Number& otherNumber);
	bool operator ==(const Number& otherNumber);
	void SwitchBase(int newBase);
	void Print();
	Number& operator=(Number&& other);
	bool operator --();
	bool operator --(int value);
	friend Number operator+(Number num1, Number num2);
	friend Number operator-( Number num1, Number num2);

	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};