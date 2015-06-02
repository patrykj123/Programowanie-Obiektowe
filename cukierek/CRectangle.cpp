#include "CRectangle.h"

//********** Protected methods ***********

void CRectangle::doPaint(HDC hdc)
{
	const RECT& boundingRect = getBoundingRect();

    Rectangle(hdc, boundingRect.left,
                   boundingRect.top,
                   boundingRect.right,
                   boundingRect.bottom);
}
