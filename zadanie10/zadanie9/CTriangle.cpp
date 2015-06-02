#include "CTriangle.h"


//public
void CTriangle::setVertices(POINT aVertices[]){
    for(int i = 0; i < 3; i++){
        mVertices[i].x = aVertices[i].x;
        mVertices[i].y = aVertices[i].y;
    }
    setMinAndMaxHeight();
    uptadeRect();
}

//prtotected
void CTriangle::updateVertices(){
    const RECT& boundingRect = getBoundingRect();
    int width = boundingRect.right - boundingRect.left;
    int height = boundingRect.bottom - boundingRect.top;
    mVertices[0].x = boundingRect.left;
    mVertices[0].y = boundingRect.top + (mVerticalProp[0] * height);
    mVertices[1].x = boundingRect.left + (mHorizontalProp[1] * width);
    mVertices[1].y = boundingRect.top + (mVerticalProp[1] * height);
    mVertices[2].x = boundingRect.right;
    mVertices[2].y = boundingRect.top + (mVerticalProp[2] * height);
}

void CTriangle::uptadeRect(){
    RECT newBoundingRect;
    newBoundingRect.left = mVertices[0].x;
    newBoundingRect.right = mVertices[2].x;
    newBoundingRect.top = m_MinHeight;
    newBoundingRect.bottom = m_MaxHeight;
    setPropOfCenterVertex(newBoundingRect);
    setPropOfLeftVertex(newBoundingRect);
    setPropOfRightVertex(newBoundingRect);
    setBoundingRect(newBoundingRect);
}

//private
void CTriangle::setMinAndMaxHeight(){
    for(int i = 0; i < 3; i++){
        if(mVertices[i].y > m_MaxHeight)
            m_MaxHeight = mVertices[i].y;
        if(mVertices[i].y < m_MinHeight)
            m_MinHeight = mVertices[i].y;
    }
}

void CTriangle::setPropOfCenterVertex(RECT boundingRect){
    double triangleWidth = boundingRect.right - boundingRect.left;
    double vertexWidth = mVertices[1].x - boundingRect.left;
    double triangleHeight = boundingRect.bottom - boundingRect.top;
    double vertexHeight = mVertices[1].y - boundingRect.top;
    mHorizontalProp[1] = vertexWidth / triangleWidth;
    mVerticalProp[1] = vertexHeight / triangleHeight;
}

void CTriangle::setPropOfLeftVertex(RECT boundingRect){
    double triangleHeight = boundingRect.bottom - boundingRect.top;
    double vertexHeight = mVertices[0].y - boundingRect.top;
    mVerticalProp[0] = vertexHeight / triangleHeight;
}

void CTriangle::setPropOfRightVertex(RECT boundingRect){
    double triangleHeight = boundingRect.bottom - boundingRect.top;
    double vertexHeight = mVertices[2].y - boundingRect.top;
    mVerticalProp[2] = vertexHeight / triangleHeight;
}

CTriangle::CTriangle()
{
    m_MinHeight = 99999999;
    m_MaxHeight = 0;
    mHorizontalProp[1] = 0.5;
    mVerticalProp[1] = 0;
}

