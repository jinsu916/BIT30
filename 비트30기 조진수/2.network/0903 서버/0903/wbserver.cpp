//wbserver.cpp
#include "wbserver.h"
#include <stdio.h>

static SOCKET listenSock;
//��ӵ� �Լ�--------------------------------
void logmessage(int flag, const char *msg);
void recvmessage(char *msg, int size);
//-------------------------------------------
int wbserver_init()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 0;
	return 1;
	
}

void wbserver_exit()
{
	WSACleanup();
}

int wbserver_start(int port)
{
	//1.���� ����
	listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSock == INVALID_SOCKET)  //-1
	{
		return 0;
	}

	//2.�ּ� �Ҵ� (bind)
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET; //������
	serveraddr.sin_port = htons(port);      //��Ʈ�p�� ������ �ȵȴ�.
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);   //���Ǿ��� �����ǰ��� �ٲ㼭����

	int retval = bind(listenSock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		return 0;
	}

	//3.����(listen)
	retval = listen(listenSock, SOMAXCONN);
	if (retval == SOCKET_ERROR)
	{
		return 0;
	}
	return 1;
}

void wbserver_run()
{
	while (1)
	{
		//1. ����ó��
		SOCKET clientsock = acceptclient();  
		if (clientsock == 0)
			continue;

		//2.Ŭ���̾�Ʈ ���� ���(����ڿ��� ����)
		logmessage(1, clientsock);
		
		while (1)
		{
			//3.�����͸� ����
			char buf[1024] = "";
			int retval = recvdata(clientsock, buf,sizeof(buf));
			if (retval == 0)
				break;
			
			//4.����ڿ��� ����
			recvmessage(buf, retval);
	
			//4.Ŭ���̾�Ʈ���� ��۽�
			senddata(clientsock, buf, strlen(buf));
		}
		//Ŭ���̾�Ʈ ���� ����
		closesocket(clientsock);
		logmessage(2, clientsock);	
	}
}

SOCKET acceptclient()
{
	//1.����ó�� (��ȭ���)
	SOCKADDR_IN clientaddr;
	int addrlen = sizeof(clientaddr);	//�ݵ�� �ʱ�ȭ
	SOCKET clientSock = accept(listenSock, (SOCKADDR*)&clientaddr, &addrlen);
	//2��°���ڰ��� Ŭ���̾�Ʈ�� �ּ� �� ��ż��ϻ���
	if (clientSock == INVALID_SOCKET)
		return 0;
	return clientSock;
}

void logmessage(int flag, SOCKET sock)
{
	char msg[100];
	SOCKADDR_IN clientaddr;
	int length = sizeof(clientaddr);
	getpeername(sock, (SOCKADDR*)&clientaddr, &length);
	sprintf_s(msg, "%s:%d", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

	logmessage(1, msg);
}

int recvdata(SOCKET sock, char *buf,int size)
{
	int retval = recv(sock, buf, size, 0);
	if (retval == SOCKET_ERROR || retval == 0) //-1
		return 0;
	return retval;
}

int senddata(SOCKET sock, char *buf, int size)
{
	return send(sock, buf, size, 0);
}
