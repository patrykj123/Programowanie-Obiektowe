#include "CEquilateralTriangle.h"
#include <math.h>

const float SQRT3DIV2 = sqrt(3.0) / 2.0;

//********** Private methods ***********
void CEquilateralTriangle::updateBoundingRect(RECT* newBoundingRect)
{
    int rectWidth, rectHeight, trnglHeight, trnglWidth, center;

    //zak³adam, ¿e prostok¹t jest ju¿ skorygowany
    rectWidth = newBoundingRect->right - newBoundingRect->left;
    rectHeight = newBoundingRect->bottom - newBoundingRect->top;

    //obliczam wysokoœæ trójk¹ta na podstawie szerokoœci prostok¹ta
    trnglHeight = rectWidth * SQRT3DIV2;

    if(trnglHeight > rectHeight)
    {
        trnglWidth = rectHeight / SQRT3DIV2;
        center = (newBoundingRect->right + newBoundingRect->left) / 2;
        newBoundingRect->right = center + trnglWidth / 2;
        newBoundingRect->left = center - trnglWidth / 2;
    }
    else
    {
        center = (newBoundingRect->bottom + newBoundingRect->top) / 2;
        newBoundingRect->top = center - trnglHeight / 2;
        newBoundingRect->bottom = center + trnglHeight / 2;
    }
}

//********** Protected methods ***********
void CEquilateralTriangle::beforeBoundingRectChange(RECT* newBoundingRect)
{
    updateBoundingRect(newBoundingRect);
}

