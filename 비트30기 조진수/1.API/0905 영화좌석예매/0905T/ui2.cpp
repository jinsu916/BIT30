#include "std.h"


vector<HWND> checklist = { 0, };
static int ticket[seatN] = { 0, };
static int ticketed[seatN] = { 0, };
HWND g_hButton;


void ui_check(HWND hDlg, WPARAM wParam)
{
	BOOL chk;
	for (int i = 0; i < seatN; i++)
	{
		chk = (IsDlgButtonChecked(hDlg, IDC_CHECK1 + i) == BST_CHECKED);
		if (chk == TRUE)
		{
			ticket[i] = i + 1;
		}
	}
}

int ui_GetTicket(HWND hDlg, int &i)
{

	int t = -1;

	if ((i + 1) == ticket[i])
	{
		t = ticket[i];
	}

	return t;

}
int ui_GetTicketed(HWND hDlg, int &i)
{
	int t;
	t = ticketed[i];

	return t;
}
void ui_SetTicketed(int &i)
{
	ticketed[i - 1] = i - 1;
}
void ui_SetButtonEnable(BOOL f, int &i)
{
	if ((i - 1) == ticketed[i - 1])
		EnableWindow(checklist[i - 1], f);

}

void ui_GetControlHandle(HWND hDlg)
{
	for (int i = 0; i < seatN; i++)
	{
		HWND check = GetDlgItem(hDlg, IDC_CHECK1 + i);
		checklist.push_back(check);
	}



	g_hButton = GetDlgItem(hDlg, IDC_BUTTON1);
}