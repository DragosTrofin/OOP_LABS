#include <iostream>
#include "Car.h"
#include "Circuit.h"
using namespace std;

int main()
{
	Circuit c(5);
	c.SetLenght(500);
	c.SetWeather(Weather::SUNNY);
	c.AddCar(new Volvo());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new BMW());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}
