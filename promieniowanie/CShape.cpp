#include "CShape.h"
#include "Utils.h"
#include <math.h>

//********* Protected methods *********

//Wyzwalacz (trigger) wywo�ywany tu� przed zmian� w�a�ciwo�ci BoundingRect.
//Klasa pochodna reimplementuj�ca t� metod� mo�e zmodyfikowa� warto��,
//kt�r� za chwil� przyjmie w�a�ciwo�� BoundingRect (argument jest przekazywany przez adres).
void CShape::beforeBoundingRectChange(RECT* newBoundingRect)
{
}

//Wyzwalacz (trigger) wywo�ywany tu� po zmianie w�a�ciwo�ci BoundingRect.
//Klasa pochodna reimplementuj�ca t� metod� mo�e zareagowa� na zmian� w�a�ciwo�ci BoundingRect.
void CShape::afterBoundingRectChange()
{
}

//**** Property access methods ****

//Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci BoundingRect.
//Logiczna w�a�ciwo�� BoundingRect reprezentuje prostok�t opisany na figurze (minimalne i maksymalne wsp�rz�dne x i y, kt�re zajmuje figura).
//Zak�adamy, �e zaraz po utworzeniu obiekt ma rozmiar zerowy (prostok�t opisany na figurze ma wszystkie pola wyzerowane).
const RECT& CShape::getBoundingRect()
{
    return mBoundingRect;
}

void CShape::setBoundingRect(RECT aBoundingRect)
{
    CorrectRect(&aBoundingRect);
    beforeBoundingRectChange(&aBoundingRect);
    CorrectRect(&aBoundingRect);
    mBoundingRect = aBoundingRect;
    afterBoundingRectChange();
}

//Metody obs�uguj�ce pobieranie i ustawianie logicznej w�a�ciwo�ci SizeChangeStep.
//Logiczna w�a�ciwo�� SizeChangeStep ustawia maksymaln� warto��, o kt�r�
//b�d� si� zmienia�y wsp�rz�dne prostok�ta opisanego na figurze (BoundingRect).
int CShape::getSizeChangeStep()
{
    return mSizeChangeStep;
}

void CShape::setSizeChangeStep(int aSizeChangeStep)
{
    mSizeChangeStep = abs(aSizeChangeStep);
}


//**** Public methods ****

//Metoda obs�uguj�ca reakcj� na up�yw czasu
void CShape::Tick()
{
    if(mSizeChangeStep)
    {
        RECT tmpRect = mBoundingRect;

        //******* Modyfikacja rozmiar�w i po�o�enia figury *******
        tmpRect.left -= RandRange(-mSizeChangeStep, mSizeChangeStep);
        tmpRect.top -= RandRange(-mSizeChangeStep, mSizeChangeStep);
        tmpRect.right += RandRange(-mSizeChangeStep, mSizeChangeStep);
        tmpRect.bottom += RandRange(-mSizeChangeStep, mSizeChangeStep);

        setBoundingRect(tmpRect);
    }
}

//**** Constructors & destructor ****

//Konstruktor ustawia wszystkie pola klasy na warto�ci pocz�tkowe w taki spos�b, �eby zachowa� sp�jno�� obiektu.
CShape::CShape()
{
    //Zak�adamy, �e zaraz po utworzeniu obiekt ma rozmiar i po�o�enie zerowe (prostok�t opisany na figurze ma wszystkie pola wyzerowane).
    mBoundingRect.left = 0;
    mBoundingRect.top = 0;
    mBoundingRect.right = 0;
    mBoundingRect.bottom = 0;

    mSizeChangeStep = 0;
}

CShape::~CShape()
{
}
