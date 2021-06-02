//std.h

#define WIN32_LEAN_AND_MEAN   //windows.h과 winsock2.h 충돌 방지
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <commdlg.h>
#include <winsock2.h>   
#pragma comment(lib, "ws2_32.lib")

#include <commctrl.h>					//함수 선언부
#pragma comment(lib, "comctl32.lib")	//함수 구현부

#include <stdio.h>

#include <tchar.h>
#include "resource.h"

#include "handler.h"
#include "wbfile.h"
#include "wbmessage.h"
#include "uifile.h"