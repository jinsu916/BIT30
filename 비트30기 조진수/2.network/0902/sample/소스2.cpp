//바이트 정렬(p.12)
#include <WinSock2.h>				//소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")	//소켄 API 함수의 구현부
#include <stdio.h>

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
	//host->network
	unsigned short us = 0x1234; //2바이트
	unsigned long ul = 0x12345678;	//4바이트
	unsigned short nus = htons(us);
	unsigned long nul = htonl(ul);

	printf("%x => %x\n", us, nus);
	printf("%x => %x\n", ul, nul);
	//===================================================
	WSACleanup();
	return 0;
}