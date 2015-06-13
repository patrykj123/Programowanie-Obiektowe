#include <windows.h>
#include "MsgHandlers.h"


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
char szClassName[ ] = "CodeBlocksWindowsApp";

int WINAPI WinMain (HINSTANCE hThisInstance, HINSTANCE hPrevInstance, LPSTR lpszArgument, int nCmdShow)
{
	HWND hwnd;               /* This is the handle for our window */
	MSG message;            /* Here messages to the application are saved */
	WNDCLASSEX wincl;        /* Data structure for the windowclass */

	/* The Window structure */
	wincl.hInstance = hThisInstance;
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
	wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
	wincl.cbSize = sizeof (WNDCLASSEX);

	/* Use default icon and mouse-pointer */
	wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;                 /* No menu */
	wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
	wincl.cbWndExtra = 0;                      /* structure or the window instance */
	/* Use Windows's default colour as the background of the window */
	wincl.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1);

	/* Register the window class, and if it fails quit the program */
	if (!RegisterClassEx (&wincl))
		return 0;

	/* The class is registered, let's create the program*/
	hwnd = CreateWindowEx (
			   0,                   /* Extended possibilites for variation */
			   szClassName,         /* Classname */
			   "Programowanie obiektowe 2014/2015",       /* Title Text */
			   WS_OVERLAPPEDWINDOW, /* default window */
			   CW_USEDEFAULT,       /* Windows decides the position */
			   CW_USEDEFAULT,       /* where the window ends up on the screen */
			   900,                 /* The programs width */
			   700,                 /* and height in pixels */
			   HWND_DESKTOP,        /* The window is a child-window to desktop */
			   NULL,                /* No menu */
			   hThisInstance,       /* Program Instance handler */
			   NULL                 /* No Window Creation data */
		   );

	/* Make the window visible on the screen */
	ShowWindow (hwnd, nCmdShow);

	/* Run the message loop. It will run until GetMessage() returns 0 */
	while (GetMessage(&message, NULL, 0, 0))
	{
		/* Translate virtual-key messages into character messages */
		TranslateMessage(&message);
		/* Send message to WindowProcedure */
		DispatchMessage(&message);
	}

	/* The program return-value is 0 - The value that PostQuitMessage() gave */
	return message.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;


	switch (message)                  /* handle the messages */
	{
	case WM_CREATE:
		OnCreate(hwnd);
		break;
	case WM_SIZE:
		OnSize(hwnd, short(lParam & 0x0000FFFF), short(lParam >> 16), wParam);
		break;
	case WM_TIMER:
		OnTimer(hwnd, wParam);
		break;
	case WM_KEYDOWN:
		OnKeyDown(hwnd, wParam);
		break;
	case WM_LBUTTONDOWN:
		OnLButtonDown(hwnd, short(lParam & 0x0000FFFF), short(lParam >> 16), wParam);
		break;
	case WM_MOUSEMOVE:
		OnMouseMove(hwnd, short(lParam & 0x0000FFFF), short(lParam >> 16), wParam);
		break;
	case WM_LBUTTONUP:
		OnLButtonUp(hwnd, short(lParam & 0x0000FFFF), short(lParam >> 16), wParam);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		OnPaint(hwnd, hdc);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		OnDestroy(hwnd);
		PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
		break;
	default:                      /* for messages that we don't deal with */
		return DefWindowProc (hwnd, message, wParam, lParam);
	}

	return 0;
}
