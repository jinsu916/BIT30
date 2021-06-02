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
	//if (flag == 1) //Ŭ���̾�Ʈ ����
	//	printf("[Ŭ���̾�Ʈ ����] %s\n", msg);
	//else if (flag == 2)
	//	printf("[���� ���� ���� ����] %s\n", msg);
}
void recvmessage(unsigned int sock, char *msg, int size)
{
	int *flag = (int*)msg;
	if (*flag == ACK_LOGIN_S)
	{
		//������ ���� ����ȯ�ؼ� ȹ��
		LOGIN *packet = (LOGIN*)msg;
		data3 = *packet;

		
		//���Ἲ��
		MessageBox(0, TEXT("�α��� ����"), TEXT("�˸�"), MB_OK);
		OnChild2(g_hDlg);
	}

	else if (*flag == ACK_LOGIN_F)		//�߰�
	{
		//������ ���� ����ȯ�ؼ� ȹ��
		LOGIN *packet = (LOGIN*)msg;
		MessageBox(0, TEXT("�α��� ����"), TEXT("�˸�"), MB_OK);
		//uiMessage_Print(packet->msg);
	}

	else if (*flag == PACK_TIME)
	{
		//������ ���� ����ȯ�ؼ� ȹ��
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
	
	//���� ���� ��û
	sock1 = wbclient_start(IP, PORT);
	if (sock1 == 0)
		MessageBox(0, TEXT("���� ����"), TEXT("�˸�"), MB_OK);

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

	//���� ���� ȹ��
	ui_GetConnectData(hDlg, id, pw);

	//��Ŷ ����
	LOGIN pack = pack_Login(id, pw);

	//����
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
		MessageBox(NULL, TEXT("���� ���"),
			TEXT("�˸�"), MB_OK);
		return;
	}
}

void OnInsert(HWND hDlg)
{
	TCHAR id[20], pw[20], name[20], phone[20];

	//���� ���� ȹ��
	ui_GetInsertData(hDlg, id, pw, name, phone);

	//��Ŷ ����
	INSERT pack = pack_Insert(id, pw, name, phone);

	//����
	wbclient_senddata(sock1, (char*)&pack, sizeof(pack));
}

void OnChild2(HWND hDlg)
{
	MEMBER mem2;
	//g_hDlg = 
	BOOL b = ui_Insert2(hDlg, &mem2);
	if (b == FALSE)
	{
		MessageBox(NULL, TEXT("���� ���"),
			TEXT("�˸�"), MB_OK);
		return;
	}
}
