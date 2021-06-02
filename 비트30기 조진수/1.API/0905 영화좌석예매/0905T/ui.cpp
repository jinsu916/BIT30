//ui.cpp
#include "std.h"

HWND g_hList;           //IDC_LIST1
extern vector<MEMBER> g_memberlist;

void ui_GetConnectData(HWND hDlg, TCHAR* id, TCHAR* pw)
{
	GetDlgItemText(hDlg, IDC_EDIT1, id, sizeof(TCHAR) * 20);
	GetDlgItemText(hDlg, IDC_EDIT2, pw, sizeof(TCHAR) * 20);
}

BOOL ui_Insert(HWND hDlg, MEMBER *pmem)//p.146
{
	MEMBER member = { 0 };

	UINT ret = DialogBoxParam(GetModuleHandle(0),
		MAKEINTRESOURCE(IDD_DIALOG2), hDlg,
		InsertProc, (LPARAM)&member);

	if (ret == IDOK)
	{
		*pmem = member;
		g_memberlist.push_back(member);
		return TRUE;
	}
	else				return FALSE;
}

BOOL ui_Insert2(HWND hDlg, MEMBER *pmem)//p.146
{
	MEMBER member = { 0 };

	UINT ret = DialogBoxParam(GetModuleHandle(0),
		MAKEINTRESOURCE(IDD_DIALOG3), hDlg,
		InsertProc2, (LPARAM)&member);

	if (ret == IDOK)
	{
		*pmem = member;
		g_memberlist.push_back(member);
		return TRUE;
	}
	else				return FALSE;
}