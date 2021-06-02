//wbdb.cpp

#include "std.h"

#define DBNAME  TEXT("wb30db")
#define ID	    TEXT("wb30")
#define PW		TEXT("1234")

SQLHSTMT hStmt;
SQLHENV hEnv;
SQLHDBC hDbc;

BOOL wbdb_DBConnect()
{

	// 연결 설정을 위한 변수들
	SQLRETURN Ret;

	// 1, 환경 핸들을 할당하고 버전 속성을 설정한다.(p1741)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
		return false;
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
		return false;

	// 2. 연결 핸들을 할당하고 연결한다.
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
		return false;
	// 오라클 서버에 연결하기
	Ret = SQLConnect(hDbc, (SQLTCHAR *)DBNAME, SQL_NTS, (SQLTCHAR *)ID, SQL_NTS, (SQLTCHAR *)PW, SQL_NTS);

	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
		return false;

	// 명령 핸들을 할당한다.
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) != SQL_SUCCESS)
		return false;

	return true;
}

BOOL wbdb_DBDConnect()
{
	// 뒷정리
	if (hStmt) SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	if (hDbc) SQLDisconnect(hDbc);
	if (hDbc) SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	if (hEnv) SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

	return TRUE;
}

// SQL 명령 전달
BOOL CommandSql(TCHAR *str)
{
	// 전달됐는지 확인. 디버깅할때 여기서 멈춰서 확인
	if (SQLExecDirect(hStmt, (SQLTCHAR *)str, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}
	return TRUE;
}

//콤보박스출력
BOOL wbdb_GetTeamSelectAll(vector<int>*csidlist)
{
	int cs_id;
	SQLINTEGER Ics_id;

	//컬럼과 데이터를 연결
	SQLBindCol(hStmt, 1, SQL_C_ULONG, &cs_id, 0, &Ics_id);

	TCHAR sql[256] = TEXT("select cs_id from customer");

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		int data;
		data = cs_id;
		csidlist->push_back(data);
		
	}
	return TRUE;
}

//전체출력
BOOL wbdb_GetAcListtAll(vector<Account>*aclist)
{
	int ac_id;
	int ac_money;
	SQLTCHAR ac_date[20];
	int ac_count;
	int cs_id;
	SQLINTEGER lac_id, lac_money, lac_date, lac_count, lcs_id;

	//컬럼과 데이터를 연결
	SQLBindCol(hStmt, 1, SQL_C_ULONG, &ac_id, 0, &lac_id);
	SQLBindCol(hStmt, 2, SQL_C_ULONG, &ac_money, 0, &lac_money);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, ac_date, sizeof(ac_date), &lac_date);
	SQLBindCol(hStmt, 4, SQL_C_ULONG, &ac_count, 0, &lac_count);
	SQLBindCol(hStmt, 5, SQL_C_ULONG, &cs_id, 0, &lcs_id);

	TCHAR sql[256] = TEXT("select * from account;");

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		Account data;
		data.ac_id = ac_id;
		data.ac_money = ac_money;
		_tcscpy_s(data.ac_date, ac_date);
		data.ac_count = ac_count;
		data.cs_id = cs_id;
		aclist->push_back(data);
	}
	return TRUE;
}

BOOL wbdb_GetAccSelect(vector<Account>*accinfolist, int cs_id)
{
	int ac_id;
	int ac_money;
	SQLTCHAR ac_date[20];
	int ac_count;
	int cs_id1;
	SQLINTEGER lac_id, lac_money, lac_date, lac_count, lcs_id1;

	SQLBindCol(hStmt, 1, SQL_C_ULONG, &ac_id, 0, &lac_id);
	SQLBindCol(hStmt, 2, SQL_C_ULONG, &ac_money, 0, &lac_money);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, ac_date, sizeof(ac_date), &lac_date);
	SQLBindCol(hStmt, 4, SQL_C_ULONG, &ac_count, 0, &lac_count);
	SQLBindCol(hStmt, 5, SQL_C_ULONG, &cs_id1, 0, &lcs_id1);


	TCHAR sql[256]; 
	wsprintf(sql,TEXT("select * from account where cs_id = %d"),cs_id);

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		Account acclist;
		acclist.ac_id = ac_id;
		acclist.ac_money = ac_money;
		_tcscpy_s(acclist.ac_date, ac_date);
		acclist.ac_count = ac_count;
		acclist.cs_id = cs_id1;

		accinfolist->push_back(acclist);
	}

	return TRUE;
}

BOOL wbdb_GetAccSelect1(vector<Account>*accinfolist, int ac_id)
{
	int ac_id1;
	int ac_money;
	SQLTCHAR ac_date[20];
	int ac_count;
	int cs_id;
	SQLINTEGER lac_id1, lac_money, lac_date, lac_count, lcs_id;

	SQLBindCol(hStmt, 1, SQL_C_ULONG, &ac_id1, 0, &lac_id1);
	SQLBindCol(hStmt, 2, SQL_C_ULONG, &ac_money, 0, &lac_money);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, ac_date, sizeof(ac_date), &lac_date);
	SQLBindCol(hStmt, 4, SQL_C_ULONG, &ac_count, 0, &lac_count);
	SQLBindCol(hStmt, 5, SQL_C_ULONG, &cs_id, 0, &lcs_id);


	TCHAR sql[256];
	wsprintf(sql, TEXT("select * from account where ac_id = %d"), ac_id);

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		Account acclist;
		acclist.ac_id = ac_id1;
		acclist.ac_money = ac_money;
		_tcscpy_s(acclist.ac_date, ac_date);
		acclist.ac_count = ac_count;
		acclist.cs_id = cs_id;

		accinfolist->push_back(acclist);
	}

	return TRUE;
}

BOOL wbdb_InsertAcc(int cs_id)
{
	TCHAR str[1024];
	wsprintf(str, TEXT("insert into account (ac_id, ac_money, ac_date, ac_count,cs_id) values(ac_register.nextval, 0, sysdate, 0, %d);"), cs_id);
	if (CommandSql(str) == TRUE)
	{
		return CommandSql((TCHAR*)TEXT("commit"));
	}
	return FALSE;
}

BOOL wbdb_DeleteAcc(int ac_id)
{
	TCHAR str[1024];
	wsprintf(str, TEXT("delete from account where ac_id = %d;"), ac_id);
	if (CommandSql(str) == TRUE)
	{
		return CommandSql((TCHAR*)TEXT("commit"));
	}
	return FALSE;
}

BOOL wbdb_DeleteAllAcc(int cs_id)
{
	TCHAR str[1024];
	wsprintf(str, TEXT("delete from account where cs_id = %d;"), cs_id);
	if (CommandSql(str) == TRUE)
	{
		return CommandSql((TCHAR*)TEXT("commit"));
	}
	return FALSE;
}
