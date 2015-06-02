#ifndef CCHEQUER_H
#define CCHEQUER_H

#include "CShape.h"
#include "CSquare.h"


class CChequer : public CShape
{
private:
    CSquare mainSquare;
    CSquare mSquare[4];

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

    CChequer();
    virtual ~CChequer();
};

#endif // CCHEQUER_H
