//wbserver.h
#include <WinSock2.h>				//소켓 API 함수의 선언부
#pragma comment(lib,"ws2_32.lib")	//소켄 API 함수의 구현부
int wbserver_init();
void wbserver_exit();
int wbserver_start(int port);
void wbserver_run();

SOCKET acceptclient();
void logmessage(int flag, SOCKET sock);
int recvdata(SOCKET sock, char *buf, int size);
int senddata(SOCKET sock, char *buf, int size);