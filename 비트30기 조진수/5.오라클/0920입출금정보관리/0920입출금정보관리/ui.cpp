//ui.cpp

#include "std.h"

HWND g_hListBox;
HWND g_hCombo;

void ui_GetListBoxHendle(HWND hDlg)
{
	g_hListBox = GetDlgItem(hDlg, IDC_LIST1);
}

void ui_GetComboHendle(HWND hDlg)
{
	g_hCombo = GetDlgItem(hDlg, IDC_COMBO1);
}

void ui_CSIDComboPrint(vector<int> *datalist, int size)
{
	for (int i = 0; i < size; i++)
	{
		int info = (*datalist)[i];
		TCHAR temp[20];
		wsprintf(temp, TEXT("%d"), info);
		SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)temp);
	}
}