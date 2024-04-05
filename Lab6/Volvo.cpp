#include "Volvo.h"
#include <iostream>
#include "Weather.h"
using namespace std;

Volvo::Volvo()
{
	fuelCapacity = 60; //litri
	fuelConsumption = 12;//litri la 100 km
	avgSpeed[Weather::SUNNY] = 120; //ambele scrieri sunt corecte
	avgSpeed[RAIN] = 80;
	avgSpeed[SNOW] = 70;

}
unsigned int Volvo::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
	return circuitLenght / avgSpeed[condition];
}
void Volvo::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption;
}
const char* Volvo::getNume()
{
	return "Volvo";
}