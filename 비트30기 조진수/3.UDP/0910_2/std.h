//std.h

#define WIN32_LEAN_AND_MEAN   //windows.h�� winsock2.h �浹 ����
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <commdlg.h>
#include <winsock2.h>   
#pragma comment(lib, "ws2_32.lib")

#include <commctrl.h>					//�Լ� �����
#pragma comment(lib, "comctl32.lib")	//�Լ� ������

#include <stdio.h>

#include <tchar.h>
#include "resource.h"

#include "handler.h"
#include "wbfile.h"
#include "wbmessage.h"
#include "uifile.h"