//handler.cpp

#include "std.h"
#define IP		TEXT("192.168.0.52")
#define PORT	7000
int sock1;
void logmessage(int flag, const char *msg)
{
	//if (flag == 1) //Ŭ���̾�Ʈ ����
	//	printf("[Ŭ���̾�Ʈ ����] %s\n", msg);
	//else if (flag == 2)
	//	printf("[���� ���� ���� ����] %s\n", msg);
}

void recvmessage(char *msg, int size)
{
	int *flag = (int*)msg;
	if (*flag == ACK_DRAW)
	{
		//������ ���� ����ȯ�ؼ� ȹ��
		DRAW *packet = (DRAW*)msg;
		//[����������Ʈ]�ش� ������ �׸��� �׷������Ѵ�.
		uipaint_Draw(packet->color, packet->pt);
		//[����������Ʈ]�ϴ� ��Ʈ�� ������ ����
		uipaint_InfoPrint(packet->color, packet->pt);
	}
	
	/*else if (*flag == ACK_INSERT_F)
	{
		SELECT *packet = (SELECT*)msg;
		MessageBox(0, TEXT("ȸ�����Խ���"), packet->name, MB_OK);
	}
	else if (*flag == ACK_SELECT_S)
	{
		INSERT *packet = (INSERT*)msg;
		ui_SetInfoData(packet);
	}
	else if (*flag == ACK_SELECT_F)
	{
		SELECT *packet = (SELECT*)msg;
		MessageBox(0, TEXT("�α��ν���"), packet->name, MB_OK);
	}*/
}

BOOL OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	uimsg_GetHandle(hDlg);
	uipaint_GetHandle(hDlg);
	uipaint_InitCombo(hDlg);

	uimsg_SetName(hDlg);
	ui_SetAddress(hDlg, IP, PORT);
	wbclient_init();
	return TRUE;
}

BOOL OnLButtonDown(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	POINTS pt = MAKEPOINTS(lParam);

	//�׸��׸���
	//uipaint_Drawing(hDlg, pt);
	//��ǥ ���
	//uipaint_PrintPoint(hDlg, pt);

	//1.������ ȹ���� ��
	COLORREF color = uipaint_GetColor(hDlg);

	//2.��Ŷ ����
	DRAW packet = packer_Draw(pt, color);

	//3. ����(����)
	wbclient_senddata(sock1, (char*)&pack, sizeof(pack));
	return TRUE;
}


BOOL OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam)
{
	switch (LOWORD(wParam))
	{
	case IDCANCEL:			OnIdCancel(hDlg);		break;
	case IDC_BUTTON1:		OnClickButton(hDlg);    break;
	case IDC_COMBO1:		OnComboBoxSelChange(hDlg, wParam); break;
	}
	return TRUE;
}

void OnIdCancel(HWND hDlg)
{
	EndDialog(hDlg, IDCANCEL);
}

void OnClickButton(HWND hDlg)
{
	TCHAR msg[100];
	if (uimsg_GetMessage(hDlg, msg) == FALSE)
		return;

	uimsg_DisplayText(hDlg, msg);
}

void OnComboBoxSelChange(HWND hDlg, WPARAM wParam)
{
	if (HIWORD(wParam) == CBN_SELCHANGE) //���� ����ɶ�����...
	{
		uipaint_DrawColor(hDlg);
	}
}