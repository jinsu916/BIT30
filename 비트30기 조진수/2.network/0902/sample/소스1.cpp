//IP �ּҺ���(p.10)
#include <WinSock2.h>				//���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")	//���� API �Լ��� ������)
#include <stdio.h>
#pragma warning(disable : 4996)

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
	//���ڿ� �ּ� ���
	char ipaddr[20] = "230.00.12.5";
	printf("IP���ڿ� : %s\n", ipaddr);

	int numaddr = inet_addr(ipaddr);
	printf("IP���� : %x\n", numaddr);

	//--------------------------------------------------
	IN_ADDR in_addr;
	in_addr.s_addr = inet_addr(ipaddr);  //inet_addr(ipaddr)
	printf("�ٽ� ���ڿ��� ��ȯ : %s\n", inet_ntoa(in_addr));

	//===================================================
	WSACleanup();
	return 0;
}