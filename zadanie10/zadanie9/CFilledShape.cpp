#include "CFilledShape.h"
#include "Utils.h"


//********* Protected methods *********

//Wyzwalacz (trigger) wywo�ywany tu� przed zmian� w�a�ciwo�ci BoundingRect.
//Klasa pochodna reimplementuj�ca t� metod� mo�e zmodyfikowa� warto��,
//kt�r� za chwil� przyjmie w�a�ciwo�� BoundingRect (argument jest przekazywany przez adres).
void CFilledShape::beforeBoundingRectChange(RECT* newBoundingRect)
{
}

//Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
//Klasa pochodna reimplementuj�ca t� metod� mo�e zareagowa� na zmian� w�a�ciwo�ci BoundingRect.
void CFilledShape::afterBoundingRectChange()
{
}

//**** Property access methods ****

//Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci BoundingRect.
//Logiczna w�a�ciwo�� BoundingRect reprezentuje prostok�t opisany na figurze (minimalne i maksymalne wsp�rz�dne x i y, kt�re zajmuje figura).
//Zak�adamy, �e zaraz po utworzeniu obiekt ma rozmiar zerowy (prostok�t opisany na figurze ma wszystkie pola wyzerowane).
const RECT& CFilledShape::getBoundingRect()
{
    return mBoundingRect;
}

void CFilledShape::setBoundingRect(RECT aBoundingRect)
{
    CorrectRect(&aBoundingRect);
    beforeBoundingRectChange(&aBoundingRect);
    CorrectRect(&aBoundingRect);
    mBoundingRect = aBoundingRect;
    afterBoundingRectChange();
}


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
    mPen = CreatePen(PS_SOLID, mLineWidth, mLineColor);
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
    mPen = CreatePen(PS_SOLID, mLineWidth, mLineColor);
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



//********** Public methods ***********

//Metoda obs�uguj�ca rysowanie obiektu graficznego.
//Metoda zwalnia klasy pochodne z obs�ugi pi�r i p�dzli podczas rysowania.
//Metoda wywo�uje wirtualn� metod� implementuj�c� rysowanie w klasach pochodnych (metoda doPaint).
void CFilledShape::Paint(HDC hdc)
{
    HPEN oldPen;
    HBRUSH oldBrush;

    oldPen = (HPEN)SelectObject(hdc, mPen);
    oldBrush = (HBRUSH)SelectObject(hdc, mBrush);

    doPaint(hdc);

    SelectObject(hdc, oldPen);
    SelectObject(hdc, oldBrush);
}



//**** Constructors & destructor ****

//Konstruktor ustawia wszystkie pola klasy na warto�ci pocz�tkowe w taki spos�b, �eby zachowa� sp�jno�� obiektu.
CFilledShape::CFilledShape()
{
    //Zak�adamy, �e zaraz po utworzeniu obiekt ma rozmiar i po�o�enie zerowe (prostok�t opisany na figurze ma wszystkie pola wyzerowane).
    mBoundingRect.left = 0;
    mBoundingRect.top = 0;
    mBoundingRect.right = 0;
    mBoundingRect.bottom = 0;

    mLineColor = RGB(0, 0, 255);
    mLineWidth = 3;
    mFillColor = RGB(255, 255, 0);
    mPen = CreatePen(PS_SOLID, mLineWidth, mLineColor);
    mBrush = CreateSolidBrush(mFillColor);
}

CFilledShape::~CFilledShape()
{
    DeleteObject(mPen);
    DeleteObject(mBrush);
}
