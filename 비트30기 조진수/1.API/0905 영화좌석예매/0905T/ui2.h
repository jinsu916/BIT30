#pragma once

void ui_SetButtonEnable(BOOL f, int &i);
void ui_check(HWND hDlg, WPARAM wParam);
void ui_GetControlHandle(HWND hDlg);
int ui_GetTicket(HWND hDlg, int &i);
int ui_GetTicketed(HWND hDlg, int &i);
void ui_SetTicketed(int &i);