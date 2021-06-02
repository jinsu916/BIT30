//handler.cpp

#include "std.h"

BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	InitCommonControls();

	ui_InitTeamRadio(hDlg);
	ui_InitTeamListView(hDlg);
	
	ui_InitTeamCombo(hDlg);
	return TRUE;
}

BOOL  OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
		//DB����
	case IDC_BUTTON1:   OnDBConnect(hDlg);      return 0;
		//DB��������
	case IDC_BUTTON2:	OnDBDConnect(hDlg);		return 0;
		//��ü���
	case IDC_BUTTON3:	AllPrint(hDlg);			return 0;
		//�Է�
	case IDC_BUTTON4:	OnInesert(hDlg);		return 0;
		//����
	case IDC_BUTTON5:	OnUpdate(hDlg);			return 0;
		//����
	case IDC_BUTTON6:	OnDelete(hDlg);			return 0;
		//�˻�
	case IDC_BUTTON7:	OnSelect(hDlg);			return 0;
		////DDL��===================================================
		////Team ���̺� ����
		//case IDC_BUTTON3:	OnCreateTeamTable(hDlg);	break;
		////Team ���̺� ����
		//case IDC_BUTTON4:	OnDropTeamTable(hDlg);		break;
		////Member ���̺� ����
		//case IDC_BUTTON5:	OnCreateMemberTable(hDlg);	break;
		////Member ���̺� ����
		//case IDC_BUTTON6:	OnDropMemberTable(hDlg);	break;
		////������ ����
		//case IDC_BUTTON7:	OnCreateSequence(hDlg);		break;
		////������ ����
		//case IDC_BUTTON8:	OnDropSequence(hDlg);		break;
		////========================================================
		////Team���
		//case IDC_BUTTON9:	OnInsertTeam(hDlg);		return 0;
	case IDCANCEL:		OnCancel(hDlg);			return 0;
	}
	return TRUE;
}

void OnDBConnect(HWND hDlg)
{
	if (wbdb_DBConnect() == TRUE)
	{
		MessageBox(NULL, TEXT("DB���� ����"), TEXT("�˸�"), MB_OK);
		SetWindowText(hDlg, TEXT("DB Connect"));
	}
	else
		MessageBox(NULL, TEXT("DB���� ����"), TEXT("�˸�"), MB_OK);
}

void OnDBDConnect(HWND hDlg)
{
	if (wbdb_DBDConnect() == TRUE)
	{
		MessageBox(NULL, TEXT("DB�������� ����"), TEXT("�˸�"), MB_OK);
		SetWindowText(hDlg, TEXT("DB DisConnect"));
	}
	else
		MessageBox(NULL, TEXT("DB�������� ����"), TEXT("�˸�"), MB_OK);
}

void AllPrint(HWND hDlg)
{
	vector<Customer> cslist;
	wbdb_GetTeamSelectAll(&cslist);
	ui_TeamListPrint(&cslist, cslist.size());
}

void OnSelect(HWND hDlg)
{
	int cs_id;
	TCHAR cs_name[20];
	TCHAR cs_phone[20];

	ui_GetTeamSelectInfo(hDlg, &cs_id, cs_name, cs_phone);
	vector<Customer> cslist;
	wbdb_GetTeamSelect(cs_id, cs_name, cs_phone, &cslist);
	ui_TeamListPrint(&cslist, cslist.size());
}

void OnInesert(HWND hDlg)
{
	int cs_id;
	TCHAR cs_name[20];
	TCHAR cs_gender[2];
	TCHAR cs_phone[20];

	ui_GetTeamCreateInfo(hDlg, &cs_id, cs_name, cs_gender, cs_phone);
	if (wbdb_InsertTeam(cs_id, cs_name, cs_gender, cs_phone) == TRUE)
	{
		vector<Customer> cslist;
		wbdb_GetTeamSelect(cs_id,cs_name,cs_phone,&cslist);
		ui_TeamListPrint(&cslist, cslist.size());
	}
	else
		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
}

void OnUpdate(HWND hDlg)
{
	int cs_id;
	TCHAR cs_name[20];
	TCHAR cs_phone[20];
	

	ui_GetTeamCreateInfo2(hDlg, &cs_id, cs_name, cs_phone);
	if (wbdb_UpdateTeam(cs_id, cs_name, cs_phone) == TRUE)
	{
		vector<Customer> cslist;
		wbdb_GetTeamSelectAll(&cslist);
		ui_TeamListPrint(&cslist, cslist.size());
	}
	else
		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
}

void OnDelete(HWND hDlg)
{
	int cs_id;

	ui_GetTeamCreateInfo1(hDlg, &cs_id);

	if (wbdb_DeleteTeam(cs_id) == TRUE)
	{
		vector<Customer> cslist;
		wbdb_GetTeamSelectAll(&cslist);
		ui_TeamListPrint(&cslist, cslist.size());
	}
	else
		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
}

void OnCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);

}

//DDL=========================================================
//void OnCreateTeamTable(HWND hDlg)
//{
//	if (wbdb_CreateTeamTable() == TRUE)
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//	else
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//}
//
//void OnDropTeamTable(HWND hDlg)
//{
//	if (wbdb_DropTeamTable() == TRUE)
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//	else
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//}
//
//void OnCreateMemberTable(HWND hDlg)
//{
//	if (wbdb_CreateMemberTable() == TRUE)
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//	else
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//}
//
//void OnDropMemberTable(HWND hDlg)
//{
//	if (wbdb_DropMemberTable() == TRUE)
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//	else
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//}
//
//void OnCreateSequence(HWND hDlg)
//{
//	if (wbdb_CreateSequence() == TRUE)
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//	else
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//}
//
//void OnDropSequence(HWND hDlg)
//{
//	if (wbdb_DropSequence() == TRUE)
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//	else
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//}
//==========================================================

//void OnInsertTeam(HWND hDlg)
//{
//	int   team_id;
//	TCHAR team_name[20];
//
//	ui_GetTeamCreateInfo(hDlg, &team_id, team_name);
//	if (wbdb_InsertTeam(team_id, team_name) == TRUE)
//	{
//		vector<TEAM> teamlist;
//		wbdb_GetTeamSelectAll(&teamlist);
//		ui_TeamListPrint(&teamlist, teamlist.size());
//	}
//	else
//		MessageBox(NULL, TEXT("����"), TEXT("�˸�"), MB_OK);
//}

/*
void OnPrint(HWND hDlg)
{
	GetProcessList(hDlg);
}

void GetProcessList(HWND hDlg)
{
	//���μ��� ����Ʈ ���
	vector<PROINFO> datalist;
	int size;
	pro_getProcessList(&datalist, &size);
	coll_proListSave(&datalist, size);
	ui_processListPrint(&datalist, size);
}
*/