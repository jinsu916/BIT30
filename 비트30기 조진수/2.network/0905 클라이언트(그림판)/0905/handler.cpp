//handler.cpp

#include "std.h"
#define IP		TEXT("192.168.0.52")
#define PORT	7000
int sock1;
void logmessage(int flag, const char *msg)
{
	//if (flag == 1) //클라이언트 접속
	//	printf("[클라이언트 접속] %s\n", msg);
	//else if (flag == 2)
	//	printf("[서버 연결 해제 해제] %s\n", msg);
}

void recvmessage(char *msg, int size)
{
	int *flag = (int*)msg;
	if (*flag == ACK_DRAW)
	{
		//데이터 강제 형변환해서 획득
		DRAW *packet = (DRAW*)msg;
		//[유아이페인트]해당 정보로 그림이 그려져야한다.
		uipaint_Draw(packet->color, packet->pt);
		//[유아이페인트]하단 컨트롤 정보가 변경
		uipaint_InfoPrint(packet->color, packet->pt);
	}
	
	/*else if (*flag == ACK_INSERT_F)
	{
		SELECT *packet = (SELECT*)msg;
		MessageBox(0, TEXT("회원가입실패"), packet->name, MB_OK);
	}
	else if (*flag == ACK_SELECT_S)
	{
		INSERT *packet = (INSERT*)msg;
		ui_SetInfoData(packet);
	}
	else if (*flag == ACK_SELECT_F)
	{
		SELECT *packet = (SELECT*)msg;
		MessageBox(0, TEXT("로그인실패"), packet->name, MB_OK);
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

	//그림그리기
	//uipaint_Drawing(hDlg, pt);
	//좌표 출력
	//uipaint_PrintPoint(hDlg, pt);

	//1.정보를 획득을 해
	COLORREF color = uipaint_GetColor(hDlg);

	//2.패킷 생성
	DRAW packet = packer_Draw(pt, color);

	//3. 전송(있음)
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
	if (HIWORD(wParam) == CBN_SELCHANGE) //선택 변경될때마다...
	{
		uipaint_DrawColor(hDlg);
	}
}