//start.cpp
//��ȭ���� ���(p.150)
#include "std.h"

vector<MEMBER> g_memberlist;

BOOL CALLBACK DlgProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_INITDIALOG:		return OnInitDialog(hDlg, wParam, lparam);	// �ʱ�ȭ
	case WM_COMMAND:		return OnCommand(hDlg, wParam, lparam);		
	}
	return FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE, LPTSTR IpCmdLine, int nShowCmd)
{
	UINT ret = DialogBox(hInst,
		MAKEINTRESOURCE(IDD_DIALOG1),	//�θ� �ּ�
		0, DlgProc);					//�ڽ� ���μ���

	return 0;
}