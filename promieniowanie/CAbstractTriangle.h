#ifndef CABSTRACTTRIANGLE_H
#define CABSTRACTTRIANGLE_H

#include <windows.h>
#include "CFilledShape.h"

class CAbstractTriangle : public CFilledShape
{
protected:
	//Tablica wierzcho³ków trójk¹ta.
    POINT mVertices[3];

    //Metoda s³u¿¹ca do przeliczenia wierzcho³ków na podstawie aktualnego prostok¹ta opisanego na figurze (w³aœciwoœæ BoundingRect).
    virtual void updateVertices() = 0;

    //Metoda wykonuj¹ca rysowanie (bez koniecznoœci obs³ugi piór i pêdzli).
    virtual void doPaint(HDC hdc);

    //Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
    //Klasa CAbstractTriangle musi zareagowaæ na zmianê w³aœciwoœci BoundingRect aktualizacj¹ wierzcho³ków trójk¹ta.
    virtual void afterBoundingRectChange();

public:
    //**** Constructors & destructor ****
	CAbstractTriangle();
};

#endif // CABSTRACTTRIANGLE_H
