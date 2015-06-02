#ifndef CSHAPE_H
#define CSHAPE_H

#include <windows.h>

class CShape
{
private:
    //Sk�adowa mBoundingRect przechowuje warto�� logicznej w�a�ciwo�ci BoundingRect;
    RECT mBoundingRect;

    //Sk�adowa mSizeChangeStep przechowuje warto�� logicznej w�a�ciwo�ci SizeChangeStep;
    int mSizeChangeStep;

protected:
    //Wyzwalacz (trigger) wywo�ywany tu� przed zmian� w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zmodyfikowa� warto��,
    //kt�r� za chwil� przyjmie w�a�ciwo�� BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);

    //Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zareagowa� na zmian� w�a�ciwo�ci BoundingRect.
    virtual void afterBoundingRectChange();

public:
    //**** Property access methods ****

    //Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci BoundingRect.
    //Logiczna w�a�ciwo�� BoundingRect reprezentuje prostok�t opisany na figurze (minimalne i maksymalne wsp�rz�dne x i y, kt�re zajmuje figura).
    //Zak�adamy, �e zaraz po utworzeniu obiekt ma rozmiar zerowy (prostok�t opisany na figurze ma wszystkie pola wyzerowane).
    const RECT& getBoundingRect();
    void setBoundingRect(RECT aBoundingRect);

    //Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci SizeChangeStep.
    //Logiczna w�a�ciwo�� SizeChangeStep ustawia maksymaln� warto��, o kt�r�
    //b�d� si� zmienia�y wsp�rz�dne prostok�ta opisanego na figurze (BoundingRect)
    //w jednym takcie zegara.
    int getSizeChangeStep();
    void setSizeChangeStep(int aSizeChangeStep);

    //**** Public methods ****

    //Metoda obs�uguj�ca rysowanie obiektu graficznego.
    virtual void Paint(HDC hdc) = 0;

    //Metoda obs�uguj�ca reakcj� na up�yw czasu
    virtual void Tick();

    //**** Constructors & destructor ****
    CShape();
    virtual ~CShape();

};


#endif // CSHAPE_H
