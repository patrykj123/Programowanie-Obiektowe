#ifndef CFILLEDSHAPE_H
#define CFILLEDSHAPE_H

#include <windows.h>

class CFilledShape
{
private:
    //Sk�adowa mBoundingRect przechowuje warto�� logicznej w�a�ciwo�ci BoundingRect;
    RECT mBoundingRect;

    //Sk�adowa mLineColor przechowuje warto�� logicznej w�a�ciwo�ci LineColor;
    COLORREF mLineColor;

    //Sk�adowa mLineWidth przechowuje warto�� logicznej w�a�ciwo�ci LineWidth;
    int mLineWidth;

    //Sk�adowa mFillColor przechowuje warto�� logicznej w�a�ciwo�ci FillColor;
    COLORREF mFillColor;

    //Uchwyt pi�rka GDI. Pi�rko s�u�y do rysowania linii.
    HPEN mPen;

    //Uchwyt p�dzla GDI. P�dzel s�u�y do rysowania wype�nienia.
    HBRUSH mBrush;

protected:
    //Wyzwalacz (trigger) wywo�ywany tu� przed zmian� w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zmodyfikowa� warto��,
    //kt�r� za chwil� przyjmie w�a�ciwo�� BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);

    //Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
    //Klasa pochodna reimplementuj�ca t� metod� mo�e zareagowa� na zmian� w�a�ciwo�ci BoundingRect.
    virtual void afterBoundingRectChange();

    //Metoda wykonuj�ca rysowanie. Tutaj (na poziomie CFilledShape) jest to metoda abstrakcyjna.
    //Klasa pochodna reimplementuj�ca t� metod� powinna w tej metodzie wykonywa� rysowanie.
    virtual void doPaint(HDC hdc) = 0;

public:
    //**** Property access methods ****

    //Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci BoundingRect.
    //Logiczna w�a�ciwo�� BoundingRect reprezentuje prostok�t opisany na figurze (minimalne i maksymalne wsp�rz�dne x i y, kt�re zajmuje figura).
    //Zak�adamy, �e zaraz po utworzeniu obiekt ma rozmiar zerowy (prostok�t opisany na figurze ma wszystkie pola wyzerowane).
    const RECT& getBoundingRect();
    void setBoundingRect(RECT aBoundingRect);

    //Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci LineColor.
    //Logiczna w�a�ciwo�� LineColor reprezentuje kolor linii obiektu graficznego.
    COLORREF getLineColor();
    void setLineColor(COLORREF aLineColor);

    //Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci LineWidth.
    //Logiczna w�a�ciwo�� LineWidth reprezentuje grubo�� linii obiektu graficznego w pikselach.
    int getLineWidth();
    void setLineWidth(int aLineWidth);

    //Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci FillColor.
    //Logiczna w�a�ciwo�� FillColor reprezentuje kolor wype�nienia obiektu graficznego.
    COLORREF getFillColor();
    void setFillColor(COLORREF aFillColor);

    //**** Public methods ****

    //Metoda obs�uguj�ca rysowanie obiektu graficznego.
    //Metoda zwalnia klasy pochodne z obs�ugi pi�r i p�dzli podczas rysowania.
    //Metoda wywo�uje wirtualn� metod� implementuj�c� rysowanie w klasach pochodnych (metoda doPaint).
    void Paint(HDC hdc);

    //**** Constructors & destructor ****
    CFilledShape();
    virtual ~CFilledShape();

};

#endif // CFILLEDSHAPE_H
