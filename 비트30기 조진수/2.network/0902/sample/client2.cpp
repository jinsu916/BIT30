//client2.cpp (p.27)+������
#include <WinSock2.h>				//���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")	//���� API �Լ��� ������
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
		//=============�����ڵ� ī��=========================
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

	unsigned int h;		//���ú� ������
	h = _beginthreadex(0, 0, com_thread, (void*)sock, 0, 0);
	CloseHandle((HANDLE)h);

	while (1)                //�������� ������ ���
	{
		char buf[1024] = "";       //��� �ʱ�ȭ
		printf(">> ");
		if (fgets(buf, sizeof(buf), stdin) == '\0')         //�׳� ���������� ����
			break;

		int length = strlen(buf) + 1;
		send(sock, (char*)& length, sizeof(int), 0);
		send(sock, buf, length, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("�۽ſ���\n");
			break;
		}
	}

	closesocket(sock);	//���� ����
						//===================================================
	WSACleanup();
	return 0;
}