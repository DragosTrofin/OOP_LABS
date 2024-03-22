#include <iostream>
#include "Sort.h"
using namespace std;
char s[20] = "11,9,5,3,2,1";
int y[] = { 20,13,35,24,144 };
int main()
{
    Sort v(5,3,2,5,1,11);
    Sort x(s);
    Sort a(5, 72, 100);
    Sort b(y, 5);
    Sort c;
    v.BubbleSort();
    a.InsertSort();
    x.QuickSort(true,0,x.GetElementsCount()-1);
    v.Print();
    x.Print();
    a.Print();
    b.Print();
    c.Print();


}

