//packet.h

//패킷 정의(APP 프로토콜 정의)

//클라이언트 => 서버
#define PACK_INSERT		1
#define PACK_LOGIN      4
#define PACK_TIME		 5
#define PACK_TICKET      6

#define PACK_CONNECTED	 7	//추가함

//서버 => 클라이언트
#define ACK_INSERT_S    10
#define ACK_INSERT_F    11
#define ACK_LOGIN_S		17    
#define ACK_LOGIN_F		18  
#define ACK_CONNECTED_R 16

//패킷 구조체 
typedef struct tagINSERT
{
	int flage;		//PACK정의 추가 
	TCHAR id[20];
	TCHAR pw[20];
	TCHAR name[20];
	TCHAR phone[20];
}INSERT;
typedef struct tagLOGIN
{
	int flage;		//PACK정의 추가 
	TCHAR id[20];
	TCHAR pw[20];
}LOGIN;
//패킷 구조체 
typedef struct tagTICKET
{
	int flag;		//PACK정의 추가 
	int sn;
}TICKET;


//typedef struct tagCONCERT
//{
//	int flage;      //
//	int month;
//	int day;
//	int time;      //회차정보
//	TCHAR info[40];   //콘서트정보
//
//}CONCERT;

TICKET packet_Ticket(int &sn);
INSERT pack_Insert(TCHAR*id, TCHAR*pw, TCHAR*name, TCHAR*phone);
LOGIN pack_Login(TCHAR*id, TCHAR*pw);
