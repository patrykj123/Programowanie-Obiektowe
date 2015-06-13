#include "CFilledShape.h"
#include "Utils.h"
#include <math.h>

//**** Property access methods ****

//Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci LineColor.
//Logiczna w³aœciwoœæ LineColor reprezentuje kolor linii obiektu graficznego.
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


//Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci LineWidth.
//Logiczna w³aœciwoœæ LineWidth reprezentuje gruboœæ linii obiektu graficznego w pikselach.
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


//Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci FillColor.
//Logiczna w³aœciwoœæ FillColor reprezentuje kolor wype³nienia obiektu graficznego.
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


//Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci ColorChangeStep.
//Logiczna w³aœciwoœæ ColorChangeStep reprezentuje maksymaln¹ liczbê,
//o któr¹ mog¹ siê zmieniæ sk³adowe koloru (R, G, B)
//w wartoœciach w³aœciwoœci LineColor i FillColor w jednym takcie zegara.
int CFilledShape::getColorChangeStep()
{
    return mColorChangeStep;
}

void CFilledShape::setColorChangeStep(int aColorChangeStep)
{
    mColorChangeStep = abs(aColorChangeStep);
}



//********** Public methods ***********

//Metoda obs³uguj¹ca rysowanie obiektu graficznego.
//Metoda zwalnia klasy pochodne z obs³ugi piór i pêdzli podczas rysowania.
//Metoda wywo³uje wirtualn¹ metodê implementuj¹c¹ rysowanie w klasach pochodnych (metoda doPaint).
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

//Metoda obs³uguj¹ca reakcjê na up³yw czasu
void CFilledShape::Tick()
{
    //Wywo³anie dziedziczonej wersji metody
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

        //******* Modyfikacja koloru wype³nienia *******
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

//Konstruktor ustawia wszystkie pola klasy na wartoœci pocz¹tkowe w taki sposób, ¿eby zachowaæ spójnoœæ obiektu.
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
