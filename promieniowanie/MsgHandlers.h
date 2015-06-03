#ifndef MSGHANDLERS_H_INCLUDED
#define MSGHANDLERS_H_INCLUDED

#include <windows.h>

void OnCreate(HWND hwnd);
void OnSize(HWND hwnd, int width, int height, WPARAM wParam);
void OnTimer(HWND hwnd, WPARAM timerID);
void OnPaint(HWND hwnd, HDC hdc);
void OnKeyDown(HWND hwnd, WPARAM keyCode);
void OnMouseMove(HWND hwnd, int x, int y, WPARAM wParam);
void OnLButtonDown(HWND hwnd, int x, int y, WPARAM wParam);
void OnLButtonUp(HWND hwnd, int x, int y, WPARAM wParam);
void OnDestroy(HWND hwnd);

#endif // MSGHANDLERS_H_INCLUDED
