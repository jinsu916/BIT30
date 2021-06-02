//client.cpp (p.27)
#include <WinSock2.h>				//���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")	//���� API �Լ��� ������
#include <stdio.h>
#pragma warning(suppress : 4996)
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
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		printf("���� ���� ����\n");
		return -1;
	}
	//2.���� ���� ��ö
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET; //������
	serveraddr.sin_port = htons(7000);      //��Ʈ�p�� ������ �ȵȴ�.
	serveraddr.sin_addr.s_addr = inet_addr("192.168.137.1");
		//("127.0.0.1");

	int retval = connect(sock, (SOCKADDR*)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("���� ����\n");
		return -1;
	}
	printf("���� ����\n");
	
	while (1)
	{
		char buf[1024] = "";
		printf(">>");
		if (fgets(buf, sizeof(buf), stdin) == NULL)		//Ű�����Է�
			break;

		int length = strlen(buf);
		int retval = send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("�۽� ����\n");
			break;
		}
	}
	closesocket(sock);	//���� ����
	//===================================================
	WSACleanup();
	return 0;
}