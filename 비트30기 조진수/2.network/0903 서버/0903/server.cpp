//1대1 통신 서버
#include <stdio.h>
#include "wbserver.h"

#define SERVER_PORT 7000

//flag 0 : 클라이언트 접속
void logmessage(int flag, const char *msg)
{
	if (flag == 1)	//클라이언트 접속
		printf("[클라이언트 접속]%s\n", msg);
	else if(flag == 2)	//접속 해제
		printf("[클라이언트 해제]%s\n", msg);
}

void recvmessage(char *msg, int size)
{
	msg[size] = '\0';		//retval => 실제 수신된 바이트의 크!기!
	printf("[수신데이터]%s\n", msg);
}

int main()
{
	//1.소켓을 사용하기 위해 반드시 최초 초기화 함수 호출
	if (wbserver_init() == 0)
	{
		printf("윈도우 소켓 초기화 실패\n");
		return -1;
	}
	printf("윈도우 소켓 초기화 성공\n");
	//================================================

	//2. 서버소켓 생성
	if (wbserver_start(SERVER_PORT) == 0)
	{
		printf("서버 소켓 생성 실패\n");
		return -1;
	}
	printf("서버 소켓 생성 성공\n");

	 
	//3. 서버 실행
	wbserver_run();
	//================================================

	//N. 소켓을 사용종료하기위해 반드시 프로그램 종료시 호출
	wbserver_exit();
	return 0;
}