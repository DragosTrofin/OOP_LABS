#include "RangeRover.h"
#include <iostream>
#include "Weather.h"
using namespace std;

RangeRover::RangeRover()
{
	fuelCapacity = 90; //litri
	fuelConsumption = 16;//litri la 100 km
	avgSpeed[Weather::SUNNY] = 130; //ambele scrieri sunt corecte
	avgSpeed[RAIN] = 90;
	avgSpeed[SNOW] = 60;

}
unsigned int RangeRover::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
	return circuitLenght / avgSpeed[condition];
}
void RangeRover::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption;
}
const char* RangeRover::getNume()
{
	return "RangeRover";
}