#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include <windows.h>
#include "CFilledShape.h"

class CRectangle : public CFilledShape
{
protected:
    //Metoda wykonuj¹ca rysowanie (bez koniecznoœci obs³ugi piór i pêdzli).
    virtual void doPaint(HDC hdc);
};

#endif // CRECTANGLE_H
