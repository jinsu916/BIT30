//����
#include <WinSock2.h>				//���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")	//���� API �Լ��� ������
#include <stdio.h>

int main()
{
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("������ ���� �ʱ�ȭ ����\n");
		return -1;
	}
	printf("������ ���� �ʱ�ȭ ����\n");
	//===================================================
	//1.���� ����
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSock == INVALID_SOCKET)  //-1
	{
		printf("���ϻ��� ����\n");
		return -1;
	}

	//2.�ּ� �Ҵ� (bind)
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET; //������
	serveraddr.sin_port = htons(7000);      //��Ʈ�p�� ������ �ȵȴ�.
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);   //���Ǿ��� �����ǰ��� �ٲ㼭����
	
	int retval = bind(listenSock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("bind()����\n");
		return -1;
	}

	//3.����(listen)
	retval = listen(listenSock, SOMAXCONN);		
	if (retval == SOCKET_ERROR)
	{
		printf("listen()����\n");
		return -1;
	}
	//===============INIT CODE �� END(�����ڵ�)==========
	
	while (1)
	{
		//1.����ó�� (��ȭ���)
		SOCKADDR_IN clientaddr;
		int addrlen = sizeof(clientaddr);	//�ݵ�� �ʱ�ȭ
		SOCKET clientSock = accept(listenSock,(SOCKADDR*)&clientaddr,&addrlen);
		//2��°���ڰ��� Ŭ���̾�Ʈ�� �ּ� �� ��ż��ϻ���
		if (clientSock == INVALID_SOCKET)
		{
			printf("Ŭ���̾�Ʈ ���� ����\n");
			continue;//�ٽ� ����
		}
		//=====Ŭ���̾�Ʈ ����===================================
		//2.Ŭ���̾�Ʈ ���� ���
		printf(">>Ŭ���̾�Ʈ ����: %s:%d\n",	
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
			//������ �������ּҸ� ����������
			//IP : ��Ʈ

		while (1)
		{
			char buf[1024];
			retval = recv(clientSock, buf, sizeof(buf), 0);
			if (retval == SOCKET_ERROR) //-1
			{
				printf("���ſ���\n");	//�߾ȵ��~ ����~
				break;
			}
			else if (retval == 0)
			{
				printf("������ ������ ���� ���\n");	//������ ����
				break;
			}
			else
			{
				buf[retval] = '\0';		//retval => ���� ���ŵ� ����Ʈ�� ũ!��!
				printf("[%s:%d]%s",		//������ ������, ��Ʈ, ���۹���
					inet_ntoa(clientaddr.sin_addr),
					ntohs(clientaddr.sin_port),buf);
			}
		}
		closesocket(clientSock);
		printf(">>Ŭ���̾�Ʈ ���� ����: %s:%d\n",
			inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
	}


	//===================================================
	WSACleanup();
	return 0;
}