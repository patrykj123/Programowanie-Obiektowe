#ifndef CSHAPE_H
#define CSHAPE_H

#include <windows.h>

class CShape
{
private:
    //Sk³adowa mBoundingRect przechowuje wartoœæ logicznej w³aœciwoœci BoundingRect;
    RECT mBoundingRect;

    //Sk³adowa mSizeChangeStep przechowuje wartoœæ logicznej w³aœciwoœci SizeChangeStep;
    int mSizeChangeStep;

protected:
    //Wyzwalacz (trigger) wywo³ywany tu¿ przed zmian¹ w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zmodyfikowaæ wartoœæ,
    //któr¹ za chwilê przyjmie w³aœciwoœæ BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);

    //Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zareagowaæ na zmianê w³aœciwoœci BoundingRect.
    virtual void afterBoundingRectChange();

public:
    //**** Property access methods ****

    //Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci BoundingRect.
    //Logiczna w³aœciwoœæ BoundingRect reprezentuje prostok¹t opisany na figurze (minimalne i maksymalne wspó³rzêdne x i y, które zajmuje figura).
    //Zak³adamy, ¿e zaraz po utworzeniu obiekt ma rozmiar zerowy (prostok¹t opisany na figurze ma wszystkie pola wyzerowane).
    const RECT& getBoundingRect();
    void setBoundingRect(RECT aBoundingRect);

    //Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci SizeChangeStep.
    //Logiczna w³aœciwoœæ SizeChangeStep ustawia maksymaln¹ wartoœæ, o któr¹
    //bêd¹ siê zmienia³y wspó³rzêdne prostok¹ta opisanego na figurze (BoundingRect)
    //w jednym takcie zegara.
    int getSizeChangeStep();
    void setSizeChangeStep(int aSizeChangeStep);

    //**** Public methods ****

    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc) = 0;

    //Metoda obs³uguj¹ca reakcjê na up³yw czasu
    virtual void Tick();

    //**** Constructors & destructor ****
    CShape();
    virtual ~CShape();

};


#endif // CSHAPE_H
