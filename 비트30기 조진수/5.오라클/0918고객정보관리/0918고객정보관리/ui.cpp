//ui.cpp

#include "std.h"
HWND g_hListTeamView;
HWND g_hRadio1;
HWND g_hCombo;

//void ui_GetTeamCreateInfo(HWND hDlg, int *team_id, TCHAR*team_name)
//{
//	*team_id = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
//	GetDlgItemText(hDlg, IDC_EDIT2, team_name, 20);
//}

void ui_GetTeamSelectInfo(HWND hDlg, int *cs_id, TCHAR*cs_name, TCHAR*cs_phone)
{
	*cs_id = GetDlgItemInt(hDlg, IDC_EDIT3, 0, 0);
	GetDlgItemText(hDlg, IDC_EDIT3, cs_name, 20);
	GetDlgItemText(hDlg, IDC_EDIT3, cs_phone, 20);
}

void ui_GetTeamCreateInfo(HWND hDlg, int *cs_id, TCHAR*cs_name, TCHAR*cs_gender, TCHAR*cs_phone)
{
	*cs_id = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
	GetDlgItemText(hDlg, IDC_EDIT2, cs_name, 20);
	if (SendMessage(g_hRadio1, BM_GETCHECK, 0, 0) == BST_CHECKED)
		_tcscpy(cs_gender, (LPWSTR)TEXT("M"));
	else
		_tcscpy(cs_gender, (LPWSTR)TEXT("F"));

	GetDlgItemText(hDlg, IDC_EDIT4, cs_phone, 20);
}

void ui_GetTeamCreateInfo1(HWND hDlg, int *cs_id)
{
	*cs_id = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);

}

void ui_GetTeamCreateInfo2(HWND hDlg, int *cs_id, TCHAR*cs_name, TCHAR*cs_phone)
{
	*cs_id = GetDlgItemInt(hDlg, IDC_EDIT1, 0, 0);
	GetDlgItemText(hDlg, IDC_EDIT2, cs_name, 20);
	GetDlgItemText(hDlg, IDC_EDIT4, cs_phone, 20);
}

void ui_InitTeamCombo(HWND hDlg)
{
	g_hCombo= GetDlgItem(hDlg, IDC_COMBO1);
	SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)TEXT("ID"));
	SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)TEXT("�̸�"));
	SendMessage(g_hCombo, CB_ADDSTRING, 0, (LPARAM)TEXT("����"));
}

int ui_GetComboSel()
{
	int sel = SendMessage(g_hCombo, CB_GETCURSEL, 0, 0);

	return sel;
}

void ui_InitTeamRadio(HWND hDlg)
{
	g_hRadio1 = GetDlgItem(hDlg, IDC_RADIO1);
}

void ui_InitTeamListView(HWND hDlg)
{
	g_hListTeamView = GetDlgItem(hDlg, IDC_LIST1);
	LVCOLUMN COL;

	// ����� �߰��Ѵ�.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;

	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("��ID");				// ù ��° ���
	COL.iSubItem = 0;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("�̸�");			// �� ��° ���
	COL.iSubItem = 1;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("����");
	COL.iSubItem = 2;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 2, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("��ȭ��ȣ");
	COL.iSubItem = 3;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 3, (LPARAM)&COL);
	COL.cx = 100;
	COL.pszText = (LPWSTR)TEXT("���������");
	COL.iSubItem = 4;
	SendMessage(g_hListTeamView, LVM_INSERTCOLUMN, 4, (LPARAM)&COL);

}

void ui_TeamListPrint(vector<Customer> *datalist, int size)
{
	ListView_DeleteAllItems(g_hListTeamView);
	//ListView_DeleteItem(hList, idx);

	for (int i = 0; i < size; i++)
	{
		Customer info = (*datalist)[i];
		//========================================
		ListTeamPrint(info, i);
		//=========================================
	}
}

void ListTeamPrint(Customer info, int idx)
{
	LVITEM LI;

	// �ؽ�Ʈ�� �̹����� ���� �����۵��� ����Ѵ�.
	LI.mask = LVIF_TEXT;

	LI.iItem = idx;
	LI.iSubItem = 0;
	TCHAR buf[20];
	wsprintf(buf, TEXT("%d"), info.cs_id);
	LI.pszText = buf;			// ù ��° ������
	SendMessage(g_hListTeamView, LVM_INSERTITEM, 0, (LPARAM)&LI);
	
	LI.iSubItem = 1;
	LI.pszText = info.cs_name;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 2;
	LI.pszText = info.cs_gender;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 3;
	LI.pszText = info.cs_phone;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)&LI);

	LI.iSubItem = 4;
	LI.pszText = info.cs_date;
	SendMessage(g_hListTeamView, LVM_SETITEM, 0, (LPARAM)&LI);
}

/*
void ui_GetHandle(HWND hDlg)
{
	g_hListView = GetDlgItem(hDlg, IDC_LIST1);
}

void ui_SetListViewColumnHeader(HWND hDlg)
{
	LVCOLUMN COL;

	// ����� �߰��Ѵ�.
	COL.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	COL.fmt = LVCFMT_LEFT;
	COL.cx = 150;
	COL.pszText = TEXT("�̸�");				// ù ��° ���
	COL.iSubItem = 0;
	SendMessage(g_hListView, LVM_INSERTCOLUMN, 0, (LPARAM)&COL);

	COL.pszText = TEXT("PID");			// �� ��° ���
	COL.iSubItem = 1;
	SendMessage(g_hListView, LVM_INSERTCOLUMN, 1, (LPARAM)&COL);
}



*/