//start.cpp
#include "std.h"

#define RECVPORT 9000

CRITICAL_SECTION g_cs;

int main()
{
	InitializeCriticalSection(&g_cs);	//ũ��Ƽ�ü��� �ʱ�ȭ

	if (wbcommon_init() == 0)
	{
		printf("���� ���̺귯�� �ʱ�ȭ ����\n");
		return -1;
	}

	wbrecvber_start(RECVPORT);
	wbsenderbr_start(RECVPORT);

	while (1)
	{
		EnterCriticalSection(&g_cs);	//�Ӱ迵�� �ʱ�ȭ
		char buf[BUFSIZE + 1];
		// ������ �Է�
		if (fgets(buf, BUFSIZE + 1, stdin) == NULL)
			break;

		if (strlen(buf) == 0)
			break;

		int retval = wbsenderbr_senddata(buf, strlen(buf));
		if (retval == 0)
			continue;

		printf("%d����Ʈ�� ���½��ϴ�.\n", retval);

		LeaveCriticalSection(&g_cs);	//�Ӱ迵�� ����
		Sleep(1);						//����
	}
	wbsenderbr_close();

	wbcommon_exit();

	DeleteCriticalSection(&g_cs);		//ũ��Ƽ�ü��� ����
	return 0;
}