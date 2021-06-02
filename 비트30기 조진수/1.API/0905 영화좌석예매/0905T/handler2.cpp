#include "std.h"

extern int sock1;
extern int handle;
extern vector<HWND> checklist;



BOOL OnInitDialog2(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	//wbclient_init();
	//OnConnect(hDlg2);

	ui_GetControlHandle(hDlg);

	int msg = 7;
	wbclient_senddata(sock1, (char*)&msg, sizeof(msg));

	//ui_SetButtonEnable(FALSE);
	return 0;
}

BOOL OnCommand2(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL:			OnIdCancle(hDlg);		break;
	case IDOK:				OnClickButton(hDlg);    break;
	case IDC_CHECK1:		ui_check(hDlg, wParam); break;
	case IDC_CHECK2:		ui_check(hDlg, wParam); break;
	case IDC_CHECK3:		ui_check(hDlg, wParam); break;
	case IDC_CHECK4:		ui_check(hDlg, wParam); break;
	case IDC_CHECK5:		ui_check(hDlg, wParam); break;
	case IDC_CHECK6:		ui_check(hDlg, wParam); break;
	case IDC_CHECK7:		ui_check(hDlg, wParam); break;
	case IDC_CHECK8:		ui_check(hDlg, wParam); break;
	case IDC_CHECK9:		ui_check(hDlg, wParam); break;
	case IDC_CHECK10:		ui_check(hDlg, wParam); break;
	case IDC_CHECK11:		ui_check(hDlg, wParam); break;
	case IDC_CHECK12:		ui_check(hDlg, wParam); break;
	case IDC_CHECK13:		ui_check(hDlg, wParam); break;
	case IDC_CHECK14:		ui_check(hDlg, wParam); break;
	case IDC_CHECK15:		ui_check(hDlg, wParam); break;
	case IDC_CHECK16:		ui_check(hDlg, wParam); break;
	case IDC_CHECK17:		ui_check(hDlg, wParam); break;
	case IDC_CHECK18:		ui_check(hDlg, wParam); break;
	}
	return TRUE;
}
void OnIdCancle(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);

	//wbclient_sockclose(sock1);
	//wbclient_exit();
}
//void OnConnect2(HWND hDlg)
//{
//	TCHAR ip[60] = TEXT("192.168.0.22");
//	int port = 7000;
//
//
//	//서버 접속 요청
//	sock1 = wbclient_start((LPSTR)ip, port); //속성 -> 일반 -> 문자집합 에서 유니코드를 멀티바이트로 변경
//	if (sock1 == 0)
//	{
//		MessageBox(0, TEXT("연결실패"), TEXT("알림"), MB_OK);
//	}
//
//
//}

void OnClickButton(HWND hDlg)
{

	int ticket;
	TICKET packet;
	for (int i = 0; i < seatN; i++) //모든 좌석중 체크된 자석 찾기
	{
		ticket = ui_GetTicket(hDlg, i);
		if (ticket != 0) {
			packet = packet_Ticket(ticket);
			
			wbclient_senddata(sock1, (char*)&packet, sizeof(packet));
		}
	}
	int msg = 7;
	wbclient_senddata(sock1, (char*)&msg, sizeof(msg));
}

