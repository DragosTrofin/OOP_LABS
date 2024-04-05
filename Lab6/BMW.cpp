#include "BMW.h"
#include <iostream>
#include "Weather.h"
using namespace std;

BMW::BMW()
{
	fuelCapacity = 70; //litri
	fuelConsumption = 100;//litri la 100 km
	avgSpeed[Weather::SUNNY] = 140; //ambele scrieri sunt corecte
	avgSpeed[RAIN] = 90;
	avgSpeed[SNOW] = 70;

}
unsigned int BMW::GetRaceTime(unsigned int circuitLenght, Weather condition)
{
	return circuitLenght / avgSpeed[condition];
}
void BMW::printSpecs()
{
	cout << fuelCapacity << " " << fuelConsumption;
}
const char* BMW::getNume()
{
	return "BMW";
}
	