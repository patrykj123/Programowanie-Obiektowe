#ifndef CSOMETHING_H
#define CSOMETHING_H

#include "CShape.h"
#include "CSquare.h"
#include "CCircle.h"
#include "CEquilateralTriangle.h"

class CSomething : public CShape
{
    private:
        CSquare mSquare;
        CCircle mOuterCircle;
        CCircle mInnerCircle;
        CEquilateralTriangle mTriangle;
    public:
        virtual void Tick();
        virtual void Paint(HDC hdc);
        virtual void afterBoundingRectChange();
        CSomething();
    protected:

};

#endif // CSOMETHING_H
