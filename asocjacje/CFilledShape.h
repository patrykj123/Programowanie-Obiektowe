#ifndef CFILLEDSHAPE_H
#define CFILLEDSHAPE_H

#include <windows.h>
#include "CShape.h"

class CFilledShape : public CShape
{
private:
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

    //Sk�adowa mColorChangeStep przechowuje warto�� logicznej w�a�ciwo�ci ColorChangeStep;
    int mColorChangeStep;

protected:
    //Metoda wykonuj�ca rysowanie. Tutaj (na poziomie CFilledShape) jest to metoda abstrakcyjna.
    //Klasa pochodna reimplementuj�ca t� metod� powinna w tej metodzie wykonywa� rysowanie.
    virtual void doPaint(HDC hdc) = 0;

public:
    //**** Property access methods ****

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

    //Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci ColorChangeStep.
    //Logiczna w�a�ciwo�� ColorChangeStep reprezentuje maksymaln� liczb�,
    //o kt�r� mog� si� zmieni� sk�adowe koloru (R, G, B)
    //w warto�ciach w�a�ciwo�ci LineColor i FillColor w jednym takcie zegara.
    int getColorChangeStep();
    void setColorChangeStep(int aColorChangeStep);



    //**** Public methods ****

    //Metoda obs�uguj�ca rysowanie obiektu graficznego.
    //Metoda zwalnia klasy pochodne z obs�ugi pi�r i p�dzli podczas rysowania.
    //Metoda wywo�uje wirtualn� metod� implementuj�c� rysowanie w klasach pochodnych (metoda doPaint).
    virtual void Paint(HDC hdc);

    //Metoda obs�uguj�ca reakcj� na up�yw czasu
    virtual void Tick();


    //**** Constructors & destructor ****
    CFilledShape();
    virtual ~CFilledShape();

};

#endif // CFILLEDSHAPE_H
