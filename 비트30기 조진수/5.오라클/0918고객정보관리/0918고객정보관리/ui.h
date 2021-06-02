//ui.h

void ui_GetTeamCreateInfo(HWND hDlg, int *cs_id, TCHAR*cs_name, TCHAR*cs_gender, TCHAR*cs_phone);
void ui_GetTeamCreateInfo1(HWND hDlg, int *cs_id);
void ui_GetTeamCreateInfo2(HWND hDlg, int *cs_id, TCHAR*cs_name, TCHAR*cs_phone);
void ui_InitTeamRadio(HWND hDlg);
void ui_InitTeamCombo(HWND hDlg);
void ui_InitTeamListView(HWND hDlg);
void ui_TeamListPrint(vector<Customer> *datalist, int size);
void ListTeamPrint(Customer info, int idx);
int ui_GetComboSel();
void ui_GetTeamSelectInfo(HWND hDlg, int *cs_id, TCHAR*cs_name, TCHAR*cs_phone);
//void ui_GetHandle(HWND hDlg);
//void ui_SetListViewColumnHeader(HWND hDlg);
//void ui_processListPrint(vector<PROINFO> *datalist, int size);
//void ListPrint(PROINFO info, int idx);