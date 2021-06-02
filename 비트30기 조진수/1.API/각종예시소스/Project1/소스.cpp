//Skeleton코드.cpp
#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam) {
	switch (msg) {
	case WM_LBUTTONDOWN:
		{
		//사각형 출력
		//HDC hdc = GetDC(hwnd); //클라이언트 영역
		HDC hdc = GetWindowDC(hwnd); //윈도우 영역
		Rectangle(hdc, 10, 10, 110, 110);
		}
		return 0;
	case WM_CREATE:
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, msg, wParam, IParam);
}
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lPCmdLine, int nShowCmd)
{
	//1. 윈도우 클래스 만들기
	WNDCLASS wc;
	wc.cbWndExtra = 0;
	wc.cbClsExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;
	wc.style = 0;

	//2.등록(레지스트리에)
	RegisterClass(&wc);

	//3.윈도우 창 만들기
	HWND hwnd = CreateWindowEx(0, //WS_EX_TOPMOST
		TEXT("fiest"),		//클래스면
		TEXT("Hello"),		//캡션바 내용
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	//초기 위치
		0, 0,								//부모 윈도우 핸들, 메뉴 핸들
		hInst,				//WinMain 의 1번째 파라미터 (exe 주소)
		0);					//생성 인자

							//4.윈도우 보여주기
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//5.Message
	/*
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	*/
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			DispatchMessage(&msg);
		}
		else
		{
			HDC hdc = GetDC(hwnd);
			SetPixel(hdc,
				rand() % 500, rand() % 400,
				RGB(255, 0, 0));
				//RGB(rand() % 256, rand() % 256, rand() % 256));
			ReleaseDC(hwnd, hdc);
		}
	}
	return 0;
}