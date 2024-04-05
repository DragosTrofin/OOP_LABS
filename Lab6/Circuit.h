#pragma once
#include "Weather.h"
#include "Car.h"
#include "Volvo.h"
#include "Seat.h"
#include "Fiat.h"
#include "RangeRover.h"
#include "BMW.h"
struct board
{
	bool finish;
	float time;
	char name[10];
};
class Circuit
{
private:
	unsigned int lenght;
	Weather weather;
	//Car* cars[20];
	unsigned int nrCars = 0;
	Car** cars;
	board* b;
public:
	Circuit(unsigned int nrDesiredCars);
	void SetLenght(unsigned int lenght);
	void SetWeather(Weather weather);
	void AddCar(Car *car);
	void Race();
	int dnf(Car* masina, unsigned int lenght);
	void ShowWhoDidNotFinish();
	void ShowFinalRanks();
};