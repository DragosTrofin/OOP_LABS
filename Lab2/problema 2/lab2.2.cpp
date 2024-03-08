#include <iostream>
#include "Student.h"
#include "globalfunctions.h"
using namespace std;
int main()
{
    Student s1,s2;
    s1.setNume("Ionescu");
    s2.setNume("Popescu");
    cout << s1.getNume() << " " << s2.getNume() << endl;
    cout << compNume(s1, s2)<<endl;
    s1.setMate(5);
    s2.setMate(8);
    cout << s1.getMate() << " " << s2.getMate() << endl;
    cout<<compMate(s1, s2)<<endl;
    s1.setIstorie(9);
    s2.setIstorie(7);
    cout << s1.getIstorie() << " " << s2.getIstorie() << endl;
    cout << compIstorie(s1, s2)<<endl;
    s1.setEngleza(10);
    s2.setEngleza(10);
    cout << s1.getEngleza() << " " << s2.getEngleza() << endl;
    cout << compEngleza(s1, s2) << endl;
    cout << s1.Media(s1.getEngleza(), s1.getIstorie(), s1.getMate())<<endl;
    cout << s2.Media(s2.getEngleza(), s2.getIstorie(), s2.getMate()) << endl;
    cout << compMedie(s1, s2) << endl;
}

