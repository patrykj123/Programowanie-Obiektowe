#include "CRightTriangle.h"

void CRightTriangle::updateVertices()
{
	const RECT& boundingRect = getBoundingRect();

    mVertices[0].x = boundingRect.left;
    mVertices[0].y = boundingRect.bottom;
    mVertices[1].x = boundingRect.left;
    mVertices[1].y = boundingRect.top;
    mVertices[2].x = boundingRect.right;
    mVertices[2].y = boundingRect.bottom;
}
