//Skeleton�ڵ�.cpp
#include <Windows.h>
#include <tchar.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam) {
	switch (msg) {
	case WM_LBUTTONDOWN:
		{
		//�簢�� ���
		//HDC hdc = GetDC(hwnd); //Ŭ���̾�Ʈ ����
		HDC hdc = GetWindowDC(hwnd); //������ ����
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
	//1. ������ Ŭ���� �����
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

	//2.���(������Ʈ����)
	RegisterClass(&wc);

	//3.������ â �����
	HWND hwnd = CreateWindowEx(0, //WS_EX_TOPMOST
		TEXT("fiest"),		//Ŭ������
		TEXT("Hello"),		//ĸ�ǹ� ����
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,	//�ʱ� ��ġ
		0, 0,								//�θ� ������ �ڵ�, �޴� �ڵ�
		hInst,				//WinMain �� 1��° �Ķ���� (exe �ּ�)
		0);					//���� ����

							//4.������ �����ֱ�
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