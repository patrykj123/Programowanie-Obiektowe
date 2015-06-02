#ifndef CREGULARTRIANGLE_H
#define CREGULARTRIANGLE_H

#include <windows.h>
#include "Utils.h"
#include "CTriangle.h"

class CRegularTriangle : public CTriangle
{
private:
    //Metoda prywatna s�u��ca do przeliczenia prostok�ta opisanego na figurze (w�a�ciwo�� BoundingRect) w taki spos�b, �eby figura by�a foremna.
    //Metoda modyfikuje warto�� nowego prostok�ta (argument przekazywany przez adres).
    void updateBoundingRect(RECT* newBoundingRect);

protected:
    //Wyzwalacz (trigger) wywo�ywany tu� przed zmian� w�a�ciwo�ci BoundingRect.
    //Klasa CRegularTriangle modyfikuje warto��, kt�r� za chwil� przyjmie w�a�ciwo�� BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);

};

#endif // CREGULARTRIANGLE_H
