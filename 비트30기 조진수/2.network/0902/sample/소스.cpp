//ȯ�� �����ϱ�
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

	//===================================================
	WSACleanup();
	return 0;
}