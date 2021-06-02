//handler.cpp
#include "std.h"
#define IP		TEXT("192.168.0.22")
#define PORT	7000
int sock1;
extern vector<MEMBER> g_memberlist;
HWND g_hDlg;
LOGIN data3;

void logmessage(int flag, const char *msg)
{
	//if (flag == 1) //클라이언트 접속
	//	printf("[클라이언트 접속] %s\n", msg);
	//else if (flag == 2)
	//	printf("[서버 연결 해제 해제] %s\n", msg);
}
void recvmessage(unsigned int sock, char *msg, int size)
{
	int *flag = (int*)msg;
	if (*flag == ACK_LOGIN_S)
	{
		//데이터 강제 형변환해서 획득
		LOGIN *packet = (LOGIN*)msg;
		data3 = *packet;

		
		//연결성공
		MessageBox(0, TEXT("로그인 성공"), TEXT("알림"), MB_OK);
		OnChild2(g_hDlg);
	}

	else if (*flag == ACK_LOGIN_F)		//추가
	{
		//데이터 강제 형변환해서 획득
		LOGIN *packet = (LOGIN*)msg;
		MessageBox(0, TEXT("로그인 실패"), TEXT("알림"), MB_OK);
		//uiMessage_Print(packet->msg);
	}

	else if (*flag == PACK_TIME)
	{
		//데이터 강제 형변환해서 획득
		TICKET *packet = (TICKET*)msg;
	}
	else if (*flag == ACK_CONNECTED_R)
	{
		TICKET *packet = (TICKET*)msg;
		TICKET data = *packet;
		int sn = data.sn;
		sn += 1;
		if (data.sn != 0)
		{
			ui_SetTicketed(sn);
			ui_SetButtonEnable(FALSE, sn);
		}
	}
}
BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	//InitCommonControls();
	wbclient_init();
	
	//서버 접속 요청
	sock1 = wbclient_start(IP, PORT);
	if (sock1 == 0)
		MessageBox(0, TEXT("연결 실패"), TEXT("알림"), MB_OK);

	return TRUE;
}

BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL:		OnCancel(hDlg);		break;
	case IDC_BUTTON1:	OnConnect(hDlg);	break;
	case IDC_BUTTON2:   OnChild(hDlg);		break;
	}
	return TRUE;
}


void OnConnect(HWND hDlg)
{
	TCHAR id[20], pw[20];

	//전달 정보 획득
	ui_GetConnectData(hDlg, id, pw);

	//패킷 정의
	LOGIN pack = pack_Login(id, pw);

	//전송
	wbclient_senddata(sock1, (char*)&pack, sizeof(pack));
}
void OnCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);
	wbclient_exit();
}

void OnChild(HWND hDlg)
{
	MEMBER mem;
	BOOL b = ui_Insert(hDlg, &mem);
	if (b == FALSE)
	{
		MessageBox(NULL, TEXT("저장 취소"),
			TEXT("알림"), MB_OK);
		return;
	}
}

void OnInsert(HWND hDlg)
{
	TCHAR id[20], pw[20], name[20], phone[20];

	//전달 정보 획득
	ui_GetInsertData(hDlg, id, pw, name, phone);

	//패킷 정의
	INSERT pack = pack_Insert(id, pw, name, phone);

	//전송
	wbclient_senddata(sock1, (char*)&pack, sizeof(pack));
}

void OnChild2(HWND hDlg)
{
	MEMBER mem2;
	//g_hDlg = 
	BOOL b = ui_Insert2(hDlg, &mem2);
	if (b == FALSE)
	{
		MessageBox(NULL, TEXT("저장 취소"),
			TEXT("알림"), MB_OK);
		return;
	}
}
