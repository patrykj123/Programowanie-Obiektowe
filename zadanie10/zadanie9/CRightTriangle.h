#ifndef CRIGHTTRIANGLE_H
#define CRIGHTTRIANGLE_H

#include "CAbstractTriangle.h"

class CRightTriangle : public CAbstractTriangle
{
    //Metoda s³u¿¹ca do przeliczenia wierzcho³ków na podstawie aktualnego prostok¹ta opisanego na figurze (w³aœciwoœæ BoundingRect).
    virtual void updateVertices();
};

#endif // CRIGHTTRIANGLE_H
