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

/******************** Procedury obs³ugi zdarzeñ ********************/

//Procedura wywo³ywana przed pokazaniem okna (na pocz¹tku dzia³ania programu).
//Tutaj mo¿na przeprowadziæ pocz¹tkow¹ inicjalizacjê zmiennych, obiektów itp.
void OnCreate(HWND hwnd)
{
    int shapeType;

    srand(time(NULL));

    for(int i=0; i<NumOfFilledShapes; i++)
    {
        shapeType = RandRange(8,8);

        switch(shapeType)
        {
        case 1: //prostok¹t
            FilledShapes[i] = new CRectangle;
            break;
        case 2: //elipsa
            FilledShapes[i] = new CEllipse;
            break;
        case 3: //kó³ko
            FilledShapes[i] = new CCircle;
            break;
        case 4: //kwadrat
            FilledShapes[i] = new CSquare;
            break;
        case 5: //trójk¹t równoramienny
            FilledShapes[i] = new CIsoscelesTriangle;
            break;
        case 6: //trójk¹t równoboczny
            FilledShapes[i] = new CEquilateralTriangle;
            break;
        case 7: //trójk¹t prostok¹tny
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


//Procedura wywo³ywana po ka¿dej zmianie rozmiaru okna
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


//Procedura wywo³ywana co 25 ms (czas ustawia siê trzecim argumentem
// funkcji SetTimer() wywo³ywanej w OnCreate).
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
        //******* Modyfikacja rozmiarów figury *******
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

        //******* Modyfikacja koloru wype³nienia *******
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


//Procedura wywo³ywana w celu odœwie¿enia zawartoœci okna.
//Wy³¹cznie tutaj powinno siê przeprowadzaæ rysowanie.
void OnPaint(HWND hwnd, HDC hdc)
{
    if(InDrawState)
        DrawFocusRect(hdc, &MouseRect);

    for(int i=0; i<NumOfFilledShapes; i++)
        FilledShapes[i]->Paint(hdc);
}


//Procedura wywo³ywana po naciœniêciu klawisza klawiatury.
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


//Procedura wywo³ywana po poruszeniu wskaŸnika myszy.
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


//Procedura wywo³ywana po naciœniêciu lewego przycisku myszy.
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


//Procedura wywo³ywana po zwolnieniu lewego przycisku myszy.
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


//Procedura wywo³ywana przed zniszczeniem okna (przed koñcem dzia³ania programu).
//Tutaj mo¿na zwolniæ zaalokowane zasoby.
void OnDestroy(HWND hwnd)
{
    KillTimer(hwnd, 1);

    for(int i=0; i<NumOfFilledShapes; i++)
        delete FilledShapes[i];
}

















