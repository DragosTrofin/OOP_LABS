#include "Number.h"
#include <cstring>
#include <iostream>
using namespace std;
Number::Number(const char* value, int base)
{
	sir = new char[100] {};
	strcpy(sir, value);
	nrBase = base;
	sirLen = strlen(sir);
}


void Number::Print()
{
	cout << "Numarul" << " " << sir << " " << "in baza" << nrBase;
	cout << endl;
}
Number::~Number()
{
	delete[] sir;
	sir = nullptr;

}

unsigned int Number::GetBase10Number() const //gaybase
{
	unsigned int result = 0, power = 1;
	int i;
	for (i = sirLen - 1; i >= 0; i--)
	{
		if (sir[i] >= '0' && sir[i] <= '9')
		{
			result = result + (sir[i] - '0') * power;	
		}
		else
		{
			result = result + (sir[i] - 'A' + 10) * power;
		}
		power = power * nrBase;
	}
	return result;
}

bool Number::operator <(const Number& otherNumber)
{
	return GetBase10Number() < otherNumber.GetBase10Number();
}
bool Number::operator >(const Number& otherNumber)
{
	return GetBase10Number() > otherNumber.GetBase10Number();
}
bool Number::operator <=(const Number& otherNumber)
{
	return GetBase10Number() <= otherNumber.GetBase10Number();
}
bool Number::operator >=(const Number& otherNumber)
{
	return GetBase10Number() >= otherNumber.GetBase10Number();
}
bool Number::operator ==(const Number& otherNumber)
{
	return GetBase10Number() == otherNumber.GetBase10Number();
}
int Number::GetBase()
{
	return nrBase;
}
int Number::GetDigitsCount()
{
	return sirLen;
}

Number::Number(const Number& d)
{
	nrBase = d.nrBase;
	strcpy(d.sir, sir);
	sirLen = d.sirLen;
}
Number::Number(Number&& d)
{
	char* temp = d.sir;
	d.sir = nullptr;
	this->sir = temp;
	int d1 = d.nrBase;
	d.nrBase = 0;
	this->nrBase = d1;
	int d2 = d.sirLen;
	d.sirLen = 0;
	this->sirLen = d2;
}

char Number::operator[](int index) const 
{
	if (index < 0 || index >= this->sirLen)
	{
			cout << "Index out of range";
			cout << endl;
	}
	return sir[index];
}

Number& Number::operator=(const Number& other) 
{
	if (this != &other) {
		strcpy(sir, other.sir);
		nrBase = other.nrBase;
	}
	return *this;
}

bool Number::operator --()
{
	strcpy(sir, sir + 1);
	return true;
}

bool Number::operator --(int value)
{
	sir[strlen(sir)] = NULL;
}
int nr = 0;
char convertToBase(int num, int base)
{
	nr = 0;
	char* numar;
	while (num != 0)
	{
		int c = num % base;
		char cif;
		if (c < 10)
			cif = '0' + c;
		else
			cif = 'A' + c - 10;
		numar = numar + cif;
		nr++;
		num = num / base;
	}
		return *numar;
}
void Number::SwitchBase(int newBase)
{
	int result = GetBase10Number();
	*sir = convertToBase(result, newBase);
	nrBase = newBase;
	sirLen = nr;
}
Number& Number::operator=(Number&& other)
{
	if (this != &other) {
		sir = std::move(other.sir);
		nrBase = other.nrBase;
	}
	return *this;
}

Number operator+(Number num1, Number num2)
{
	int baza;
	if (num1.nrBase > num2.nrBase)
	{
		num2.SwitchBase(num1.nrBase);
		 baza = num1.nrBase;
	}
	else
	{
		num1.SwitchBase(num2.nrBase);
		 baza = num2.nrBase;
	}
	int result1 = num1.GetBase10Number() + num2.GetBase10Number();
	result1 = convertToBase(result1, baza);
	return result1;
}
Number operator-(Number num1, Number num2)
{
	int baza;
	if (num1.nrBase > num2.nrBase)
	{
		num2.SwitchBase(num1.nrBase);
		baza = num1.nrBase;
	}
	else
	{
		num1.SwitchBase(num2.nrBase);
		baza = num2.nrBase;
	}
	int result1 = num1.GetBase10Number() - num2.GetBase10Number();
	result1 = convertToBase(result1, baza);
	return result1;
}