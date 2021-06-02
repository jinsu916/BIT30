//packet.h

//패킷 정의(APP 프로토콜 정의)

//클라이언트 => 서버
#define PACK_DRAW			1
#define PACK_MESSAGE		2

//서버 => 클라이언트
#define ACK_DRAW			10   //이름   SELECT
#define ACK_MESSAGE			11	 //이름   SELECT

//패킷 구조체 
typedef struct tagDRAW
{
	int flage;		//PACK정의 추가 
	POINTS pt;
	COLORREF color;
}DRAW;

typedef struct tagMESSAGE
{
	int flage;		//PACK정의 추가 
	TCHAR msg[100];
}MESSAGE;

DRAW packer_Draw(POINTS pt, COLORREF color);
MESSAGE pack_Message(TCHAR*msg);
//INSERT pack_Insert(TCHAR*id, TCHAR*pw, TCHAR*name, TCHAR*phone, int age);
//SELECT pack_Select(TCHAR*name);
//UPDATE pack_Update(TCHAR*name, TCHAR*phone, int age);
//SELECT pack_Delete(TCHAR*name);