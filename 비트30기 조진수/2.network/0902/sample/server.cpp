//서버
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
	//1.소켓 생성
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSock == INVALID_SOCKET)  //-1
	{
		printf("소켓생성 실패\n");
		return -1;
	}

	//2.주소 할당 (bind)
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET; //고정값
	serveraddr.sin_port = htons(7000);      //네트웤은 인지가 안된다.
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);   //이피씨의 아이피값을 바꿔서전달
	
	int retval = bind(listenSock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("bind()에러\n");
		return -1;
	}

	//3.개통(listen)
	retval = listen(listenSock, SOMAXCONN);		
	if (retval == SOCKET_ERROR)
	{
		printf("listen()에러\n");
		return -1;
	}
	//===============INIT CODE 의 END(기초코드)==========
	
	while (1)
	{
		//1.접속처리 (전화대기)
		SOCKADDR_IN clientaddr;
		int addrlen = sizeof(clientaddr);	//반드시 초기화
		SOCKET clientSock = accept(listenSock,(SOCKADDR*)&clientaddr,&addrlen);
		//2번째인자값은 클라이언트의 주소 및 통신소켓생성
		if (clientSock == INVALID_SOCKET)
		{
			printf("클라이언트 접속 실패\n");
			continue;//다시 접속
		}
		//=====클라이언트 접속===================================
		//2.클라이언트 정보 출력
		printf(">>클라이언트 접속: %s:%d\n",	
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
			//숫자형 아이피주소를 문자형으로
			//IP : 포트

		while (1)
		{
			char buf[1024];
			retval = recv(clientSock, buf, sizeof(buf), 0);
			if (retval == SOCKET_ERROR) //-1
			{
				printf("수신에러\n");	//잘안들려~ 끊어~
				break;
			}
			else if (retval == 0)
			{
				printf("상대방이 소켓을 닫은 경우\n");	//상대방이 종료
				break;
			}
			else
			{
				buf[retval] = '\0';		//retval => 실제 수신된 바이트의 크!기!
				printf("[%s:%d]%s",		//상대방의 아이피, 포트, 전송문자
					inet_ntoa(clientaddr.sin_addr),
					ntohs(clientaddr.sin_port),buf);
			}
		}
		closesocket(clientSock);
		printf(">>클라이언트 접속 해제: %s:%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	}


	//===================================================
	WSACleanup();
	return 0;
}