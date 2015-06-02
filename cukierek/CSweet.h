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
    //Wyzwalacz (trigger) wywo³ywany tu¿ przed zmian¹ w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zmodyfikowaæ wartoœæ,
    //któr¹ za chwilê przyjmie w³aœciwoœæ BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);

public:
    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    //Metoda obs³uguj¹ca reakcjê na up³yw czasu
    virtual void Tick();
    CSweet();
    virtual ~CSweet();
};

#endif // CSWEET_H
