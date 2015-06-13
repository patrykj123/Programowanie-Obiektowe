#include "CSquare.h"
#include <math.h>

//********** Private methods ***********
void CSquare::updateBoundingRect(RECT* newBoundingRect)
{
    int width, height, center;

    //zak³adam, ¿e prostok¹t jest ju¿ skorygowany
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
void CSquare::beforeBoundingRectChange(RECT* newBoundingRect)
{
    updateBoundingRect(newBoundingRect);
}
