//ui.h

void ui_InitTeamComboView(HWND hDlg);
void ui_InitTeamListView(HWND hDlg);
void ui_getcombocustid(HWND hDlg, int *cs_id);
void ui_GetDeleteacid(HWND hDlg, int *ac_id);
void ui_TeamComboListPrint(vector<int> *datalist, int size);
void ui_AcListPrint(vector<Account> *datalist, int size);
void ListAcPrint(Account info, int idx);
