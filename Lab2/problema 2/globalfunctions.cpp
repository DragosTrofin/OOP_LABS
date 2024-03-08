#pragma once
#include "globalfunctions.h"
#include <cstring>
using namespace std;
 int compNume(Student& p1,Student& p2)
 {
	 int x = strcmp(p1.getNume(), p2.getNume());
	 return x;

 }
 int compMate(Student& p1, Student& p2)
 {
	 if (p1.getMate() > p2.getMate())
		 return 1;
	 else
		 if (p1.getMate()< p2.getMate())
			 return -1;
		 else
			 return 0;
 }
 int compEngleza(Student& p1, Student& p2)
 {
	 if (p1.getEngleza() > p2.getEngleza())
		 return 1;
	 else
		 if (p1.getEngleza() < p2.getEngleza())
			 return -1;
		 else
			 return 0;
 }
 int compIstorie(Student& p1, Student& p2)
 {
	 if (p1.getIstorie() > p2.getIstorie())
		 return 1;
	 else
		 if (p1.getIstorie() < p2.getIstorie())
			 return -1;
		 else
			 return 0;
 }
 int compMedie(Student& p1, Student& p2)
 {
	 if (p1.Media(p1.getMate(), p1.getEngleza(), p1.getIstorie()) > p2.Media(p2.getMate(), p2.getEngleza(), p2.getIstorie()))
		 return 1;
	 else
	if (p1.Media(p1.getMate(), p1.getEngleza(), p1.getIstorie()) < p2.Media(p2.getMate(), p2.getEngleza(), p2.getIstorie()))
		 return -1;
	 else 
			 return 0;
 }