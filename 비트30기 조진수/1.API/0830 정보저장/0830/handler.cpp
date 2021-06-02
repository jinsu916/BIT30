//handler.cpp
#include "std.h"

extern vector<MEMBER> g_memberlist;

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{

   InitCommonControls();			//공통컨트롤 정보획득

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
		MessageBox(NULL, TEXT("저장 취소"),
			TEXT("알림"), MB_OK);
		return;
	}

	//저장의 흐름
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

   case ID_FILE_EXIT: OnExit(hDlg);		break;	  //메뉴 프로그램 종료

   case ID_FUCTION_INSERT: OnInsert(hDlg); break; //메뉴 인서트
   }
   return TRUE;
}