//InsertProc.cpp
#include "std.h"
//extern vector<MEMBER> g_memberlist;
BOOL CALLBACK InsertProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static MEMBER *pmem;
	switch (msg)
	{
	case WM_INITDIALOG:
		pmem = (MEMBER*)lParam;

	case WM_COMMAND:			//p.146
		switch (LOWORD(wParam))
		{

		case IDC_BUTTON3:
		{
			//전달된 주소값을 이용 부모에게 자신의 정보를 전달
			//에디트박스 출력
			GetDlgItemText(hDlg, IDC_EDIT1, pmem->id, sizeof(pmem->id));
			GetDlgItemText(hDlg, IDC_EDIT2, pmem->pw, sizeof(pmem->pw));
			GetDlgItemText(hDlg, IDC_EDIT3, pmem->name, sizeof(pmem->name));
			GetDlgItemText(hDlg, IDC_EDIT4, pmem->phone, sizeof(pmem->phone));
			
			OnInsert(hDlg);
			
			EndDialog(hDlg, IDOK);
		}
		return TRUE;

		case IDCANCEL: EndDialog(hDlg, IDOK); return 0;
		case IDC_BUTTON4: EndDialog(hDlg, IDOK); return 0;

		}
		return TRUE;
	}
	return FALSE;
}

void ui_GetInsertData(HWND hDlg, TCHAR* id, TCHAR* pw, TCHAR* name, TCHAR* phone)
{
	GetDlgItemText(hDlg, IDC_EDIT1, id, sizeof(TCHAR) * 20);
	GetDlgItemText(hDlg, IDC_EDIT2, pw, sizeof(TCHAR) * 20);
	GetDlgItemText(hDlg, IDC_EDIT3, name, sizeof(TCHAR) * 20);
	GetDlgItemText(hDlg, IDC_EDIT4, phone, sizeof(TCHAR) * 20);
}
