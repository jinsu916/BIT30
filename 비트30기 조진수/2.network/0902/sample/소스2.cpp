//����Ʈ ����(p.12)
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
	//host->network
	unsigned short us = 0x1234; //2����Ʈ
	unsigned long ul = 0x12345678;	//4����Ʈ
	unsigned short nus = htons(us);
	unsigned long nul = htonl(ul);

	printf("%x => %x\n", us, nus);
	printf("%x => %x\n", ul, nul);
	//===================================================
	WSACleanup();
	return 0;
}