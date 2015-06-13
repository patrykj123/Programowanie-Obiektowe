#include "CEllipse.h"

//********** Protected methods ***********

void CEllipse::doPaint(HDC hdc)
{
	const RECT& boundingRect = getBoundingRect();

    Ellipse(hdc, boundingRect.left,
                 boundingRect.top,
                 boundingRect.right,
                 boundingRect.bottom);
}
