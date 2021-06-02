//소스1.cpp
#include <Windows.h>
#include <tchar.h>

int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hPrev,
	LPTSTR ipCmdLine, int nShowCmd)
{
	//===========================================================
	//1. 윈도우 클래스 생성
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);  //자기자신의 크기를 담는다
	wcex.style = CS_HREDRAW | CS_VREDRAW; //??
	wcex.lpfnWndProc = DefWindowProc; //메세지처리함수
	wcex.cbClsExtra = 0; //예약
	wcex.cbWndExtra = 0; //예약
	wcex.hInstance = hlnst; //자신의 인스턴스 등록
	wcex.hIcon = LoadIcon(0, IDI_APPLICATION); //미리등록된
	wcex.hCursor = LoadCursor(0, IDC_ARROW); //미리등록된
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //미리등록된
	wcex.lpszMenuName = 0;
	wcex.lpszClassName = TEXT("FIRST");//등록키
	wcex.hIconSm = 0; //예약

	//2. 위도우 클래스를 레지스트리에 등록
	RegisterClassEx(&wcex);

	//3. 윈도우 생성(<-----MainWindow)
	HWND hwnd;
	hwnd = CreateWindow(TEXT("FIRST"), TEXT("타이틀바"),
		WS_OVERLAPPEDWINDOW, //윈도우속성
		0, 0, 200, 200,//시작위치x,y, 사이즈x,y
		0, 0, hlnst, 0);

	//4. 윈도우 화면 출력
//	ShowWindow(hwnd, SW_NORMAL);
	ShowWindow(hwnd, nShowCmd);
	//===========================================================
	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_OK);

	return 0;
}