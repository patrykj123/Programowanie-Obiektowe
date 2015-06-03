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
    //Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zareagowaæ na zmianê w³aœciwoœci BoundingRect.
    virtual void afterBoundingRectChange();

public:
    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc);

    //Metoda obs³uguj¹ca reakcjê na up³yw czasu
    virtual void Tick();

    CChequer();
    virtual ~CChequer();
};

#endif // CCHEQUER_H
