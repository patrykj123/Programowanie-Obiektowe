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
    //Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zareagowa� na zmian� w�a�ciwo�ci BoundingRect.
    virtual void afterBoundingRectChange();

public:
    //Metoda obs�uguj�ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    //Metoda obs�uguj�ca reakcj� na up�yw czasu
    virtual void Tick();

    CSweet();
    virtual ~CSweet();
};

#endif // CSWEET_H
