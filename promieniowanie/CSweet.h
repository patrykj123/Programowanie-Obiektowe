#ifndef CSWEET_H
#define CSWEET_H

#include "CShape.h"
#include "CEllipse.h"
#include "CTriangle.h"

class CSweet : public CShape
{
private:
    CEllipse mEllipse;
    CTriangle mLeftTriangle;
    CTriangle mRightTriangle;

protected:
    //Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zareagowaæ na zmianê w³aœciwoœci BoundingRect.
    virtual void afterBoundingRectChange();

public:
    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    //Metoda obs³uguj¹ca reakcjê na up³yw czasu
    virtual void Tick();

    CSweet();
    virtual ~CSweet();
};

#endif // CSWEET_H
