#include "Car.h"
class Fiat : public Car
{
public:
	Fiat();
	unsigned int GetRaceTime(unsigned int circuitLenght, Weather condition);
	void printSpecs();
	const char* getNume();
};
