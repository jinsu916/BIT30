//handler.h

BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam);
BOOL  OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);
void OnDBConnect(HWND hDlg);
void OnDBDConnect(HWND hDlg);

void OnAcAllListView(HWND hDlg);
void OnAcListView(HWND hDlg);
void OnAcFindview(HWND hDlg);
void OnAcInsert(HWND hDlg);
void OnAcDelete(HWND hDlg);
void OnAcDeleteAll(HWND hDlg);
void OnCancel(HWND hDlg);