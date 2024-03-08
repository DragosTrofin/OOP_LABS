#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

void Student::setMate(float x)
{
	this->mate = x;
}
void Student::setEngleza(float z)
{
	this->e = z;
}
void Student::setIstorie(float y)
{
	this->is = y;
}
float Student::getMate()
{
	return this->mate;
}
float Student::getEngleza()
{
	return this->e;
}
float Student::getIstorie()
{
	return this->is;
}
void Student::setNume(const char s[20])
{
	strcpy_s(this->nume,20, s);
}
char* Student::getNume()
{
	return this->nume;
}
float Student::Media(float a, float b, float c)
{
	float s = 0;
	s = s + a + b + c;
	s = s / 3;
	return s;
}