#include "CCircle.h"
#include <math.h>

//********** Private methods ***********
void CCircle::updateBoundingRect(RECT* newBoundingRect)
{
    int width, height, center;

    //zak�adam, �e prostok�t jest ju� skorygowany
    width = newBoundingRect->right - newBoundingRect->left;
    height = newBoundingRect->bottom - newBoundingRect->top;

    if(width > height)
    {
        center = (newBoundingRect->right + newBoundingRect->left) / 2;
        newBoundingRect->right = center + height / 2;
        newBoundingRect->left = center - height / 2;
    }
    else if(width < height)
    {
        center = (newBoundingRect->bottom + newBoundingRect->top) / 2;
        newBoundingRect->top = center - width / 2;
        newBoundingRect->bottom = center + width / 2;
    }
}

//********** Protected methods ***********
void CCircle::beforeBoundingRectChange(RECT* newBoundingRect)
{
    updateBoundingRect(newBoundingRect);
}
