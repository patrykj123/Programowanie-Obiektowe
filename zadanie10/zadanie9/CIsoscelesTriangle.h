#ifndef CISOSCELESTRIANGLE_H
#define CISOSCELESTRIANGLE_H

#include "CAbstractTriangle.h"

class CIsoscelesTriangle : public CAbstractTriangle
{
    //Metoda s�u��ca do przeliczenia wierzcho�k�w na podstawie aktualnego prostok�ta opisanego na figurze (w�a�ciwo�� BoundingRect).
    virtual void updateVertices();
};

#endif // CISOSCELESTRIANGLE_H
