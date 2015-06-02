#ifndef CELLIPSE_H
#define CELLIPSE_H

#include <windows.h>
#include "CFilledShape.h"

class CEllipse : public CFilledShape
{
protected:
    //Metoda wykonuj¹ca rysowanie (bez koniecznoœci obs³ugi piór i pêdzli).
    virtual void doPaint(HDC hdc);
};

#endif // CELLIPSE_H
