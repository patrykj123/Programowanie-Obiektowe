#include "CFilledShape.h"
#include "Utils.h"


//********* Protected methods *********

//Wyzwalacz (trigger) wywo³ywany tu¿ przed zmian¹ w³aœciwoœci BoundingRect.
//Klasa pochodna reimplementuj¹ca tê metodê mo¿e zmodyfikowaæ wartoœæ,
//któr¹ za chwilê przyjmie w³aœciwoœæ BoundingRect (argument jest przekazywany przez adres).
void CFilledShape::beforeBoundingRectChange(RECT* newBoundingRect)
{
}

//Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
//Klasa pochodna reimplementuj¹ca tê metodê mo¿e zareagowaæ na zmianê w³aœciwoœci BoundingRect.
void CFilledShape::afterBoundingRectChange()
{
}

//**** Property access methods ****

//Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci BoundingRect.
//Logiczna w³aœciwoœæ BoundingRect reprezentuje prostok¹t opisany na figurze (minimalne i maksymalne wspó³rzêdne x i y, które zajmuje figura).
//Zak³adamy, ¿e zaraz po utworzeniu obiekt ma rozmiar zerowy (prostok¹t opisany na figurze ma wszystkie pola wyzerowane).
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
    mPen = CreatePen(PS_SOLID, mLineWidth, mLineColor);
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
    mPen = CreatePen(PS_SOLID, mLineWidth, mLineColor);
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



//********** Public methods ***********

//Metoda obs³uguj¹ca rysowanie obiektu graficznego.
//Metoda zwalnia klasy pochodne z obs³ugi piór i pêdzli podczas rysowania.
//Metoda wywo³uje wirtualn¹ metodê implementuj¹c¹ rysowanie w klasach pochodnych (metoda doPaint).
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

//Konstruktor ustawia wszystkie pola klasy na wartoœci pocz¹tkowe w taki sposób, ¿eby zachowaæ spójnoœæ obiektu.
CFilledShape::CFilledShape()
{
    //Zak³adamy, ¿e zaraz po utworzeniu obiekt ma rozmiar i po³o¿enie zerowe (prostok¹t opisany na figurze ma wszystkie pola wyzerowane).
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
