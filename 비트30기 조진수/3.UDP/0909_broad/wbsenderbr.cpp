////wbsecderbr.cpp
#include "std.h"

SOCKET send_sock;
SOCKADDR_IN remoteaddr;

int wbsenderbr_start(int port)
{
	ssocket_init(port);
	return 1;
}

int ssocket_init(int port)
{
	// socket()
	send_sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (send_sock == INVALID_SOCKET) wbcommon_errquit((char*)"socket()");

	// 브로드캐스팅 활성화
	BOOL      bEnable = TRUE;
	int retval = setsockopt(send_sock, SOL_SOCKET, SO_BROADCAST,
		(char*)&bEnable, sizeof(bEnable));
	if (retval == SOCKET_ERROR)
		wbcommon_errquit((char*)"setsockopt()");

	// 소켓 주소 구조체 초기화
	ZeroMemory(&remoteaddr, sizeof(remoteaddr));
	remoteaddr.sin_family = AF_INET;
	remoteaddr.sin_port = htons(port);
	//-------------------------------------------------------
	remoteaddr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
	//-------------------------------------------------------

	return 1;
}

int wbsenderbr_senddata(char* buf, int size)
{
	// 데이터 보내기
	int retval = sendto(send_sock, buf, size, 0,
		(SOCKADDR*)&remoteaddr, sizeof(remoteaddr));
	if (retval == SOCKET_ERROR)
	{
		wbcommon_errdisplay((char*)"sendto");
		return 0;
	}
	return retval;
}

void wbsenderbr_close()
{
	closesocket(send_sock);
}