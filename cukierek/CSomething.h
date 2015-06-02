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
    CEquilateralTriangle mTriangle;
    CCircle mInnerCircle;

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

    CSomething();
    virtual ~CSomething();
};

#endif // CSOMETHING_H
