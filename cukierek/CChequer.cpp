#include "CChequer.h"

void CChequer::beforeBoundingRectChange(RECT* newBoundingRect)
{
    int height;
    RECT tmpRect;
    mainSquare.setBoundingRect(*newBoundingRect);
    *newBoundingRect = mainSquare.getBoundingRect();
    height = newBoundingRect->bottom - newBoundingRect->top;

    tmpRect = *newBoundingRect;
    tmpRect.bottom -= height/2;
    tmpRect.right -= height/2;
    mSquare[0].setBoundingRect(tmpRect);

    tmpRect.right = newBoundingRect->right;
    tmpRect.left += height/2;
    mSquare[1].setBoundingRect(tmpRect);

    tmpRect.bottom = newBoundingRect->bottom;
    tmpRect.top += height/2;
    mSquare[3].setBoundingRect(tmpRect);

    tmpRect.left = newBoundingRect->left;
    tmpRect.right -= height/2;
    mSquare[2].setBoundingRect(tmpRect);

}

//Metoda obs³uguj¹ca rysowanie obiektu graficznego.
void CChequer::Paint(HDC hdc)
{
    for(int i = 0; i < 4; i++)
        mSquare[i].Paint(hdc);
}

//Metoda obs³uguj¹ca reakcjê na up³yw czasu
void CChequer::Tick()
{
    CShape::Tick();
    mSquare[0].Tick();
    mSquare[1].Tick();
    mSquare[2].setFillColor(mSquare[1].getFillColor());
    mSquare[2].setLineColor(mSquare[1].getLineColor());
    mSquare[3].setFillColor(mSquare[0].getFillColor());
    mSquare[3].setLineColor(mSquare[0].getLineColor());
}


CChequer::CChequer()
{
    for(int i = 0; i < 4; i++)
        mSquare[i].setColorChangeStep(5);
}

CChequer::~CChequer()
{
    //dtor
}
