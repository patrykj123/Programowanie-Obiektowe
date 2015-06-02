#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CAbstractTriangle.h"

class CTriangle : public CAbstractTriangle
{
    private:
        long m_MinHeight, m_MaxHeight;
        double mHorizontalProp[3], mVerticalProp[3];
        void setMinAndMaxHeight();
        void setPropOfCenterVertex(RECT boundingRect);
        void setPropOfLeftVertex(RECT boundingRect);
        void setPropOfRightVertex(RECT boundingRect);
    protected:
        virtual void updateVertices();
        void uptadeRect();
    public:
        CTriangle();
        void setVertices(POINT aVertices[]);
};

#endif // CTRIANGLE_H
