#pragma once
class Student
{
private:
	char nume[20];
	float medie,mate, e, is;
	
public:
	void setMate(float x);
	void setIstorie(float y);
	void setEngleza(float z);
	float Media(float a, float b,float c);
	float getEngleza();
	float getIstorie();
	float getMate();
	void setNume(const char s[20]);
	char* getNume();
};
