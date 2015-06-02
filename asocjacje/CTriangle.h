#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include <windows.h>
#include "CAbstractTriangle.h"

class CTriangle : public CAbstractTriangle
{
private:
    //Deklaracja typu strukturalnego reprezentuj�cego wsp�rz�dne punktu przechowywane
    //w formacie zmiennoprzecinkowym. Typ jest prywatny dla klasy CTriangle
    struct SFloatPoint
    {
        float x;
        float y;
    };

    //Tablica przechowuj�ce proporcje poszczeg�lnych wierzcho�k�w w stosunku do szeroko�ci i wysoko�ci BoundingRect
    SFloatPoint mVertProportions[3];

    //Flaga wskazuj�ca czy wierzcho�ki zosta�y zaktualizowane
    bool mVerticesUpdated;


    int mVertChangeStep;

    //Metoda aktualizuj�ca warto�� w�a�ciwo�ci BoundingRect na podstawie wierzcho�k�w
    void updateBoundingRect();

    //Metoda aktualizuj�ca proporcje poszczeg�lnych wierzcho�k�w w stosunku do szeroko�ci i wysoko�ci BoundingRect
    void updateVertProportions();

protected:
    //Metoda s�u��ca do przeliczenia wierzcho�k�w na podstawie aktualnego prostok�ta opisanego na figurze (w�a�ciwo�� BoundingRect).
    virtual void updateVertices();

    //Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
    //Klasa CTriangle musi zareagowa� na zmian� w�a�ciwo�ci BoundingRect aktualizacj� wierzcho�k�w tr�jk�ta.
    virtual void afterBoundingRectChange();

public:
    //Metody obs�uguj�ce w�a�ciwo�� Vertices (getter jest przeci��ony - ma dwie wersje)
    const POINT* getVertices();
    void getVertices(POINT* aVertices);
    void setVertices(const POINT aVertices[]);

    //Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci VertChangeStep.
    //Logiczna w�a�ciwo�� VertChangeStep ustawia maksymaln� warto��, o kt�r�
    //b�d� si� zmienia�y wsp�rz�dne wierzcho�k�w tr�jk�ta w jednym takcie zegara.
    int getVertChangeStep();
    void setVertChangeStep(int aVertChangeStep);

    //Metoda obs�uguj�ca reakcj� na up�yw czasu
    virtual void Tick();


    CTriangle();
};

#endif // CTRIANGLE_H
