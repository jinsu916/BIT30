//packet.cpp
#include <stdio.h>
#include <tchar.h>
#include "packet.h"

SELECT pack_insert(TCHAR *name)
{
	SELECT pack;

	pack.flage = ACK_INSERT_S;
	_tcscpy_s(pack.name, name);

	return pack;
}
