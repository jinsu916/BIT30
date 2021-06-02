//소스.cpp
#include <Windows.h>

//1)DBCS(char)- ANSI 기반의 코드 : 키워드 : A
/*
int __stdcall WinMain(HINSTANCE hlnst, HINSTANCE hPrev,
	LPSTR ipCmdLine, int nShowCmd)
{
	return 0;
}
*/

//2) UNICODE(wchar_t) 기반의 코드(유니코드 관련 키워드 w(wide)
/*
int __stdcall wWinMain(HINSTANCE hlnst, HINSTANCE hPrev,
	LPWSTR ipCmdLine, int nShowCmd)
{
	return 0;
}
*/

//3) 범용타입 (알아서 char 또는 wchar_t 로 처리):
//   관련키워드  : t
#include <tchar.h> 
int WINAPI _tWinMain(HINSTANCE hlnst, HINSTANCE hPrev,
	LPTSTR ipCmdLine, int nShowCmd)
{
	int value = MessageBoxA(0, "Hello,API", "First", MB_YESNO);
	if (value == IDYES)
	{

	}
	else if (value == IDNO)
	{

	}
	MessageBoxW(0, L"Hello,API", L"First", MB_OK | MB_ICONQUESTION);
	MessageBox(0, TEXT("Hello,API"), TEXT("First"), MB_OK);

	return 0;
}