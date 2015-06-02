#ifndef CISOSCELESTRIANGLE_H
#define CISOSCELESTRIANGLE_H

#include "CAbstractTriangle.h"

class CIsoscelesTriangle : public CAbstractTriangle
{
    //Metoda służąca do przeliczenia wierzchołków na podstawie aktualnego prostokąta opisanego na figurze (właściwość BoundingRect).
    virtual void updateVertices();
};

#endif // CISOSCELESTRIANGLE_H
