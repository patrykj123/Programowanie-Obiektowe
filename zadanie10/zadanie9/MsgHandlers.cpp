#include "MsgHandlers.h"
#include "Utils.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "CRectangle.h"
#include "CEllipse.h"
#include "CCircle.h"
#include "CSquare.h"
#include "CRightTriangle.h"
#include "CTriangle.h"
#include "CIsoscelesTriangle.h"
#include "CEquilateralTriangle.h"

/************************ Zmienne globalne ************************/

int ClientWidth, ClientHeight;
BOOL EraseBkgnd = TRUE;
RECT MouseRect;

bool InDrawState = false;

const int NumOfFilledShapes = 1;
CFilledShape* FilledShapes[NumOfFilledShapes];

int CurrDrawnShapeIdx = 0;

/******************** Procedury obs�ugi zdarze� ********************/

//Procedura wywo�ywana przed pokazaniem okna (na pocz�tku dzia�ania programu).
//Tutaj mo�na przeprowadzi� pocz�tkow� inicjalizacj� zmiennych, obiekt�w itp.
void OnCreate(HWND hwnd)
{
    int shapeType;

    srand(time(NULL));

    for(int i=0; i<NumOfFilledShapes; i++)
    {
        shapeType = RandRange(8,8);

        switch(shapeType)
        {
        case 1: //prostok�t
            FilledShapes[i] = new CRectangle;
            break;
        case 2: //elipsa
            FilledShapes[i] = new CEllipse;
            break;
        case 3: //k�ko
            FilledShapes[i] = new CCircle;
            break;
        case 4: //kwadrat
            FilledShapes[i] = new CSquare;
            break;
        case 5: //tr�jk�t r�wnoramienny
            FilledShapes[i] = new CIsoscelesTriangle;
            break;
        case 6: //tr�jk�t r�wnoboczny
            FilledShapes[i] = new CEquilateralTriangle;
            break;
        case 7: //tr�jk�t prostok�tny
            FilledShapes[i] = new CRightTriangle;
            break;
        case 8:
            POINT point[3];
            point[0].x = 50;
            point[0].y = 100;
            point[1].x = 150;
            point[1].y = 150;
            point[2].x = 200;
            point[2].y = 300;
            FilledShapes[i] = new CTriangle;
            ((CTriangle * ) FilledShapes[i])->setVertices(point);
            break;

        }

        FilledShapes[i]->setLineColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
        FilledShapes[i]->setFillColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
        FilledShapes[i]->setLineWidth(RandRange(0,15));
    }

    SetTimer(hwnd, 1, 50, NULL);
}


//Procedura wywo�ywana po ka�dej zmianie rozmiaru okna
void OnSize(HWND hwnd, int width, int height, WPARAM wParam)
{
    RECT tmpRect;

    ClientWidth = width;
    ClientHeight = height;

    tmpRect.left = width * .25;
    tmpRect.top = height * .25;
    tmpRect.right = width * .75;
    tmpRect.bottom = height * .75;

    for(int i=0; i<NumOfFilledShapes; i++)
        FilledShapes[i]->setBoundingRect(tmpRect);

    InvalidateRect(hwnd, NULL, EraseBkgnd);
}


//Procedura wywo�ywana co 25 ms (czas ustawia si� trzecim argumentem
// funkcji SetTimer() wywo�ywanej w OnCreate).
void OnTimer(HWND hwnd, WPARAM timerID)
{
    RECT tmpRect;
    const int sizeChangeStep = 5;

    COLORREF tmpColor;
    int rVal, gVal, bVal;
    const int colorChangeStep = 5;

    if(InDrawState) return;

    for(int i=0; i<NumOfFilledShapes; i++)
    {
        //******* Modyfikacja rozmiar�w figury *******
        tmpRect = FilledShapes[i]->getBoundingRect();

        tmpRect.left += RandRange(-sizeChangeStep, sizeChangeStep);
        tmpRect.top += RandRange(-sizeChangeStep, sizeChangeStep);
        tmpRect.right += RandRange(-sizeChangeStep, sizeChangeStep);
        tmpRect.bottom += RandRange(-sizeChangeStep, sizeChangeStep);

        FilledShapes[i]->setBoundingRect(tmpRect);

        //******* Modyfikacja koloru linii *******
        tmpColor = FilledShapes[i]->getLineColor();

        rVal = GetRValue(tmpColor) + RandRange(-colorChangeStep, colorChangeStep);
        if(rVal < 0) rVal = 0;
        else if(rVal > 255) rVal = 255;

        gVal = GetGValue(tmpColor) + RandRange(-colorChangeStep, colorChangeStep);
        if(gVal < 0) gVal = 0;
        else if(gVal > 255) gVal = 255;

        bVal = GetBValue(tmpColor) + RandRange(-colorChangeStep, colorChangeStep);
        if(bVal < 0) bVal = 0;
        else if(bVal > 255) bVal = 255;

        FilledShapes[i]->setLineColor(RGB(rVal, gVal, bVal));

        //******* Modyfikacja koloru wype�nienia *******
        tmpColor = FilledShapes[i]->getFillColor();

        rVal = GetRValue(tmpColor) + RandRange(-colorChangeStep, colorChangeStep);
        if(rVal < 0) rVal = 0;
        else if(rVal > 255) rVal = 255;

        gVal = GetGValue(tmpColor) + RandRange(-colorChangeStep, colorChangeStep);
        if(gVal < 0) gVal = 0;
        else if(gVal > 255) gVal = 255;

        bVal = GetBValue(tmpColor) + RandRange(-colorChangeStep, colorChangeStep);
        if(bVal < 0) bVal = 0;
        else if(bVal > 255) bVal = 255;

        FilledShapes[i]->setFillColor(RGB(rVal, gVal, bVal));
    }

    InvalidateRect(hwnd, NULL, EraseBkgnd);
}


//Procedura wywo�ywana w celu od�wie�enia zawarto�ci okna.
//Wy��cznie tutaj powinno si� przeprowadza� rysowanie.
void OnPaint(HWND hwnd, HDC hdc)
{
    if(InDrawState)
        DrawFocusRect(hdc, &MouseRect);

    for(int i=0; i<NumOfFilledShapes; i++)
        FilledShapes[i]->Paint(hdc);
}


//Procedura wywo�ywana po naci�ni�ciu klawisza klawiatury.
void OnKeyDown(HWND hwnd, WPARAM keyCode)
{
    switch (keyCode)
    {
    case VK_LEFT:
        break;
    case VK_UP:
        break;
    case VK_RIGHT:
        break;
    case VK_DOWN:
        break;
    case 0x43: //klawisz C
        break;
    case 0x45: //klawisz E
        EraseBkgnd ^= 0x00000001;
        break;
    case 0x52: //klawisz R
        break;
    case 0x53: //klawisz S
        break;
    }
    //InvalidateRect(hwnd, NULL, EraseBkgnd);
}


//Procedura wywo�ywana po poruszeniu wska�nika myszy.
void OnMouseMove(HWND hwnd, int x, int y, WPARAM wParam)
{
    if(InDrawState)
    {
        MouseRect.right = x;
        MouseRect.bottom = y;
        FilledShapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);

        InvalidateRect(hwnd, NULL, EraseBkgnd);
    }
}


//Procedura wywo�ywana po naci�ni�ciu lewego przycisku myszy.
void OnLButtonDown(HWND hwnd, int x, int y, WPARAM wParam)
{
    if(!InDrawState)
    {
        MouseRect.left = x;
        MouseRect.top = y;
        MouseRect.right = x;
        MouseRect.bottom = y;
        FilledShapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);

        InDrawState = true;
        SetCapture(hwnd);
    }
}


//Procedura wywo�ywana po zwolnieniu lewego przycisku myszy.
void OnLButtonUp(HWND hwnd, int x, int y, WPARAM wParam)
{
    if(InDrawState)
    {
        MouseRect.right = x;
        MouseRect.bottom = y;
        FilledShapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);
        CurrDrawnShapeIdx = (CurrDrawnShapeIdx + 1) % NumOfFilledShapes;

        InDrawState = false;
        ReleaseCapture();
        InvalidateRect(hwnd, NULL, EraseBkgnd);
    }
}


//Procedura wywo�ywana przed zniszczeniem okna (przed ko�cem dzia�ania programu).
//Tutaj mo�na zwolni� zaalokowane zasoby.
void OnDestroy(HWND hwnd)
{
    KillTimer(hwnd, 1);

    for(int i=0; i<NumOfFilledShapes; i++)
        delete FilledShapes[i];
}

















