#include "Fiat.h"
#include <iostream>
#include "Weather.h"
using namespace std;

Fiat::Fiat()
{
	fuelCapacity = 40; //litri
	fuelConsumption = 7;//litri la 100 km
	avgSpeed[Weather::SUNNY] = 90; //ambele scrieri sunt corecte
	avgSpeed[RAIN] = 60;
	avgSpeed[SNOW] = 50;

}
unsigned int Fiat::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
	return circuitLenght / avgSpeed[condition];
}
void Fiat::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption;
}
const char* Fiat::getNume()
{
	return "Fiat";
}