//wbdb.h

//�����ͺ��̽� ����ϱ����� 2���� ���
#include <sql.h>
#include <sqlext.h>

BOOL wbdb_DBConnect();
BOOL wbdb_DBDConnect();

BOOL CommandSql(TCHAR *str);

BOOL wbdb_GetTeamSelectAll(vector<int>*csidlist);
BOOL wbdb_GetAcListtAll(vector<Account>*aclist);
BOOL wbdb_GetAccSelect(vector<Account>*accinfolist, int cs_id);
BOOL wbdb_GetAccSelect1(vector<Account>*accinfolist, int ac_id);

BOOL wbdb_InsertAcc(int cs_id);
BOOL wbdb_DeleteAcc(int ac_id);
BOOL wbdb_DeleteAllAcc(int cs_id);
