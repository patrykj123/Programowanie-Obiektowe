#include "CChequer.h"

void CChequer::afterBoundingRectChange()
{
    int width, height;
   	RECT tmpRect = getBoundingRect();


    width = tmpRect.right - tmpRect.left;
    height = tmpRect.bottom - tmpRect.top;

    tmpRect.right -= width/2;
    tmpRect.bottom -= height/2;
    mLeftTopRect.setBoundingRect(tmpRect);

    tmpRect.right += width/2;
    tmpRect.left += width/2;
    mRightTopRect.setBoundingRect(tmpRect);

    tmpRect.bottom += height/2;
    tmpRect.top += height/2;
    mRightBottomRect.setBoundingRect(tmpRect);

    tmpRect.right -= width/2;
    tmpRect.left -= width/2;
    mLeftBottomRect.setBoundingRect(tmpRect);
}

void CChequer::Paint(HDC hdc)
{
    mLeftTopRect.Paint(hdc);
    mRightTopRect.Paint(hdc);
    mLeftBottomRect.Paint(hdc);
    mRightBottomRect.Paint(hdc);
}

void CChequer::Tick()
{
    CShape::Tick();

    mLeftTopRect.Tick();
    mRightTopRect.Tick();

    mLeftBottomRect.setLineColor(mRightTopRect.getLineColor());
    mRightBottomRect.setLineColor(mLeftTopRect.getLineColor());
    mLeftBottomRect.setFillColor(mRightTopRect.getFillColor());
    mRightBottomRect.setFillColor(mLeftTopRect.getFillColor());
}


CChequer::CChequer()
{
    mLeftTopRect.setColorChangeStep(15);
    mRightTopRect.setColorChangeStep(15);
}

CChequer::~CChequer()
{

}
