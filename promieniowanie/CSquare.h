#ifndef CSQUARE_H
#define CSQUARE_H

#include <windows.h>
#include "Utils.h"
#include "CRectangle.h"

class CSquare : public CRectangle
{
private:
    //Metoda prywatna s³u¿¹ca do przeliczenia prostok¹ta opisanego na figurze (w³aœciwoœæ BoundingRect) w taki sposób, ¿eby figura by³a foremna.
    //Metoda modyfikuje wartoœæ nowego prostok¹ta (argument przekazywany przez adres).
    void updateBoundingRect(RECT* newBoundingRect);

protected:
    //Wyzwalacz (trigger) wywo³ywany tu¿ przed zmian¹ w³aœciwoœci BoundingRect.
    //Klasa CSquare modyfikuje wartoœæ, któr¹ za chwilê przyjmie w³aœciwoœæ BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);
};

#endif // CSQUARE_H
