//start.cpp
//대화상자 기반(p.150)
#include "std.h"

vector<MEMBER> g_memberlist;

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_INITDIALOG:		return OnInitDialog(hDlg, wParam, lparam);	// 초기화
	case WM_COMMAND:		return OnCommand(hDlg, wParam, lparam);		
	}
	return FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE, LPTSTR IpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,
		MAKEINTRESOURCE(IDD_DIALOG1),	//부모 주소
		0, DlgProc);					//자식 프로세스

	return 0;
}