//packet.cpp
#include "std.h"

DRAW packer_Draw(POINTS pt, COLORREF color)
{
	DRAW pack;

	pack.flage = PACK_DRAW;
	pack.pt = pt;
	pack.color = color;

	return pack;
}

MESSAGE pack_Message(TCHAR*msg)
{
	MESSAGE pack;

	pack.flage = PACK_MESSAGE;
	_tcscpy_s(pack.msg, msg);

	return pack;
}
