#ifndef CRIGHTTRIANGLE_H
#define CRIGHTTRIANGLE_H

#include "CAbstractTriangle.h"

class CRightTriangle : public CAbstractTriangle
{
protected:
    //Metoda s�u��ca do przeliczenia wierzcho�k�w na podstawie aktualnego prostok�ta opisanego na figurze (w�a�ciwo�� BoundingRect).
    virtual void updateVertices();
};

#endif // CRIGHTTRIANGLE_H
