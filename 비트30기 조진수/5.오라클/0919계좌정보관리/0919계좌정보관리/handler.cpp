//handler.cpp

#include "std.h"

BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	//������Ʈ��
	InitCommonControls();

	//����Ʈ��Ʈ�� �ʱ�ȭ
	ui_InitTeamListView(hDlg);
	//�޺��ڽ� �ڵ鷯
	ui_InitTeamComboView(hDlg);
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
		//���� ���� ��ü ���
	case IDC_BUTTON7:	OnAcAllListView(hDlg);	return 0;
		//��ID�� ����ã��
	case IDC_BUTTON3:	OnAcListView(hDlg);		return 0;
		//���� ����
	case IDC_BUTTON4:	OnAcInsert(hDlg);		return 0;
		//���� ����
	case IDC_BUTTON5:	OnAcDelete(hDlg);		return 0;
		//�ش� ��ID�� ��� ���� ����
	case IDC_BUTTON6:	OnAcDeleteAll(hDlg);	return 0;
		//����ID �� ã��
	case IDC_BUTTON8:	OnAcFindview(hDlg);	return 0;
		//���
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

		vector<int> csidlist;
		wbdb_GetTeamSelectAll(&csidlist);
		ui_TeamComboListPrint(&csidlist, csidlist.size());
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

void OnAcAllListView(HWND hDlg)
{
	vector<Account> aclist;
	wbdb_GetAcListtAll(&aclist);
	ui_AcListPrint(&aclist, aclist.size());
}

void OnAcListView(HWND hDlg)
{
	int cs_id;
	ui_getcombocustid(hDlg, &cs_id);

	vector<Account> aclist;
	wbdb_GetAccSelect(&aclist, cs_id);
	ui_AcListPrint(&aclist, aclist.size());
}

void OnAcFindview(HWND hDlg)
{
	int ac_id;
	ui_GetDeleteacid(hDlg, &ac_id);

	vector<Account> aclist;
	wbdb_GetAccSelect1(&aclist, ac_id);
	ui_AcListPrint(&aclist, aclist.size());
}

void OnAcInsert(HWND hDlg)
{
	int cs_id;

	ui_getcombocustid(hDlg, &cs_id);

	if (wbdb_InsertAcc(cs_id) == TRUE)
	{
		vector<Account> acclist;
		wbdb_GetAccSelect(&acclist, cs_id);
		ui_AcListPrint(&acclist, acclist.size());
		MessageBox(NULL, TEXT("��ϼ���"), TEXT("�˸�"), MB_OK);
	}
	else
		MessageBox(NULL, TEXT("��Ͻ���"), TEXT("�˸�"), MB_OK);

}

void OnAcDelete(HWND hDlg)
{
	int ac_id;

	ui_GetDeleteacid(hDlg, &ac_id);

	if (wbdb_DeleteAcc(ac_id) == TRUE)
	{
		vector<Account> aclist;
		wbdb_GetAcListtAll(&aclist);
		ui_AcListPrint(&aclist, aclist.size());
		MessageBox(NULL, TEXT("��������"), TEXT("�˸�"), MB_OK);
	}
	else
		MessageBox(NULL, TEXT("��������"), TEXT("�˸�"), MB_OK);

}

void OnAcDeleteAll(HWND hDlg)
{
	int cs_id;

	ui_getcombocustid(hDlg, &cs_id);

	if (wbdb_DeleteAllAcc(cs_id) == TRUE)
	{
		vector<Account> aclist;
		wbdb_GetAcListtAll(&aclist);
		ui_AcListPrint(&aclist, aclist.size());
		MessageBox(NULL, TEXT("��������"), TEXT("�˸�"), MB_OK);
	}
	else
		MessageBox(NULL, TEXT("��������"), TEXT("�˸�"), MB_OK);

}

void OnCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);

}