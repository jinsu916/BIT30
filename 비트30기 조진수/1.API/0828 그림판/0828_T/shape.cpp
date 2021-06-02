#include "std.h"

extern vector<SHAPE> g_shapelist;
extern SHAPE g_curshape;
extern POINT g_curpoint;
extern bool g_viewcheck;

void createShape1(HWND hwnd, LPARAM lParam) //벡터 배열에 SHAPE 구조체 쌓기 
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };

	
	g_curshape.pt = pt;
	g_shapelist.push_back(g_curshape);
	
	InvalidateRect(hwnd, 0, FALSE);
}
void createShape2(HWND hwnd) //무효화 후 다시 그리는 함수 (출력) onpaint
{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
	
		for (int i = 0; i < (int)g_shapelist.size(); i++)
		{
			POINT point[3] = {{g_shapelist[i].pt.x, g_shapelist[i].pt.y + 50}
			,{g_shapelist[i].pt.x + 25, g_shapelist[i].pt.y} 
			,{g_shapelist[i].pt.x + 50, g_shapelist[i].pt.y + 50} };

			SHAPE shape = g_shapelist[i];
			HPEN pen = CreatePen(PS_SOLID, g_shapelist[i].penwidth, RGB(0, 0, 0));
			HPEN old = (HPEN)SelectObject(hdc, pen);
			HBRUSH brush = CreateSolidBrush(g_shapelist[i].color);
			HBRUSH oldB = (HBRUSH)SelectObject(hdc, brush);
			if (g_shapelist[i].type == 1)
				Rectangle(hdc, g_shapelist[i].pt.x, g_shapelist[i].pt.y,
					g_shapelist[i].pt.x + 50, g_shapelist[i].pt.y + 50);
			else if (g_shapelist[i].type == 2)
				Ellipse(hdc, g_shapelist[i].pt.x, g_shapelist[i].pt.y,
					g_shapelist[i].pt.x + 50, g_shapelist[i].pt.y + 50);
			else if (g_shapelist[i].type == 3) {
				Polygon(hdc, point, 3);
			}
			//삼각형좀 ㅠ
			DeleteObject(SelectObject(hdc, old));
			DeleteObject(SelectObject(hdc, oldB));
		}
	//좌표 출력
	if (g_viewcheck == true) {
		TCHAR arr[20];
		wsprintf(arr, TEXT("%05d:%05d"), g_curpoint.x, g_curpoint.y);
		TextOut(hdc, 0, 0, arr, _tcslen(arr));
	}


	EndPaint(hwnd, &ps);
}

void shape_Init() {
	g_curshape.color = RGB(255, 0, 0);
	g_curshape.penwidth = 1;
	g_curshape.type = 1;
	
}
