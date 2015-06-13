#include "CSomething.h"

void CSomething::beforeBoundingRectChange(RECT* newBoundingRect)
{
    int height;
    RECT tmpRect;

    mSquare.setBoundingRect(*newBoundingRect);
    *newBoundingRect = mSquare.getBoundingRect();
    mOuterCircle.setBoundingRect(*newBoundingRect);
    height = newBoundingRect->bottom - newBoundingRect->top;
    tmpRect = *newBoundingRect;
    tmpRect.bottom -= height/4;
    mTriangle.setBoundingRect(tmpRect);
    tmpRect.top += height/4;
    tmpRect.left += height/4;
    tmpRect.right -= height/4;
    mInnerCircle.setBoundingRect(tmpRect);
}

//Metoda obs³uguj¹ca rysowanie obiektu graficznego.
void CSomething::Paint(HDC hdc)
{
    mSquare.Paint(hdc);
    mOuterCircle.Paint(hdc);
    mTriangle.Paint(hdc);
    mInnerCircle.Paint(hdc);
}

//Metoda obs³uguj¹ca reakcjê na up³yw czasu
void CSomething::Tick()
{
    CShape::Tick();

    mSquare.Tick();
    mOuterCircle.Tick();
    mTriangle.Tick();
    mInnerCircle.Tick();
}

CSomething::CSomething()
{
    mSquare.setColorChangeStep(5);
    mOuterCircle.setColorChangeStep(5);
    mTriangle.setColorChangeStep(5);
    mInnerCircle.setColorChangeStep(5);
}

CSomething::~CSomething()
{
}
