#include "std.h"

extern SHAPE g_curshape;
extern vector<SHAPE> g_shapelist;
extern POINT g_curpoint;

bool g_viewcheck = false;
int colorState = 0;
LRESULT OnMouseMove(HWND hwnd, WPARAM, LPARAM lParam)
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };

	g_curpoint = pt;
	RECT rc = { 0, 0, 200, 30 };
	InvalidateRect(hwnd, &rc, TRUE);

	return 0;
}
LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM)
{

	shape_Init();
	return 0;
}
LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM)
{
	PostQuitMessage(0);
	return 0;
}
LRESULT OnLButtonDown(HWND hwnd, WPARAM, LPARAM lParam)
{
	createShape1(hwnd , lParam);


	if (GetKeyState(MK_LBUTTON) && GetKeyState(VK_CONTROL))
	{
		if (1 < g_shapelist.size()) {
			int i = g_shapelist.size();
			g_shapelist.resize(i - 2);

			InvalidateRect(hwnd, 0, TRUE);
		}
	}
	return 0;
}
LRESULT OnPaint(HWND hwnd, WPARAM, LPARAM)
{
	createShape2(hwnd);
	return 0;
}
LRESULT OnContext(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU1));
	HMENU hSubMenu = GetSubMenu(hMenu, 1);
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };
	TrackPopupMenu(hSubMenu, TPM_LEFTBUTTON, pt.x, pt.y, 0, hwnd, 0);

	return 0;
}
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case ID_40001: 
	{
		g_shapelist.clear();
		InvalidateRect(hwnd, 0, TRUE);
	}break;
	case ID_40004: SendMessage(hwnd, WM_CLOSE, wParam, lParam); break;
	case ID_40005: g_curshape.type = 1; break;
	case ID_40006: g_curshape.type = 2; break;
	case ID_40007: g_curshape.type = 3; break;
	case ID_40008: g_curshape.color = RGB(255, 0, 0); break;
	case ID_40010: g_curshape.color = RGB(0, 0, 255); break;
	case ID_40009: g_curshape.color = RGB(0, 255, 0); break;
	case ID_40011: g_curshape.penwidth = 1; break;
	case ID_40012: g_curshape.penwidth = 3; break;
	case ID_40013: g_curshape.penwidth = 5; break;
	case ID_40014: 
	{
		if (g_viewcheck == false)
			g_viewcheck = true;
		else if (g_viewcheck == true)
			g_viewcheck = false;
	}break;
	}
	InvalidateRect(hwnd, 0, FALSE);
	return 0;
}
LRESULT OnInitMenu(HWND hwnd, WPARAM wParam, LPARAM lParam)
{
	HMENU hMenu = (HMENU)wParam;
	EnableMenuItem(hMenu, ID_40005, g_curshape.type == 1
		? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40006, g_curshape.type == 2
		? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40007, g_curshape.type == 3
		? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40008, g_curshape.color == RGB(255, 0, 0)
		? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40010, g_curshape.color == RGB(0, 0, 255)
		? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40009, g_curshape.color == RGB(0, 255, 0)
		? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40011, g_curshape.penwidth == 1
		? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40012, g_curshape.penwidth == 3
		? MF_GRAYED : MF_ENABLED);
	EnableMenuItem(hMenu, ID_40013, g_curshape.penwidth == 5
		? MF_GRAYED : MF_ENABLED);
	return 0;
}
