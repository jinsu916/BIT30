//wbserver.h
#include <WinSock2.h>				//���� API �Լ��� �����
#pragma comment(lib,"ws2_32.lib")	//���� API �Լ��� ������
int wbserver_init();
void wbserver_exit();
int wbserver_start(int port);
void wbserver_run();

SOCKET acceptclient();
void logmessage(int flag, SOCKET sock);
int recvdata(SOCKET sock, char *buf, int size);
int senddata(SOCKET sock, char *buf, int size);