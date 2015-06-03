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
    //Wyzwalacz (trigger) wywo³ywany tu¿ przed zmian¹ w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zmodyfikowaæ wartoœæ,
    //któr¹ za chwilê przyjmie w³aœciwoœæ BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);


public:
    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    //Metoda obs³uguj¹ca reakcjê na up³yw czasu
    virtual void Tick();

    CSomething();
    virtual ~CSomething();
};

#endif // CSOMETHING_H
