#ifndef CELLIPSE_H
#define CELLIPSE_H

#include <windows.h>
#include "CFilledShape.h"

class CEllipse : public CFilledShape
{
protected:
    //Metoda wykonuj�ca rysowanie (bez konieczno�ci obs�ugi pi�r i p�dzli).
    virtual void doPaint(HDC hdc);
};

#endif // CELLIPSE_H
