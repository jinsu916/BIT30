//handler.cpp
#include "std.h"

extern SHAPE g_curshape;
extern vector<SHAPE> g_shapelist;
extern POINT g_curpoint;

bool g_viewcheck = false;
int colorState = 0;

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM)
{
	shape_Init();

	return 0;
}

LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM)
{
	createShape2(hwnd);

	return 0;
}

LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	createShape1(hwnd, lParam);

	return 0;
}

LRESULT OnInitMenuPopup(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = (HMENU)wParam;

	EnableMenuItem(hMenu, ID_40004,
		g_curshape.color == RGB(255, 0, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40005,
		g_curshape.color == RGB(0, 255, 0) ? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40006,
		g_curshape.color == RGB(0, 0, 255) ? MF_GRAYED : MF_ENABLED);

	return 0;
}

LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case ID_40001: SendMessage(hwnd, WM_CLOSE, 0, 0); break;

		//도형 색변환
	case ID_40004: g_curshape.color = RGB(255, 0, 0); break;
	case ID_40005: g_curshape.color = RGB(0, 255, 0); break;
	case ID_40006: g_curshape.color = RGB(0, 0, 255); break;

		InvalidateRect(hwnd, 0, TRUE);
	}
	return 0;
}


LRESULT OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };

	g_curpoint = pt;
	RECT rc = { 0, 0, 200, 30 };
	InvalidateRect(hwnd, &rc, TRUE);

	return 0;
}



LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM)
{
	PostQuitMessage(0);
	return 0;
}
void OnShape(HWND hwnd, int type)
{
	if (type == 1)
		shape_Rect(hwnd);
	
}

