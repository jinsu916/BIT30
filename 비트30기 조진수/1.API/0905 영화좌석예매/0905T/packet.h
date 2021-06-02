//packet.h

//��Ŷ ����(APP �������� ����)

//Ŭ���̾�Ʈ => ����
#define PACK_INSERT		1
#define PACK_LOGIN      4
#define PACK_TIME		 5
#define PACK_TICKET      6

#define PACK_CONNECTED	 7	//�߰���

//���� => Ŭ���̾�Ʈ
#define ACK_INSERT_S    10
#define ACK_INSERT_F    11
#define ACK_LOGIN_S		17    
#define ACK_LOGIN_F		18  
#define ACK_CONNECTED_R 16

//��Ŷ ����ü 
typedef struct tagINSERT
{
	int flage;		//PACK���� �߰� 
	TCHAR id[20];
	TCHAR pw[20];
	TCHAR name[20];
	TCHAR phone[20];
}INSERT;
typedef struct tagLOGIN
{
	int flage;		//PACK���� �߰� 
	TCHAR id[20];
	TCHAR pw[20];
}LOGIN;
//��Ŷ ����ü 
typedef struct tagTICKET
{
	int flag;		//PACK���� �߰� 
	int sn;
}TICKET;


//typedef struct tagCONCERT
//{
//	int flage;      //
//	int month;
//	int day;
//	int time;      //ȸ������
//	TCHAR info[40];   //�ܼ�Ʈ����
//
//}CONCERT;

TICKET packet_Ticket(int &sn);
INSERT pack_Insert(TCHAR*id, TCHAR*pw, TCHAR*name, TCHAR*phone);
LOGIN pack_Login(TCHAR*id, TCHAR*pw);
