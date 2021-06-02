//ui.cpp

#include "std.h"

HWND g_hListTeamView;
HWND g_hCombo;

void ui_InitTeamComboView(HWND hDlg)
{
	g_hCombo = GetDlgItem(hDlg, IDC_COMBO1);
}

void ui_getcombocustid(HWND hDlg, int *cs_id)
{
	*cs_id = GetDlgItemInt(hDlg, IDC_COMBO1, 0, 0);
}

void ui_GetDeleteacid(HWND hDlg, int *ac_id)
{
	*ac_id = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);

}


void ui_InitTeamListView(HWND hDlg)
{
	g_hListTeamView = GetDlgItem(hDlg, IDC_LIST1);
	LVCOLUMN COL;

	// 헤더를 추가한다.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;

	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("계좌ID");				// 첫 번째 헤더
	COL.iSubItem = 0;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("계좌잔액");			// 두 번째 헤더
	COL.iSubItem = 1;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("개설일");
	COL.iSubItem = 2;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 2, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("사용횟수");
	COL.iSubItem = 3;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 3, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("고객ID");
	COL.iSubItem = 4;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 4, (LPARAM)&COL);

}

void ui_TeamComboListPrint(vector<int> *datalist, int size)
{
	//ListView_DeleteAllItems(g_hListTeamView);
	//ListView_DeleteItem(hList, idx);
	
	for (int i = 0; i < size; i++)
	{
		int info = (*datalist)[i];
		TCHAR temp[20];
		wsprintf(temp, TEXT("%d"), info);
		SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)temp);
		//========================================
		//ListTeamPrint(info, i);
		//=========================================
	}
}

void ui_AcListPrint(vector<Account> *datalist, int size)
{
	ListView_DeleteAllItems(g_hListTeamView);
	//ListView_DeleteItem(hList, idx);

	for (int i = 0; i < size; i++)
	{
		Account info = (*datalist)[i];
		//========================================
		ListAcPrint(info, i);
		//=========================================
	}
}

void ListAcPrint(Account info, int idx)
{
	LVITEM LI;

	// 텍스트와 이미지를 가진 아이템들을 등록한다.
	LI.mask = LVIF_TEXT;

	LI.iItem = idx;
	LI.iSubItem = 0;
	TCHAR buf[20];
	wsprintf(buf, TEXT("%d"), info.ac_id);
	LI.pszText = buf;			// 첫 번째 아이템
	SendMessage(g_hListTeamView, LVM_INSERTITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 1;
	wsprintf(buf, TEXT("%d"), info.ac_money);
	LI.pszText = buf;			// 첫 번째 아이템
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 2;
	LI.pszText = info.ac_date;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 3;
	wsprintf(buf, TEXT("%d"), info.ac_count);
	LI.pszText = buf;			// 첫 번째 아이템
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 4;
	wsprintf(buf, TEXT("%d"), info.cs_id);
	LI.pszText = buf;			// 첫 번째 아이템
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)&LI);
}
