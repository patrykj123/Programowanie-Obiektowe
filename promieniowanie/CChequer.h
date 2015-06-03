#ifndef CCHEQUER_H
#define CCHEQUER_H

#include "CShape.h"
#include "CRectangle.h"

class CChequer : public CShape
{
private:
    CRectangle mLeftTopRect;
    CRectangle mRightTopRect;
    CRectangle mLeftBottomRect;
    CRectangle mRightBottomRect;

protected:
    //Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zareagowa� na zmian� w�a�ciwo�ci BoundingRect.
    virtual void afterBoundingRectChange();

public:
    //Metoda obs�uguj�ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    //Metoda obs�uguj�ca reakcj� na up�yw czasu
    virtual void Tick();

    CChequer();
    virtual ~CChequer();
};

#endif // CCHEQUER_H
