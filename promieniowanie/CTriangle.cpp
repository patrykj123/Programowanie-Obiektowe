#include "CTriangle.h"
#include "Utils.h"
#include <math.h>

void CTriangle::updateBoundingRect()
{
    RECT tmpRect;

    //obliczenie boundingRect na podstawie nowych wierzcho³ków
    tmpRect.left = tmpRect.right = mVertices[0].x;
    tmpRect.top = tmpRect.bottom = mVertices[0].y;

    for(int i=0; i<3; i++)
    {
        if(mVertices[i].x < tmpRect.left) tmpRect.left = mVertices[i].x;
        if(mVertices[i].y < tmpRect.top) tmpRect.top = mVertices[i].y;
        if(mVertices[i].x > tmpRect.right) tmpRect.right = mVertices[i].x;
        if(mVertices[i].y > tmpRect.bottom) tmpRect.bottom = mVertices[i].y;
    }

    //ustawienie mVerticesUpdated
    mVerticesUpdated = true;

    //ustawienie boundingRect
    setBoundingRect(tmpRect);

    //wyczyszczenie mVerticesUpdated
    mVerticesUpdated = false;
}

void CTriangle::updateVertProportions()
{
    float width, height;
    const RECT& boundingRect = getBoundingRect();

    width = boundingRect.right - boundingRect.left;
    height = boundingRect.bottom - boundingRect.top;

    //obliczenie proporcji poszczególnych wierzcho³ków w stosunku do szerokoœci i wysokoœci BoundingRect
    for(int i=0; i<3; i++)
    {
        if(width != 0)
            mVertProportions[i].x = (mVertices[i].x - boundingRect.left) / width;

        if(height != 0)
            mVertProportions[i].y = (mVertices[i].y - boundingRect.top) / height;
    }
}

void CTriangle::updateVertices()
{
    float width, height;
    const RECT& boundingRect = getBoundingRect();

    width = boundingRect.right - boundingRect.left;
    height = boundingRect.bottom - boundingRect.top;

    //obliczenie wierzcho³ków na podstawie bie¿¹cego boundingRect i proporcji
    for(int i=0; i<3; i++)
    {
        mVertices[i].x = mVertProportions[i].x * width + boundingRect.left;
        mVertices[i].y = mVertProportions[i].y * height + boundingRect.top;
    }
}

void CTriangle::afterBoundingRectChange()
{
    if(!mVerticesUpdated) updateVertices();
}

const POINT* CTriangle::getVertices()
{
    return mVertices;
}

void CTriangle::getVertices(POINT* aVertices)
{
    for(int i=0; i<3; i++)
    {
        aVertices[i].x = mVertices[i].x;
        aVertices[i].y = mVertices[i].y;
    }
}

void CTriangle::setVertices(const POINT aVertices[])
{
    //kopiowanie wierzcho³ków
    for(int i=0; i<3; i++)
    {
        mVertices[i].x = aVertices[i].x;
        mVertices[i].y = aVertices[i].y;
    }

    //aktualizacja boundingRect
    updateBoundingRect();

    //aktualizacja proporcji
    updateVertProportions();
}

int CTriangle::getVertChangeStep()
{
    return mVertChangeStep;
}

void CTriangle::setVertChangeStep(int aVertChangeStep)
{
    mVertChangeStep = abs(aVertChangeStep);
}

//Metoda obs³uguj¹ca reakcjê na up³yw czasu
void CTriangle::Tick()
{
    //Wywo³anie dziedziczonej wersji metody
    CAbstractTriangle::Tick();

    if(mVertChangeStep)
    {
        POINT vertices[3];

        getVertices(vertices);
        vertices[0].x += RandRange(-mVertChangeStep, mVertChangeStep);
        vertices[0].y += RandRange(-mVertChangeStep, mVertChangeStep);
        vertices[1].x += RandRange(-mVertChangeStep, mVertChangeStep);
        vertices[1].y += RandRange(-mVertChangeStep, mVertChangeStep);
        vertices[2].x += RandRange(-mVertChangeStep, mVertChangeStep);
        vertices[2].y += RandRange(-mVertChangeStep, mVertChangeStep);
        setVertices(vertices);
    }
}


CTriangle::CTriangle()
{
    mVertProportions[0].x = 0;
    mVertProportions[0].y = 1;
    mVertProportions[1].x = 0.5;
    mVertProportions[1].y = 0;
    mVertProportions[2].x = 1;
    mVertProportions[2].y = 0.5;

    mVerticesUpdated = false;
    mVertChangeStep = 0;
}

