//InsertProc.cpp
#include "std.h"

BOOL CALLBACK InsertProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static MEMBER *pmem;
	static HWND g_hRadio1;  //핸들값
	static HWND g_hCombo1;  //핸들값
	switch (msg)
	{
	case WM_INITDIALOG:	 
		pmem = (MEMBER*)lParam;
		//컨트롤 초기화
		g_hRadio1 = GetDlgItem(hDlg, IDC_RADIO1);
		g_hCombo1 = GetDlgItem(hDlg, IDC_COMBO1);
		for (int i = 1; i <= 100; i++)  //콤보 숫자 나열
		{
			TCHAR temp[10];
			wsprintf(temp, TEXT("%d"), i);
			SendMessage(g_hCombo1, CB_ADDSTRING, 0, (LPARAM)temp);
		}
		return TRUE;

	case WM_COMMAND:			//p.146
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			//전달된 주소값을 이용 부모에게 자신의 정보를 전달
			//에디트박스 출력
			GetDlgItemText(hDlg, IDC_EDIT1, pmem->name, sizeof(pmem->name));
			//라디오박스 출력
			GetDlgItemText(hDlg, IDC_EDIT2, pmem->phone, sizeof(pmem->phone));
			if (SendMessage(g_hRadio1, BM_GETCHECK, 0, 0) == BST_CHECKED)
				pmem->gender = 'M';
			else
				pmem->gender = 'F';
			
			//콤보박스 출력
			int idx = SendMessage(g_hCombo1, CB_GETCURSEL, 0, 0);
			pmem->age = idx +1;
			
			//종료
			EndDialog(hDlg, IDOK);
		}
		return TRUE;

		case IDCANCEL: EndDialog(hDlg, IDCANCEL); return 0;
		}
		return TRUE;
	}
	return FALSE;
}