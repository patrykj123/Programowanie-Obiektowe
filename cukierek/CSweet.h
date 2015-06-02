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
    //Wyzwalacz (trigger) wywo�ywany tu� przed zmian� w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zmodyfikowa� warto��,
    //kt�r� za chwil� przyjmie w�a�ciwo�� BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);

public:
    //Metoda obs�uguj�ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    //Metoda obs�uguj�ca reakcj� na up�yw czasu
    virtual void Tick();
    CSweet();
    virtual ~CSweet();
};

#endif // CSWEET_H
