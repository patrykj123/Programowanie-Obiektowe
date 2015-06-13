#include "CShape.h"
#include "Utils.h"
#include <math.h>

//********* Protected methods *********

//Wyzwalacz (trigger) wywo³ywany tu¿ przed zmian¹ w³aœciwoœci BoundingRect.
//Klasa pochodna reimplementuj¹ca tê metodê mo¿e zmodyfikowaæ wartoœæ,
//któr¹ za chwilê przyjmie w³aœciwoœæ BoundingRect (argument jest przekazywany przez adres).
void CShape::beforeBoundingRectChange(RECT* newBoundingRect)
{
}

//Wyzwalacz (trigger) wywo³ywany tu¿ po zmianie w³aœciwoœci BoundingRect.
//Klasa pochodna reimplementuj¹ca tê metodê mo¿e zareagowaæ na zmianê w³aœciwoœci BoundingRect.
void CShape::afterBoundingRectChange()
{
}

//**** Property access methods ****

//Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci BoundingRect.
//Logiczna w³aœciwoœæ BoundingRect reprezentuje prostok¹t opisany na figurze (minimalne i maksymalne wspó³rzêdne x i y, które zajmuje figura).
//Zak³adamy, ¿e zaraz po utworzeniu obiekt ma rozmiar zerowy (prostok¹t opisany na figurze ma wszystkie pola wyzerowane).
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

//Metody obs³uguj¹ce pobieranie i ustawianie logicznej w³aœciwoœci SizeChangeStep.
//Logiczna w³aœciwoœæ SizeChangeStep ustawia maksymaln¹ wartoœæ, o któr¹
//bêd¹ siê zmienia³y wspó³rzêdne prostok¹ta opisanego na figurze (BoundingRect).
int CShape::getSizeChangeStep()
{
    return mSizeChangeStep;
}

void CShape::setSizeChangeStep(int aSizeChangeStep)
{
    mSizeChangeStep = abs(aSizeChangeStep);
}


//**** Public methods ****

//Metoda obs³uguj¹ca reakcjê na up³yw czasu
void CShape::Tick()
{
    if(mSizeChangeStep)
    {
        RECT tmpRect = mBoundingRect;

        //******* Modyfikacja rozmiarów i po³o¿enia figury *******
        tmpRect.left -= RandRange(-mSizeChangeStep, mSizeChangeStep);
        tmpRect.top -= RandRange(-mSizeChangeStep, mSizeChangeStep);
        tmpRect.right += RandRange(-mSizeChangeStep, mSizeChangeStep);
        tmpRect.bottom += RandRange(-mSizeChangeStep, mSizeChangeStep);

        setBoundingRect(tmpRect);
    }
}

//**** Constructors & destructor ****

//Konstruktor ustawia wszystkie pola klasy na wartoœci pocz¹tkowe w taki sposób, ¿eby zachowaæ spójnoœæ obiektu.
CShape::CShape()
{
    //Zak³adamy, ¿e zaraz po utworzeniu obiekt ma rozmiar i po³o¿enie zerowe (prostok¹t opisany na figurze ma wszystkie pola wyzerowane).
    mBoundingRect.left = 0;
    mBoundingRect.top = 0;
    mBoundingRect.right = 0;
    mBoundingRect.bottom = 0;

    mSizeChangeStep = 0;
}

CShape::~CShape()
{
}
