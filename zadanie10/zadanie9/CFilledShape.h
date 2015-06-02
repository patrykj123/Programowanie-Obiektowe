#ifndef CFILLEDSHAPE_H
#define CFILLEDSHAPE_H

#include <windows.h>

class CFilledShape
{
private:
    //Sk³adowa mBoundingRect przechowuje wartoœæ logicznej w³aœciwoœci BoundingRect;
    RECT mBoundingRect;

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

protected:
    //Wyzwalacz (trigger) wywo³ywany tu¿ przed zmian¹ w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zmodyfikowaæ wartoœæ,
    //któr¹ za chwilê przyjmie w³aœciwoœæ BoundingRect (argument jest przekazywany przez adres).
    virtual void beforeBoundingRectChange(RECT* newBoundingRect);

    //Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
    //Klasa pochodna reimplementuj¹ca tê metodê mo¿e zareagowaæ na zmianê w³aœciwoœci BoundingRect.
    virtual void afterBoundingRectChange();

    //Metoda wykonuj¹ca rysowanie. Tutaj (na poziomie CFilledShape) jest to metoda abstrakcyjna.
    //Klasa pochodna reimplementuj¹ca tê metodê powinna w tej metodzie wykonywaæ rysowanie.
    virtual void doPaint(HDC hdc) = 0;

public:
    //**** Property access methods ****

    //Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci BoundingRect.
    //Logiczna w³aœciwoœæ BoundingRect reprezentuje prostok¹t opisany na figurze (minimalne i maksymalne wspó³rzêdne x i y, które zajmuje figura).
    //Zak³adamy, ¿e zaraz po utworzeniu obiekt ma rozmiar zerowy (prostok¹t opisany na figurze ma wszystkie pola wyzerowane).
    const RECT& getBoundingRect();
    void setBoundingRect(RECT aBoundingRect);

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

    //**** Public methods ****

    //Metoda obs³uguj¹ca rysowanie obiektu graficznego.
    //Metoda zwalnia klasy pochodne z obs³ugi piór i pêdzli podczas rysowania.
    //Metoda wywo³uje wirtualn¹ metodê implementuj¹c¹ rysowanie w klasach pochodnych (metoda doPaint).
    void Paint(HDC hdc);

    //**** Constructors & destructor ****
    CFilledShape();
    virtual ~CFilledShape();

};

#endif // CFILLEDSHAPE_H
