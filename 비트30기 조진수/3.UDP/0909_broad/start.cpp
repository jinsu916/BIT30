//start.cpp
#include "std.h"

#define RECVPORT 9000

CRITICAL_SECTION g_cs;

int main()
{
	InitializeCriticalSection(&g_cs);	//크리티컬섹션 초기화

	if (wbcommon_init() == 0)
	{
		printf("소켓 라이브러리 초기화 에러\n");
		return -1;
	}

	wbrecvber_start(RECVPORT);
	wbsenderbr_start(RECVPORT);

	while (1)
	{
		EnterCriticalSection(&g_cs);	//임계영역 초기화
		char buf[BUFSIZE + 1];
		// 데이터 입력
		if (fgets(buf, BUFSIZE + 1, stdin) == NULL)
			break;

		if (strlen(buf) == 0)
			break;

		int retval = wbsenderbr_senddata(buf, strlen(buf));
		if (retval == 0)
			continue;

		printf("%d바이트를 보냈습니다.\n", retval);

		LeaveCriticalSection(&g_cs);	//임계영역 종료
		Sleep(1);						//재우기
	}
	wbsenderbr_close();

	wbcommon_exit();

	DeleteCriticalSection(&g_cs);		//크리티컬섹션 종료
	return 0;
}