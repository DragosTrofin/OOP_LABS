#include <iostream>
#include "NumberList.h"
using namespace std;
int main()
{
	NumberList nr1;
	NumberList nr2;

	nr1.Init();
	nr1.Add(3);
	nr1.Add(77);
	nr1.Add(98);
	nr1.Add(17);
	nr1.Add(15);
	nr1.Add(9);
	nr1.Add(12);
	nr1.Add(11);
	nr1.Add(7);
	nr1.Add(6);
	nr1.Add(5);
	nr1.Add(4);
	cout << "sirul nesortat:" << endl;
	nr1.Print();
	nr1.Sort();
	cout << endl << "sirul sortat:" << endl;
	nr1.Print();

	return 0;
}
