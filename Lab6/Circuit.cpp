#include "Circuit.h"
#include <iostream>
#include "Car.h"


using namespace std;
void swappos(board* p1, board* p2)
{
    int i;
    double aux;
    char caux[10];
    aux = p2->finish;
    p2->finish = p1->finish;
    p1->finish = aux;
    aux = p2->time;
    p2->time = p1->time;
    p1->time = aux;
    i = 0;
    while (p1->name[i] != '\0')
    {
        caux[i] = p1->name[i];
        i++;
    }
    caux[i] = p1->name[i];
    i = 0;
    while (p2->name[i] != '\0')
    {
        p1->name[i] = p2->name[i];
        i++;
    }
    p1->name[i] = p2->name[i];
    i = 0;
    while (caux[i] != '\0')
    {
        p2->name[i] = caux[i];
        i++;
    }
    p2->name[i] = caux[i];
}

void Circuit::SetLenght(unsigned int lenght)
{
	this->lenght = lenght;
}
void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
}
void Circuit::AddCar(Car* car)
{
	cars[nrCars++] = car;
}
void Circuit::Race()
{
    const char* s;
    int k;
    if (b != nullptr)
        delete[] b;
    b = new board[nrCars];
    for (int i = 0; i < nrCars; i++)
    {
        k = 0;
        s = cars[i]->getNume();
        while (s[k] != '\0')
        {
            b[i].name[k] = s[k];
            k++;
        }
        b[i].name[k] = s[k];
        b[i].time = cars[i]->GetRaceTime(lenght,weather);
        if (dnf(cars[i],lenght)==0)
            b[i].finish = 0;
        else b[i].finish = 1;
    }
}

Circuit::Circuit(unsigned int nrDesiredCars)
{
	cars = new Car * [nrDesiredCars];
}
int Circuit::dnf(Car* masina, unsigned int lenght)
{
    int fuel = masina->fuelConsumption;
    int a = (lenght * fuel) / 100;
    if (a > masina->fuelCapacity)
        return 0;
    return 1;
}

void Circuit::ShowWhoDidNotFinish()
{
    printf("These cars did not finish: \n");
    for (int i = 0; i < nrCars; i++)
        if (b[i].finish == 0)
            printf("%s\n", b[i].name);
}
void Circuit::ShowFinalRanks()
{
    int ultim, i, j;
    ultim = nrCars - 1;
    while (ultim > 0)
    {
        j = ultim - 1;
        ultim = 0;
        for (i = 0; i <= j; i++)
            if (b[i].finish == 0 && b[i + 1].finish == 1)
            {
                swappos(&b[i], &b[i + 1]);
                ultim = i;
            }
            else	if (b[i].time > b[i + 1].time && b[i + 1].finish == 1)
            {
                swappos(&b[i], &b[i + 1]);
                ultim = i;
            }
    }

    printf("This is the final ranking: \n");
    for (int i = 0; i < nrCars; i++)
        if (b[i].finish == 1)
            printf("%d. %s: %.3f\n", i + 1, b[i].name, b[i].time);

}
