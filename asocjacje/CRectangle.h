#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include <windows.h>
#include "CFilledShape.h"

class CRectangle : public CFilledShape
{
protected:
    //Metoda wykonuj�ca rysowanie (bez konieczno�ci obs�ugi pi�r i p�dzli).
    virtual void doPaint(HDC hdc);
};

#endif // CRECTANGLE_H
