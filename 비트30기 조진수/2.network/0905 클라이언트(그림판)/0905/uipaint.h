//uipaint.h

void uipaint_GetHandle(HWND hDlg);
void uipaint_InitCombo(HWND hDlg);
void uipaint_Drawing(HWND hDlg, POINTS pt);
void uipaint_PrintPoint(HWND hDlg, POINTS pt);
void uipaint_DrawColor(HWND hDlg);

COLORREF getColor(HWND hDlg);

COLORREF uipaint_GetColor(HWND hDlg);
void uipaint_Draw(POINTS pt, COLORREF color);
void uipaint_InfoPrint(COLORREF color, POINTS pt);