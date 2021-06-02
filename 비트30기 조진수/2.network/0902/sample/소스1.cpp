//IP 주소변경(p.10)
#include <WinSock2.h>				//소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")	//소켄 API 함수의 구현부)
#include <stdio.h>
#pragma warning(disable : 4996)

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
	//문자열 주소 출력
	char ipaddr[20] = "230.00.12.5";
	printf("IP문자열 : %s\n", ipaddr);

	int numaddr = inet_addr(ipaddr);
	printf("IP정수 : %x\n", numaddr);

	//--------------------------------------------------
	IN_ADDR in_addr;
	in_addr.s_addr = inet_addr(ipaddr);  //inet_addr(ipaddr)
	printf("다시 문자열로 변환 : %s\n", inet_ntoa(in_addr));

	//===================================================
	WSACleanup();
	return 0;
}