#include "CSweet.h"

void CSweet::beforeBoundingRectChange(RECT* newBoundingRect)
{
    int width;
    POINT vertices[3];
    RECT tmpRect;
    width = newBoundingRect->right - newBoundingRect->left;

    tmpRect = *newBoundingRect;
    tmpRect.left += width/4;
    tmpRect.right -= width/4;
    mEllipse.setBoundingRect(tmpRect);

    tmpRect = *newBoundingRect;

    vertices[0].x = tmpRect.left;
    vertices[0].y = tmpRect.top;
    vertices[1].x = tmpRect.left;
    vertices[1].y = tmpRect.bottom;
    vertices[2].x = tmpRect.left + width/4;
    vertices[2].y = tmpRect.top + (tmpRect.bottom - tmpRect.top)/2;

    mLeftTriangle.setVertices(vertices);

    vertices[0].x = tmpRect.right;
    vertices[0].y = tmpRect.top;
    vertices[1].x = tmpRect.right;
    vertices[1].y = tmpRect.bottom;
    vertices[2].x = tmpRect.right - width/4;
    vertices[2].y = tmpRect.top + (tmpRect.bottom - tmpRect.top)/2;

    mRightTriangle.setVertices(vertices);

}

//Metoda obs³uguj¹ca rysowanie obiektu graficznego.
void CSweet::Paint(HDC hdc)
{
    mLeftTriangle.Paint(hdc);
    mRightTriangle.Paint(hdc);
    mEllipse.Paint(hdc);
}

//Metoda obs³uguj¹ca reakcjê na up³yw czasu
void CSweet::Tick()
{
    CShape::Tick();

    mLeftTriangle.Tick();
    mEllipse.Tick();
    mRightTriangle.setFillColor(mLeftTriangle.getFillColor());
    mRightTriangle.setLineColor(mLeftTriangle.getLineColor());
}

CSweet::CSweet()
{
    mLeftTriangle.setColorChangeStep(5);
    mRightTriangle.setColorChangeStep(5);
    mEllipse.setColorChangeStep(5);
}

CSweet::~CSweet()
{

}
