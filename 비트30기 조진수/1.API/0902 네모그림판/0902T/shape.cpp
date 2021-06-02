//shape.cpp
#include "std.h"
extern vector<SHAPE> g_shapelist;
extern SHAPE g_curshape;
extern POINT g_curpoint;
extern bool g_viewcheck;

void createShape1(HWND hwnd, LPARAM lParam)
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };


	g_curshape.pt = pt;
	g_shapelist.push_back(g_curshape);

	InvalidateRect(hwnd, 0, FALSE);

	TCHAR arr[20];
	wsprintf(arr, TEXT("%05d:%05d"), g_curpoint.x, g_curpoint.y);
	SetWindowText(hwnd, arr);
}

void createShape2(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hdc = BeginPaint(hwnd, &ps);

	for (int i = 0; i < (int)g_shapelist.size(); i++)
	{
		
		SHAPE shape = g_shapelist[i];

		HBRUSH brush = CreateSolidBrush(g_shapelist[i].color);
		HBRUSH oldB = (HBRUSH)SelectObject(hdc, brush);

		if (g_shapelist[i].type == 1)
			Rectangle(hdc, g_shapelist[i].pt.x, g_shapelist[i].pt.y,
				g_shapelist[i].pt.x + 50, g_shapelist[i].pt.y + 50);

		DeleteObject(SelectObject(hdc, oldB));
		
	}
	


	EndPaint(hwnd, &ps);
}
void shape_Init()
{
	g_curshape.color = RGB(255, 0, 0);
	g_curshape.pt.x = 0;
	g_curshape.pt.y = 0;
	g_curshape.type = 1;
}
void shape_Rect(HWND hwnd)
{
	g_curshape.type = 1;
}

