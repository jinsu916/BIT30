//wbdb.h

//�����ͺ��̽� ����ϱ����� 2���� ���
#include <sql.h>
#include <sqlext.h>

BOOL wbdb_DBConnect();
BOOL wbdb_DBDConnect();

BOOL CommandSql(TCHAR *str);
BOOL wbdb_GetCSIDAll(vector<int>*csidlist);

