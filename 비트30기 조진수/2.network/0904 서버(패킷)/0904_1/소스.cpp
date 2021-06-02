//���� ��� �ڵ� sample
#include <stdio.h>
#include <vector>
using namespace std;
#include "wbserver.h"
#include "packet.h"

#define SERVER_PORT 7000
extern unsigned int handle;

vector<INSERT> g_memberlist;

//flag 0 : Ŭ���̾�Ʈ ����
void logmessage(int flag, const char *msg)
{
	if (flag == 1) //Ŭ���̾�Ʈ ����
		printf("[Ŭ���̾�Ʈ ����] %s\n", msg);
	else if (flag == 2)
		printf("[Ŭ���̾�Ʈ ����] %s\n", msg);
}

void recvmessage(char *msg, int size)
{
	int *flag = (int*)msg;
	if (*flag == PACK_INSERT)
	{
		INSERT *packet = (INSERT*)msg;
		INSERT data = *packet;
		g_memberlist.push_back(data);

		SELECT pack = pack_insert(data.name);
		senddata(handle, (char*)&pack, sizeof(pack));
	}
	else if (*flag == PACK_SELECT)
	{
		
	}

	//=============���� ��� ==============
	system("cls");
	for (int i = 0; i < (int)g_memberlist.size(); i++)
	{
		INSERT data = g_memberlist[i];
		printf("%s %s %s %d %s\n",
			data.id, data.pw, data.name, data.age, data.phone);
	}
}

int main()
{
	//1. ������ ����ϱ� ���� �ݵ�� ���� �ʱ�ȭ �Լ� ȣ��
	if (wbserver_init() == 0)
	{
		printf("������ ���� �ʱ�ȭ ����\n");
		return -1;
	}
	printf("������ ���� �ʱ�ȭ ����\n");
	//==========================================================

	//2. ���� ���� ���� 
	if (wbserver_start(SERVER_PORT) == 0)
	{
		printf("���� ���� ���� ����\n");
		return -1;
	}
	printf("���� ���� ���� ����\n");
	printf("192.168.0.52:7000\n");

	WaitForSingleObject((HANDLE)handle, INFINITE);

	//===========================================================
	//N. ������ ��������ϱ� ���� �ݵ�� ���α׷� ����� ȣ�� 
	wbserver_exit();
	return 0;
}