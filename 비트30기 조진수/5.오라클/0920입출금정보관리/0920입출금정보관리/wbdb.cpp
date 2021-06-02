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

	// ���� ������ ���� ������
	SQLRETURN Ret;

	// 1, ȯ�� �ڵ��� �Ҵ��ϰ� ���� �Ӽ��� �����Ѵ�.(p1741)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv) != SQL_SUCCESS)
		return false;
	if (SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
		return false;

	// 2. ���� �ڵ��� �Ҵ��ϰ� �����Ѵ�.
	if (SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc) != SQL_SUCCESS)
		return false;
	// ����Ŭ ������ �����ϱ�
	Ret = SQLConnect(hDbc, (SQLTCHAR *)DBNAME, SQL_NTS, (SQLTCHAR *)ID, SQL_NTS, (SQLTCHAR *)PW, SQL_NTS);

	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
		return false;

	// ��� �ڵ��� �Ҵ��Ѵ�.
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) != SQL_SUCCESS)
		return false;

	return true;
}

BOOL wbdb_DBDConnect()
{
	// ������
	if (hStmt) SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	if (hDbc) SQLDisconnect(hDbc);
	if (hDbc) SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	if (hEnv) SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

	return TRUE;
}

// SQL ��� ����
BOOL CommandSql(TCHAR *str)
{
	// ���޵ƴ��� Ȯ��. ������Ҷ� ���⼭ ���缭 Ȯ��
	if (SQLExecDirect(hStmt, (SQLTCHAR *)str, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}
	return TRUE;
}

//�޺��ڽ����
BOOL wbdb_GetCSIDAll(vector<int>*csidlist)
{
	int cs_id;
	SQLINTEGER Ics_id;

	//�÷��� �����͸� ����
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
