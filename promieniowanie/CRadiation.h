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
    //Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zareagowa� na zmian� w�a�ciwo�ci BoundingRect.
        virtual void afterBoundingRectChange();
    public:
    //Metoda obs�uguj�ca rysowanie obiektu graficznego.
        virtual void Paint(HDC hdc);

        //Metoda obs�uguj�ca reakcj� na up�yw czasu
        virtual void Tick();
            CRadiation();
            virtual ~CRadiation();
};

#endif // CRADIATION_H
