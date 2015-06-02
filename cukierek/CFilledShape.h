#ifndef CFILLEDSHAPE_H
#define CFILLEDSHAPE_H

#include <windows.h>
#include "CShape.h"

class CFilledShape : public CShape
{
private:
    //Sk³adowa mLineColor przechowuje wartoœæ logicznej w³aœciwoœci LineColor;
    COLORREF mLineColor;

    //Sk³adowa mLineWidth przechowuje wartoœæ logicznej w³aœciwoœci LineWidth;
    int mLineWidth;

    //Sk³adowa mFillColor przechowuje wartoœæ logicznej w³aœciwoœci FillColor;
    COLORREF mFillColor;

    //Uchwyt piórka GDI. Piórko s³u¿y do rysowania linii.
    HPEN mPen;

    //Uchwyt pêdzla GDI. Pêdzel s³u¿y do rysowania wype³nienia.
    HBRUSH mBrush;

    //Sk³adowa mColorChangeStep przechowuje wartoœæ logicznej w³aœciwoœci ColorChangeStep;
    int mColorChangeStep;

protected:
    //Metoda wykonuj¹ca rysowanie. Tutaj (na poziomie CFilledShape) jest to metoda abstrakcyjna.
    //Klasa pochodna reimplementuj¹ca tê metodê powinna w tej metodzie wykonywaæ rysowanie.
    virtual void doPaint(HDC hdc) = 0;

public:
    //**** Property access methods ****

    //Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci LineColor.
    //Logiczna w³aœciwoœæ LineColor reprezentuje kolor linii obiektu graficznego.
    COLORREF getLineColor();
    void setLineColor(COLORREF aLineColor);

    //Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci LineWidth.
    //Logiczna w³aœciwoœæ LineWidth reprezentuje gruboœæ linii obiektu graficznego w pikselach.
    int getLineWidth();
    void setLineWidth(int aLineWidth);

    //Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci FillColor.
    //Logiczna w³aœciwoœæ FillColor reprezentuje kolor wype³nienia obiektu graficznego.
    COLORREF getFillColor();
    void setFillColor(COLORREF aFillColor);

    //Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci ColorChangeStep.
    //Logiczna w³aœciwoœæ ColorChangeStep reprezentuje maksymaln¹ liczbê,
    //o któr¹ mog¹ siê zmieniæ sk³adowe koloru (R, G, B)
    //w wartoœciach w³aœciwoœci LineColor i FillColor w jednym takcie zegara.
    int getColorChangeStep();
    void setColorChangeStep(int aColorChangeStep);



    //**** Public methods ****

    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
    //Metoda zwalnia klasy pochodne z obs³ugi piór i pêdzli podczas rysowania.
    //Metoda wywo³uje wirtualn¹ metodê implementuj¹c¹ rysowanie w klasach pochodnych (metoda doPaint).
    virtual void Paint(HDC hdc);

    //Metoda obs³uguj¹ca reakcjê na up³yw czasu
    virtual void Tick();


    //**** Constructors & destructor ****
    CFilledShape();
    virtual ~CFilledShape();

};

#endif // CFILLEDSHAPE_H
