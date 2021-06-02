//packet.cpp
#include "std.h"

INSERT pack_Insert(TCHAR*id, TCHAR*pw, TCHAR*name, TCHAR*phone)
{
	INSERT pack;

	pack.flage = PACK_INSERT;
	_tcscpy_s(pack.id, id);
	_tcscpy_s(pack.pw, pw);
	_tcscpy_s(pack.name, name);
	_tcscpy_s(pack.phone, phone);

	return pack;
}

LOGIN pack_Login(TCHAR*id, TCHAR*pw)
{
	LOGIN pack;

	pack.flage = PACK_LOGIN;
	_tcscpy_s(pack.id, id);
	_tcscpy_s(pack.pw, pw);

	return pack;
}

TICKET packet_Ticket(int &sn)
{
	TICKET pack;

	pack.flag = PACK_TICKET;
	//_tcscpy_s(pack.seat, msg);
	pack.sn = sn;

	return pack;
}

