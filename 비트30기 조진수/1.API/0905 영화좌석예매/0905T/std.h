#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <commctrl.h>					//�Լ� �����
#pragma comment(lib, "comctl32.lib")	//�Լ� ������

#include <tchar.h>
#include <vector>
using namespace std;
#include "resource.h"

#define seatN 19
#include "member.h"


#include "ui.h"
#include "ui2.h"
#include "packet.h"
#include "handler.h"
#include "handler2.h"
#include "InsertProc.h"
#include "InsertProc2.h"
#include "wbclient.h"