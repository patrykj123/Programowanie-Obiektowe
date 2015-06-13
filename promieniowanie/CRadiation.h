#ifndef CRADIATION_H
#define CRADIATION_H

#include "CShape.h"
#include "CCircle.h"
#include "CTriangle.h"

class CRadiation : public CShape
{
    private:
        void uptadeTriangles(RECT boundingRect);
        CCircle mCircles[5];
        CTriangle mTriangle[3];
    protected:
    //Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zareagowaæ na zmianê w³aœciwoœci BoundingRect.
        virtual void afterBoundingRectChange();
    public:
    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
        virtual void Paint(HDC hdc);

        //Metoda obs³uguj¹ca reakcjê na up³yw czasu
        virtual void Tick();
            CRadiation();
            virtual ~CRadiation();
};

#endif // CRADIATION_H
