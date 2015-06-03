#include <cstdlib>
#include <iostream>
#include <math.h>

#include "CRadiation.h"

const float SQRT3DIV2 = sqrt(3.0) / 2.0;

void CRadiation::afterBoundingRectChange()
{
    int width, height;
   	RECT tmpRect = getBoundingRect();

    width = tmpRect.right - tmpRect.left;
    height = tmpRect.bottom - tmpRect.top;

    mCircles[0].setBoundingRect(tmpRect);

    tmpRect.left += width * 0.06;
    tmpRect.right -= width * 0.06;
    tmpRect.top += height * 0.06;
    tmpRect.bottom -= height * 0.06;
    mCircles[1].setBoundingRect(tmpRect);

    uptadeTriangles(mCircles[1].getBoundingRect());

    tmpRect.left += width * 0.06;
    tmpRect.right -= width * 0.06;
    tmpRect.top += height * 0.06;
    tmpRect.bottom -= height * 0.06;
    mCircles[2].setBoundingRect(tmpRect);


    tmpRect.left += width * 0.24;
    tmpRect.right -= width * 0.24;
    tmpRect.top += height * 0.24;
    tmpRect.bottom -= height * 0.24;
    mCircles[3].setBoundingRect(tmpRect);


    tmpRect.left += width * 0.06;
    tmpRect.right -= width * 0.06;
    tmpRect.top += height * 0.06;
    tmpRect.bottom -= height * 0.06;
    mCircles[4].setBoundingRect(tmpRect);
}

void CRadiation::Paint(HDC hdc)
{
    for(int i = 0; i < 3; i++)
        mCircles[i].Paint(hdc);
    for(int i = 0; i < 3; i++)
        mTriangle[i].Paint(hdc);
    for(int i = 3; i < 5; i++)
        mCircles[i].Paint(hdc);

}

void CRadiation::Tick()
{
    CShape::Tick();
}


void CRadiation::uptadeTriangles(RECT boundingRect){
    POINT vertices[3];
    int width,height, centerHeight,centerWidth;
    width = boundingRect.right - boundingRect.left;
    height = boundingRect.bottom - boundingRect.top;
    centerHeight = boundingRect.top + height /2;
    centerWidth = boundingRect.left + width /2;

    vertices[0].x = boundingRect.right - 1;
    vertices[0].y = centerHeight;
    vertices[1].x = centerWidth;
    vertices[1].y = centerHeight;
    vertices[2].x = boundingRect.right - width /4;
    vertices[2].y = centerHeight + ( (width / 2 * sqrt(3) ) / 2);
    mTriangle[0].setVertices(vertices);

    //SQRT3DIV2
    vertices[0].x = boundingRect.left + 1;
    vertices[0].y = centerHeight;
    vertices[1].x = centerWidth;
    vertices[1].y = centerHeight;
    vertices[2].x = boundingRect.left + width /4;
    vertices[2].y = centerHeight + width / 2 * SQRT3DIV2;
    mTriangle[1].setVertices(vertices);

    vertices[0].x = centerWidth;
    vertices[0].y = centerHeight;
    vertices[1].x = boundingRect.right - width /4 - 3;
    vertices[1].y = centerHeight - width / 2 * SQRT3DIV2;
    vertices[2].x = boundingRect.left + width /4 + 3;
    vertices[2].y = centerHeight - width / 2 * SQRT3DIV2;
    mTriangle[2].setVertices(vertices);
}

CRadiation::CRadiation()
{
    mCircles[0].setFillColor(RGB(0,0,0));
    mCircles[0].setLineColor(RGB(0,0,0));
    mCircles[1].setLineColor(RGB(255, 255, 0));
    mCircles[2].setFillColor(RGB(0,0,0));
    mCircles[2].setLineColor(RGB(0,0,0));
    mCircles[3].setLineColor(RGB(255, 255, 0));
    mCircles[4].setFillColor(RGB(0,0,0));
    mCircles[4].setLineColor(RGB(0,0,0));

    for(int i = 0; i < 3; i++){
        mTriangle[i].setLineColor(RGB(255, 255, 0));
        mTriangle[i].setFillColor(RGB(255, 255, 0));
    }
}

CRadiation::~CRadiation()
{
    //dtor
}
