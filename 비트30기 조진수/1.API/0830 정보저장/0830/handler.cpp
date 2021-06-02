//handler.cpp
#include "std.h"

extern vector<MEMBER> g_memberlist;

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{

   InitCommonControls();			//������Ʈ�� ����ȹ��

   ui_GetControlHandle(hDlg);
   ui_InitListView(hDlg);


   return TRUE;
}

void OnCancel(HWND hDlg)
{
   EndDialog(hDlg, IDCANCEL);
}

void OnInsert(HWND hDlg)
{
	MEMBER mem;
	BOOL b = ui_Insert(hDlg, &mem);
	if (b == FALSE)
	{
		MessageBox(NULL, TEXT("���� ���"),
			TEXT("�˸�"), MB_OK);
		return;
	}

	//������ �帧
	g_memberlist.push_back(mem);

	ui_PrintAll(hDlg);
}

void OnExit(HWND hDlg)
{
	EndDialog(hDlg, IDOK);
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
   switch (LOWORD(wParam))
   {
   case IDCANCEL: OnCancel(hDlg);      break;

   case ID_FILE_EXIT: OnExit(hDlg);		break;	  //�޴� ���α׷� ����

   case ID_FUCTION_INSERT: OnInsert(hDlg); break; //�޴� �μ�Ʈ
   }
   return TRUE;
}