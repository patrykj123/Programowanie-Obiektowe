#include "CSweet.h"

void CSweet::afterBoundingRectChange()
{
    int width, height;
   	RECT tmpRect = getBoundingRect();

    width = tmpRect.right - tmpRect.left;
    height = tmpRect.bottom - tmpRect.top;

    tmpRect.left += width/4;
    tmpRect.right -= width/4;
    mEllipse.setBoundingRect(tmpRect);

    tmpRect.left -= width/4;
    tmpRect.right -= width/2;
    mLeftTriangle.setBoundingRect(tmpRect);

    tmpRect.left += width*0.75;
    tmpRect.right += width*0.75;
    mRightTriangle.setBoundingRect(tmpRect);
}

void CSweet::Paint(HDC hdc)
{
    mEllipse.Paint(hdc);
    mLeftTriangle.Paint(hdc);
    mRightTriangle.Paint(hdc);
}

void CSweet::Tick()
{
    mEllipse.Tick();
    mLeftTriangle.Tick();

    mRightTriangle.setLineColor(mLeftTriangle.getLineColor());
    mRightTriangle.setFillColor(mLeftTriangle.getFillColor());

    CShape::Tick();
}


CSweet::CSweet()
{
    POINT vertices[3];

    mEllipse.setColorChangeStep(15);
    mLeftTriangle.setColorChangeStep(15);

    vertices[0].x = 10;
    vertices[0].y = 10;
    vertices[1].x = 20;
    vertices[1].y = 15;
    vertices[2].x = 10;
    vertices[2].y = 20;
    mLeftTriangle.setVertices(vertices);
    mLeftTriangle.setBoundingRect(getBoundingRect());

    vertices[0].x = 20;
    vertices[0].y = 10;
    vertices[1].x = 10;
    vertices[1].y = 15;
    vertices[2].x = 20;
    vertices[2].y = 20;
    mRightTriangle.setVertices(vertices);
    mRightTriangle.setBoundingRect(getBoundingRect());
}

CSweet::~CSweet()
{

}
