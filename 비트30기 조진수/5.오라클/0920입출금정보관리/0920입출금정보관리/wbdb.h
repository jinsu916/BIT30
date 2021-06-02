//wbdb.h

//데이터베이스 사용하기위한 2가지 헤더
#include <sql.h>
#include <sqlext.h>

BOOL wbdb_DBConnect();
BOOL wbdb_DBDConnect();

BOOL CommandSql(TCHAR *str);
BOOL wbdb_GetCSIDAll(vector<int>*csidlist);

