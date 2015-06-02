#include "Utils.h"
#include <math.h>

//Funkcja zwraca liczbê pseudolosow¹ z przedzia³u <min, max>
int RandRange(int min, int max)
{
    return min + rand() % (1 + max - min);
}

//Funkcja zwraca -1 dla argumentu ujemnego;
// +1 dla argumentu dodatniego lub 0
int Sign(int arg)
{
    return arg < 0 ? -1 : 1;
}

double Deg2Rad(double aDegrees)
{
    return aDegrees * PI / 180.0;
}

double Rad2Deg(double aRadians)
{
    return aRadians * 180 / PI;
}

float DirectionFromSpeedXY(int aSpeedX, int aSpeedY)
{
    if(aSpeedX==0 && aSpeedY==0)
        return 0;
    else
        return atan2(aSpeedX, -aSpeedY);
}

float SpeedFromSpeedXY(int aSpeedX, int aSpeedY)
{
    return sqrt(aSpeedX*aSpeedX + aSpeedY*aSpeedY);// * Sign(aSpeedX*aSpeedY);
}

void SpeedXYFromSpeedDirection(float aSpeed, float aDirection, int *aSpeedX, int *aSpeedY)
{
    aSpeed = abs(aSpeed);
    *aSpeedX = aSpeed * sin(aDirection);
    *aSpeedY = -aSpeed * cos(aDirection);
}

void CorrectRect(RECT *aRect)
{
    int temp;

    if(aRect->right < aRect->left)
    {
        temp = aRect->right;
        aRect->right = aRect->left;
        aRect->left = temp;
    }

    if(aRect->bottom < aRect->top)
    {
        temp = aRect->bottom;
        aRect->bottom = aRect->top;
        aRect->top = temp;
    }
}







