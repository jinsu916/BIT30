//wbfile.h

struct FILE_INFO
{
	char FileName[260]; // ������ ���� �̸�.
	int  size;         // ȭ�� ũ��
};

void wbfile_Run();

DWORD WINAPI FileServer(void* p);
DWORD WINAPI RunThread(void* p);
