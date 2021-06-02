//client.cpp (p.27)
#include <WinSock2.h>				//소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")	//소켄 API 함수의 구현부
#include <stdio.h>
#pragma warning(suppress : 4996)
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
	
	while (1)
	{
		char buf[1024] = "";
		printf(">>");
		if (fgets(buf, sizeof(buf), stdin) == NULL)		//키보드입력
			break;

		int length = strlen(buf);
		int retval = send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("송신 에러\n");
			break;
		}
	}
	closesocket(sock);	//소켓 종료
	//===================================================
	WSACleanup();
	return 0;
}