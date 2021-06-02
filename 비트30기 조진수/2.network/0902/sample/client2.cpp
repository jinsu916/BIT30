//client2.cpp (p.27)+스레드
#include <WinSock2.h>				//소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")	//소켄 API 함수의 구현부
#include <stdio.h>
#pragma warning(suppress : 4996)
#include <process.h>

int recvn(SOCKET s, char *buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0)
	{
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}
	return (len - left);
}

unsigned int __stdcall com_thread(void* value)
{
	SOCKET sock = (SOCKET)value;

	while (1)
	{
		char recvbuf[1024] = "";
		//=============서버코드 카비=========================
		//int recvdata(SOCKET sock, char *buf, int size)
		int size1;
		int retval = recvn(sock, (char*)&size1, sizeof(int), 0);
		if (retval == SOCKET_ERROR || retval == 0) //-1
			return 0;

		retval = recvn(sock, recvbuf, size1, 0);
		if (retval == SOCKET_ERROR || retval == 0) //-1
			return 0;
		//====================================================
	}
}

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("윈도우 소켓 초기화 실패\n");
		return -1;
	}
	printf("윈도우 소켓 초기화 성공\n");
	//===================================================
	//1.소켓 생성
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("소켓 생성 실패\n");
		return -1;
	}

	//2.서버 연결 요철
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET; //고정값
	serveraddr.sin_port = htons(7000);      //네트웤은 인지가 안된다.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.137.1");
	//("127.0.0.1");

	int retval = connect(sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("연결 실패\n");
		return -1;
	}

	printf("연결 성공\n");

	unsigned int h;		//리시브 스레드
	h = _beginthreadex(0, 0, com_thread, (void*)sock, 0, 0);
	CloseHandle((HANDLE)h);

	while (1)                //서버와의 데이터 통신
	{
		char buf[1024] = "";       //계속 초기화
		printf(">> ");
		if (fgets(buf, sizeof(buf), stdin) == '\0')         //그냥 엔터쳤을때 종료
			break;

		int length = strlen(buf) + 1;
		send(sock, (char*)& length, sizeof(int), 0);
		send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("송신에러\n");
			break;
		}
	}

	closesocket(sock);	//소켓 종료
						//===================================================
	WSACleanup();
	return 0;
}