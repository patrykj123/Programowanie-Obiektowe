#include "CAbstractTriangle.h"

//********** Protected methods ***********
void CAbstractTriangle::doPaint(HDC hdc)
{
    Polygon(hdc, mVertices, 3);
}

void CAbstractTriangle::afterBoundingRectChange()
{
    updateVertices();
}

//**** Constructors & destructor ****
CAbstractTriangle::CAbstractTriangle()
{
	for(int i=0; i<3; i++)
	{
        mVertices[i].x = 0;
        mVertices[i].y = 0;
	}
}
