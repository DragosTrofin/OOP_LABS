#include "Math.h"
#include <cstring>
#include <cstdarg>
int Math::Add(int x, int y)
{
	return x + y;
}
int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...) // sums up a list of integers
{
	int s = 0;
	va_list vl;
	va_start(vl, count);
	for (int i = 0; i < count; i++)
		s = s + va_arg(vl,int);
	va_end(vl);
	return s;
}
char* Math::Add(const char* x, const char* y)
{
	if (x==nullptr || y==nullptr)
		return nullptr;

	int lgx = strlen(x);
	int lgy = strlen(y);
	int aux,v=0,t=0;
	const char* a;
	if (lgy > lgx)
	{
		aux = lgx;
		lgx = lgy;
		lgy = aux;
		a = x;
		x = y;
		y = a;
	}
	char* z = new char[lgx + 2];
	memset(z, 0, lgx + 2);
	for (int i = 1; i <=lgx; i++)
	{
		
		if (i <= lgy)
			v = (x[lgx - i] - '0') + (y[lgx - i] - '0') + t;
		else
			v = x[lgx - i] - '0' + t;
			 z[lgx + 1 - i] = v % 10 + '0';
			 t = v / 10;
	}
	z[0] =t + '0';
	if (z[0] == '0')
		memcpy(z, z + 1, lgx+1);
	return z;
}