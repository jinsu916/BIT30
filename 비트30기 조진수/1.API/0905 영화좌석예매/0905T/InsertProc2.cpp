//InsertProc.cpp
#include "std.h"

//extern vector<MEMBER> g_memberlist;
BOOL CALLBACK InsertProc2(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:  return OnInitDialog2(hDlg, wParam, lParam);

	case WM_COMMAND:	return OnCommand2(hDlg, wParam, lParam);
	}
	return FALSE;
}
