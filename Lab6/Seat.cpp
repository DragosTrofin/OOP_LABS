#include "Seat.h"
#include <iostream>
#include "Weather.h"
using namespace std;

Seat::Seat()
{
	fuelCapacity = 80; //litri
	fuelConsumption = 10;//litri la 100 km
	avgSpeed[Weather::SUNNY] = 100; //ambele scrieri sunt corecte
	avgSpeed[RAIN] = 70;
	avgSpeed[SNOW] = 50;

}
unsigned int Seat::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
	return circuitLenght / avgSpeed[condition];
}
void Seat::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption;
}
const char* Seat::getNume()
{
	return "Seat";
}