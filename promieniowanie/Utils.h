#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <windows.h>


const double PI = 3.1415926535897932384626433832795;

struct SPEEDXY
{
    int SpeedX, SpeedY;
};

/*********************** Funkcje pomocnicze ***********************/

//Funkcja zwraca liczbê pseudolosow¹ z przedzia³u <min, max>
int RandRange(int min, int max);

//Funkcja zwraca -1 dla argumentu ujemnego;
// +1 dla argumentu dodatniego lub 0
int Sign(int arg);

double Deg2Rad(double aDegrees);

double Rad2Deg(double aRadians);

float DirectionFromSpeedXY(int aSpeedX, int aSpeedY);

float SpeedFromSpeedXY(int aSpeedX, int aSpeedY);

void SpeedXYFromSpeedDirection(float aSpeed, float aDirection, int *aSpeedX, int *aSpeedY);

void CorrectRect(RECT *aRect);


#endif // UTILS_H_INCLUDED
