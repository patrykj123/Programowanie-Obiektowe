#ifndef CISOSCELESTRIANGLE_H
#define CISOSCELESTRIANGLE_H

#include "CAbstractTriangle.h"

class CIsoscelesTriangle : public CAbstractTriangle
{
protected:
    //Metoda s³u¿¹ca do przeliczenia wierzcho³ków na podstawie aktualnego prostok¹ta opisanego na figurze (w³aœciwoœæ BoundingRect).
    virtual void updateVertices();
};

#endif // CISOSCELESTRIANGLE_H
