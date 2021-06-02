#include "std.h"
vector<SHAPE>  g_shapelist;
SHAPE g_curshape;
POINT g_curpoint;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_MOUSEMOVE:		return OnMouseMove(hwnd, wParam, lParam);
	case WM_CONTEXTMENU:	return OnContext(hwnd, wParam, lParam);
	case WM_COMMAND:		return OnCommand(hwnd, wParam, lParam);
	case WM_INITMENUPOPUP:	return OnInitMenu(hwnd, wParam, lParam);
	case WM_LBUTTONDOWN:	return OnLButtonDown(hwnd, wParam, lParam);
	case WM_PAINT:			return OnPaint(hwnd, wParam, lParam);
	case WM_CREATE:
	{
		SetTimer(hwnd, 1, 1000, NULL);
		SendMessage(hwnd, WM_TIMER, 1, NULL);
	}
	return OnCreate(hwnd, wParam, lParam);
	case WM_TIMER:
	{
		if (wParam == 1) {
			SYSTEMTIME st;
			GetLocalTime(&st);
			TCHAR buf[60];
			wsprintf(buf, TEXT("%d�� %d�� %d�� - %d�� %d�� %d��"),
				st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
			SetWindowText(hwnd, buf);
		}
	}
	return 0;
	case WM_DESTROY:		return OnDestroy(hwnd, wParam, lParam);
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine, int nShowCmd)
{
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.style = 0;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(0,
		TEXT("first"),
		TEXT("Hello"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0,
		hInst,
		0);

	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}