#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include <windows.h>
#include "CAbstractTriangle.h"

class CTriangle : public CAbstractTriangle
{
private:
    //Deklaracja typu strukturalnego reprezentuj¹cego wspó³rzêdne punktu przechowywane
    //w formacie zmiennoprzecinkowym. Typ jest prywatny dla klasy CTriangle
    struct SFloatPoint
    {
        float x;
        float y;
    };

    //Tablica przechowuj¹ce proporcje poszczególnych wierzcho³ków w stosunku do szerokoœci i wysokoœci BoundingRect
    SFloatPoint mVertProportions[3];

    //Flaga wskazuj¹ca czy wierzcho³ki zosta³y zaktualizowane
    bool mVerticesUpdated;


    int mVertChangeStep;

    //Metoda aktualizuj¹ca wartoœæ w³aœciwoœci BoundingRect na podstawie wierzcho³ków
    void updateBoundingRect();

    //Metoda aktualizuj¹ca proporcje poszczególnych wierzcho³ków w stosunku do szerokoœci i wysokoœci BoundingRect
    void updateVertProportions();

protected:
    //Metoda s³u¿¹ca do przeliczenia wierzcho³ków na podstawie aktualnego prostok¹ta opisanego na figurze (w³aœciwoœæ BoundingRect).
    virtual void updateVertices();

    //Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
    //Klasa CTriangle musi zareagowaæ na zmianê w³aœciwoœci BoundingRect aktualizacj¹ wierzcho³ków trójk¹ta.
    virtual void afterBoundingRectChange();

public:
    //Metody obs³uguj¹ce w³aœciwoœæ Vertices (getter jest przeci¹¿ony - ma dwie wersje)
    const POINT* getVertices();
    void getVertices(POINT* aVertices);
    void setVertices(const POINT aVertices[]);

    //Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci VertChangeStep.
    //Logiczna w³aœciwoœæ VertChangeStep ustawia maksymaln¹ wartoœæ, o któr¹
    //bêd¹ siê zmienia³y wspó³rzêdne wierzcho³ków trójk¹ta w jednym takcie zegara.
    int getVertChangeStep();
    void setVertChangeStep(int aVertChangeStep);

    //Metoda obs³uguj¹ca reakcjê na up³yw czasu
    virtual void Tick();


    CTriangle();
};

#endif // CTRIANGLE_H
