//handler.cpp

#include "std.h"

BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	//공통컨트롤
	InitCommonControls();
	
	//리스트핸들
	ui_GetListBoxHendle(hDlg);
	//콤보받스핸들
	ui_GetComboHendle(hDlg);
	return TRUE;
}

BOOL  OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		//DB접속
	case IDC_BUTTON1:   OnDBConnect(hDlg);      return 0;
		//DB접속해제
	case IDC_BUTTON2:	OnDBDConnect(hDlg);		return 0;
		//
	case IDC_BUTTON3:	OnACListView(hDlg);		return 0;
		//취소
	case IDCANCEL:		OnCancel(hDlg);			return 0;
	}
	return TRUE;
}

void OnDBConnect(HWND hDlg)
{
	if (wbdb_DBConnect() == TRUE)
	{
		MessageBox(NULL, TEXT("DB접속 성공"), TEXT("알림"), MB_OK);
		SetWindowText(hDlg, TEXT("DB Connect"));

		vector<int> csidlist;
		wbdb_GetCSIDAll(&csidlist);
		ui_CSIDComboPrint(&csidlist, csidlist.size());
	}
	else
		MessageBox(NULL, TEXT("DB접속 실패"), TEXT("알림"), MB_OK);
}

void OnDBDConnect(HWND hDlg)
{
	if (wbdb_DBDConnect() == TRUE)
	{
		MessageBox(NULL, TEXT("DB접속해제 성공"), TEXT("알림"), MB_OK);
		SetWindowText(hDlg, TEXT("DB DisConnect"));
	}
	else
		MessageBox(NULL, TEXT("DB접속해제 실패"), TEXT("알림"), MB_OK);
}

void OnACListView(HWND hDlg)
{

}

void OnCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);

}