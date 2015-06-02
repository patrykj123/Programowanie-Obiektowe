#ifndef CABSTRACTTRIANGLE_H
#define CABSTRACTTRIANGLE_H

#include <windows.h>
#include "CFilledShape.h"

class CAbstractTriangle : public CFilledShape
{
protected:
	//Tablica wierzcho�k�w tr�jk�ta.
    POINT mVertices[3];

    //Metoda s�u��ca do przeliczenia wierzcho�k�w na podstawie aktualnego prostok�ta opisanego na figurze (w�a�ciwo�� BoundingRect).
    virtual void updateVertices() = 0;

    //Metoda wykonuj�ca rysowanie (bez konieczno�ci obs�ugi pi�r i p�dzli).
    virtual void doPaint(HDC hdc);

    //Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
    //Klasa CAbstractTriangle musi zareagowa� na zmian� w�a�ciwo�ci BoundingRect aktualizacj� wierzcho�k�w tr�jk�ta.
    virtual void afterBoundingRectChange();

public:
    //**** Constructors & destructor ****
	CAbstractTriangle();
};

#endif // CABSTRACTTRIANGLE_H
