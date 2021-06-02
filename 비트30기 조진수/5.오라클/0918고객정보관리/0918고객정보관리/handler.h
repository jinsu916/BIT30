//handler.h

BOOL  OnInitDialog(HWND hDlg, WPARAM wParam, LPARAM lParam);
BOOL  OnCommand(HWND hDlg, WPARAM wParam, LPARAM lParam);

void OnDBConnect(HWND hDlg);
void OnDBDConnect(HWND hDlg);
void AllPrint(HWND hDlg);
//DDL=========================================================
//void OnCreateTeamTable(HWND hDlg);
//void OnDropTeamTable(HWND hDlg);
//void OnCreateMemberTable(HWND hDlg);
//void OnDropMemberTable(HWND hDlg);
//void OnCreateSequence(HWND hDlg);
//void OnDropSequence(HWND hDlg);
////==========================================================
//void OnInsertTeam(HWND hDlg);
//
//
void OnSelect(HWND hDlg);
void OnInesert(HWND hDlg);
void OnUpdate(HWND hDlg);
void OnDelete(HWND hDlg);
void OnCancel(HWND hDlg);
//void OnPrint(HWND hDlg);
//
//void GetProcessList(HWND hDlg);