#include "Weather.h"
#pragma once
class Car
{
public:
	unsigned int fuelCapacity;
	unsigned int fuelConsumption;
	unsigned int avgSpeed[3]; //1 sunny 2 rainy 3 snow
	virtual unsigned int GetRaceTime(unsigned int circuitLenght, Weather condition) = 0;
	virtual const char* getNume() = 0;
	//functie sa returneze numele masini pentru fucntia care verifica daca poate termina cursa sau nu
};