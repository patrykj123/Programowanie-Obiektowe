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
#include "CIsoscelesTriangle.h"
#include "CEquilateralTriangle.h"
#include "CTriangle.h"
#include "CSomething.h"
#include "CChequer.h"
#include "CSweet.h"
#include "CRadiation.h"

/************************ Zmienne globalne ************************/

int ClientWidth, ClientHeight;
BOOL EraseBkgnd = TRUE;
RECT MouseRect;

bool InDrawState = false;

const int NumOfShapes = 1;
CShape* Shapes[NumOfShapes];

int CurrDrawnShapeIdx = 0;

/******************** Procedury obs�ugi zdarze� ********************/

//Procedura wywo�ywana przed pokazaniem okna (na pocz�tku dzia�ania programu).
//Tutaj mo�na przeprowadzi� pocz�tkow� inicjalizacj� zmiennych, obiekt�w itp.
void OnCreate(HWND hwnd)
{
    int shapeType;
    bool isFilledShape;
    //POINT vertices[3];

    srand(time(NULL));

    for(int i=0; i<NumOfShapes; i++)
    {
        shapeType = RandRange(12,12);
        isFilledShape = true;

        switch(shapeType)
        {
        case 1: //prostok�t
            Shapes[i] = new CRectangle;
            break;
        case 2: //elipsa
            Shapes[i] = new CEllipse;
            break;
        case 3: //k�ko
            Shapes[i] = new CCircle;
            break;
        case 4: //kwadrat
            Shapes[i] = new CSquare;
            break;
        case 5: //tr�jk�t r�wnoramienny
            Shapes[i] = new CIsoscelesTriangle;
            break;
        case 6: //tr�jk�t r�wnoboczny
            Shapes[i] = new CEquilateralTriangle;
            break;
        case 7: //tr�jk�t prostok�tny
            Shapes[i] = new CRightTriangle;
            break;
        case 8: //tr�jk�t dowolny
//            vertices[0].x = 10;
//            vertices[0].y = 10;
//            vertices[1].x = 100;
//            vertices[1].y = 50;
//            vertices[2].x = 200;
//            vertices[2].y = 210;
            Shapes[i] = new CTriangle;
//            static_cast<CTriangle*>(Shapes[i])->setVertices(vertices);
            break;
        case 9: //figura z�o�ona
            Shapes[i] = new CSomething;
            isFilledShape = false;
            break;
        case 10: //szachownica
            Shapes[i] = new CChequer;
            isFilledShape = false;
            break;
        case 11: //cukierek
            Shapes[i] = new CSweet;
            isFilledShape = false;
            break;
         case 12: //cukierek
            Shapes[i] = new CRadiation;
            isFilledShape = false;
            break;
        }

        //Shapes[i]->setSizeChangeStep(1);

        if(isFilledShape)
        {
            static_cast<CFilledShape*>(Shapes[i])->setLineColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
            static_cast<CFilledShape*>(Shapes[i])->setFillColor(RGB(RandRange(0,255),RandRange(0,255),RandRange(0,255)));
            //static_cast<CFilledShape*>(Shapes[i])->setLineWidth(RandRange(0,15));
        }
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

    for(int i=0; i<NumOfShapes; i++)
        Shapes[i]->setBoundingRect(tmpRect);

    InvalidateRect(hwnd, NULL, EraseBkgnd);
}


//Procedura wywo�ywana co 25 ms (czas ustawia si� trzecim argumentem
// funkcji SetTimer() wywo�ywanej w OnCreate).
void OnTimer(HWND hwnd, WPARAM timerID)
{
    if(InDrawState) return;

    for(int i=0; i<NumOfShapes; i++)
        Shapes[i]->Tick();

    InvalidateRect(hwnd, NULL, EraseBkgnd);
}


//Procedura wywo�ywana w celu od�wie�enia zawarto�ci okna.
//Wy��cznie tutaj powinno si� przeprowadza� rysowanie.
void OnPaint(HWND hwnd, HDC hdc)
{
    if(InDrawState)
        DrawFocusRect(hdc, &MouseRect);

    for(int i=0; i<NumOfShapes; i++)
        Shapes[i]->Paint(hdc);
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
        Shapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);

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
        Shapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);

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
        Shapes[CurrDrawnShapeIdx]->setBoundingRect(MouseRect);
        CurrDrawnShapeIdx = (CurrDrawnShapeIdx + 1) % NumOfShapes;

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

    for(int i=0; i<NumOfShapes; i++)
        delete Shapes[i];
}

















