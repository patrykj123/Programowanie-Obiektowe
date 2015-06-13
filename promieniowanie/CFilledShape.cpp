#include "CFilledShape.h"
#include "Utils.h"
#include <math.h>

//**** Property access methods ****

//Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci LineColor.
//Logiczna w�a�ciwo�� LineColor reprezentuje kolor linii obiektu graficznego.
COLORREF CFilledShape::getLineColor()
{
    return mLineColor;
}

void CFilledShape::setLineColor(COLORREF aLineColor)
{
    mLineColor = aLineColor;
    DeleteObject(mPen);
    mPen = CreatePen(PS_INSIDEFRAME, mLineWidth, mLineColor);
}


//Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci LineWidth.
//Logiczna w�a�ciwo�� LineWidth reprezentuje grubo�� linii obiektu graficznego w pikselach.
int CFilledShape::getLineWidth()
{
    return mLineWidth;
}

void CFilledShape::setLineWidth(int aLineWidth)
{
    mLineWidth = aLineWidth;
    DeleteObject(mPen);
    mPen = CreatePen(PS_INSIDEFRAME, mLineWidth, mLineColor);
}


//Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci FillColor.
//Logiczna w�a�ciwo�� FillColor reprezentuje kolor wype�nienia obiektu graficznego.
COLORREF CFilledShape::getFillColor()
{
    return mFillColor;
}

void CFilledShape::setFillColor(COLORREF aFillColor)
{
    mFillColor = aFillColor;
    DeleteObject(mBrush);
    mBrush = CreateSolidBrush(mFillColor);
}


//Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci ColorChangeStep.
//Logiczna w�a�ciwo�� ColorChangeStep reprezentuje maksymaln� liczb�,
//o kt�r� mog� si� zmieni� sk�adowe koloru (R, G, B)
//w warto�ciach w�a�ciwo�ci LineColor i FillColor w jednym takcie zegara.
int CFilledShape::getColorChangeStep()
{
    return mColorChangeStep;
}

void CFilledShape::setColorChangeStep(int aColorChangeStep)
{
    mColorChangeStep = abs(aColorChangeStep);
}



//********** Public methods ***********

//Metoda obs�uguj�ca rysowanie obiektu graficznego.
//Metoda zwalnia klasy pochodne z obs�ugi pi�r i p�dzli podczas rysowania.
//Metoda wywo�uje wirtualn� metod� implementuj�c� rysowanie w klasach pochodnych (metoda doPaint).
void CFilledShape::Paint(HDC hdc)
{
    HPEN oldPen;
    HBRUSH oldBrush;
    const RECT& boundingRect = getBoundingRect();

    //DrawFocusRect(hdc, &boundingRect);

    oldPen = (HPEN)SelectObject(hdc, mPen);
    oldBrush = (HBRUSH)SelectObject(hdc, mBrush);

    doPaint(hdc);

    SelectObject(hdc, oldPen);
    SelectObject(hdc, oldBrush);
}

//Metoda obs�uguj�ca reakcj� na up�yw czasu
void CFilledShape::Tick()
{
    //Wywo�anie dziedziczonej wersji metody
    CShape::Tick();

    if(mColorChangeStep)
    {
        int rVal, gVal, bVal;

        //******* Modyfikacja koloru linii *******
        rVal = GetRValue(mLineColor) + RandRange(-mColorChangeStep, mColorChangeStep);
        if(rVal < 0) rVal = 0;
        else if(rVal > 255) rVal = 255;

        gVal = GetGValue(mLineColor) + RandRange(-mColorChangeStep, mColorChangeStep);
        if(gVal < 0) gVal = 0;
        else if(gVal > 255) gVal = 255;

        bVal = GetBValue(mLineColor) + RandRange(-mColorChangeStep, mColorChangeStep);
        if(bVal < 0) bVal = 0;
        else if(bVal > 255) bVal = 255;

        setLineColor(RGB(rVal, gVal, bVal));

        //******* Modyfikacja koloru wype�nienia *******
        rVal = GetRValue(mFillColor) + RandRange(-mColorChangeStep, mColorChangeStep);
        if(rVal < 0) rVal = 0;
        else if(rVal > 255) rVal = 255;

        gVal = GetGValue(mFillColor) + RandRange(-mColorChangeStep, mColorChangeStep);
        if(gVal < 0) gVal = 0;
        else if(gVal > 255) gVal = 255;

        bVal = GetBValue(mFillColor) + RandRange(-mColorChangeStep, mColorChangeStep);
        if(bVal < 0) bVal = 0;
        else if(bVal > 255) bVal = 255;

        setFillColor(RGB(rVal, gVal, bVal));
    }
}


//**** Constructors & destructor ****

//Konstruktor ustawia wszystkie pola klasy na warto�ci pocz�tkowe w taki spos�b, �eby zachowa� sp�jno�� obiektu.
CFilledShape::CFilledShape()
{
    mLineColor = RGB(0, 0, 255);
    mLineWidth = 3;
    mFillColor = RGB(255, 255, 0);
    mPen = CreatePen(PS_INSIDEFRAME, mLineWidth, mLineColor);
    mBrush = CreateSolidBrush(mFillColor);

    mColorChangeStep = 0;
}

CFilledShape::~CFilledShape()
{
    DeleteObject(mPen);
    DeleteObject(mBrush);
}
