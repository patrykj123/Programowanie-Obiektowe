#include <cstdlib>
#include <iostream>
#include "CSomething.h"


void CSomething::Tick(){
    CShape::Tick();
    mSquare.Tick();
    mOuterCircle.Tick();
    mInnerCircle.Tick();
    mTriangle.Tick();
}

void CSomething::afterBoundingRectChange(){
    RECT tmpRect; int height;
    mSquare.setBoundingRect(getBoundingRect());
    mOuterCircle.setBoundingRect(mSquare.getBoundingRect());
    mOuterCircle.getBoundingRect(tmpRect);
    height = tmpRect.bottom - tmpRect.top;
    tmpRect.bottom -= (height * 1/4);
    mTriangle.setBoundingRect(tmpRect);
    tmpRect.top += (height / 4);
    tmpRect.bottom = tmpRect.top + (height / 2);
    mInnerCircle.setBoundingRect(tmpRect);
}

void CSomething::Paint(HDC hdc){
    mSquare.Paint(hdc);
    mOuterCircle.Paint(hdc);
    mTriangle.Paint(hdc);
    mInnerCircle.Paint(hdc);
}

CSomething::CSomething()
{
    mSquare.setColorChangeStep(5);
    mOuterCircle.setColorChangeStep(5);
    mInnerCircle.setColorChangeStep(5);
    mTriangle.setColorChangeStep(5);
}


