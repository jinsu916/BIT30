//�ҽ�.cpp
#include <Windows.h>

//1)DBCS(char)- ANSI ����� �ڵ� : Ű���� : A
/*
int __stdcall WinMain(HINSTANCE hlnst, HINSTANCE hPrev,
	LPSTR ipCmdLine, int nShowCmd)
{
	return 0;
}
*/

//2) UNICODE(wchar_t) ����� �ڵ�(�����ڵ� ���� Ű���� w(wide)
/*
int __stdcall wWinMain(HINSTANCE hlnst, HINSTANCE hPrev,
	LPWSTR ipCmdLine, int nShowCmd)
{
	return 0;
}
*/

//3) ����Ÿ�� (�˾Ƽ� char �Ǵ� wchar_t �� ó��):
//   ����Ű����  : t
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