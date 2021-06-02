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

BOOL wbdb_CreateTeamTable()
{
	TCHAR str[1024] = TEXT("CREATE TABLE Team (GroupId number,GroupName varchar2(20),CONSTRAINT Group_id_pk primary key(GroupId));");

	return CommandSql(str);
}

BOOL wbdb_DropTeamTable()
{
	TCHAR str[1024] = TEXT("DROP TABLE Team;");

	return CommandSql(str);
}

BOOL wbdb_CreateMemberTable()
{
	TCHAR str[1024] = TEXT("CREATE TABLE member( \
		mem_ID   	 NUMBER,	\
		mem_NAME  	VARCHAR2(20 BYTE) NOT NULL,	\
		mem_gen		VARCHAR2(20 BYTE)			\
			check(mem_gen in('남성', '여성')),	\
		mem_phone 	 VARCHAR2(20 BYTE),			\
		mem_GID          NUMBER NOT NULL,		\
		mem_date	date,						\
		CONSTRAINT member_PK PRIMARY KEY(mem_ID)); ");

	CommandSql(str);

	TCHAR str1[1024] = TEXT("ALTER TABLE member \
		ADD CONSTRAINT member_FK FOREIGN KEY(mem_ID)	\
		REFERENCES member(mem_ID); ");

	return CommandSql(str1);
}

BOOL wbdb_DropMemberTable()
{
	TCHAR str[1024] = TEXT("DROP TABLE Member;");

	return CommandSql(str);
}

BOOL wbdb_CreateSequence()
{
	TCHAR str[1024] = TEXT("create sequence mem_ID_seq increment by 1 start with 1000; ");

	return CommandSql(str);
}

BOOL wbdb_DropSequence()
{
	TCHAR str[1024] = TEXT("drop sequence mem_ID_seq");

	return CommandSql(str);
}

//입력
BOOL wbdb_InsertTeam(int cs_id, TCHAR* cs_name, TCHAR* cs_gender, TCHAR* cs_phone)
{
	TCHAR str[1024];
	//wsprintf(str, TEXT("insert into Team values(%d, '%s');"),
	wsprintf(str, TEXT("insert into customer values(%d, '%s', '%s', '%s', sysdate);"),
		cs_id, cs_name, cs_gender, cs_phone);
	if (CommandSql(str) == TRUE)
	{
		return CommandSql((LPWSTR)TEXT("commit"));
	}
	return FALSE;
}

//수정
BOOL wbdb_UpdateTeam(int cs_id, TCHAR* cs_name, TCHAR* cs_phone)
{
	TCHAR str[1024];
	//wsprintf(str, TEXT("insert into Team values(%d, '%s');"),
	wsprintf(str, TEXT("update customer set cs_name = '%s', cs_phone ='%s' where cs_id = %d"),
		cs_name, cs_phone, cs_id);
	if (CommandSql(str) == TRUE)
	{
		return CommandSql((LPWSTR)TEXT("commit"));
	}
	return FALSE;
}

//삭제
BOOL wbdb_DeleteTeam(int cs_id)
{
	TCHAR str[1024];
	//wsprintf(str, TEXT("insert into Team values(%d, '%s');"),
	wsprintf(str, TEXT("delete customer where cs_id = %d;"),
		cs_id);
	if (CommandSql(str) == TRUE)
	{
		return CommandSql((LPWSTR)TEXT("commit"));
	}
	return FALSE;
}


//쿼리문 보내는 함수
BOOL CommandSql(TCHAR *str)
{
	if (SQLExecDirect(hStmt, (SQLTCHAR *)str, SQL_NTS) != SQL_SUCCESS)//hSmt -쿼리문을 날릴수있는 핸들값
	{
		return FALSE;
	}
	return TRUE;
}

//전체출력
BOOL wbdb_GetTeamSelectAll(vector<Customer>*cslist)
{
	int cs_id;
	SQLTCHAR cs_name[20];
	SQLTCHAR cs_gender[2];
	SQLTCHAR cs_phone[20];
	SQLTCHAR cs_date[20];
	SQLINTEGER Ics_id, Ics_name, Ics_gender, Ics_phone, Ics_date;

	//컬럼과 데이터를 연결
	SQLBindCol(hStmt, 1, SQL_C_ULONG, &cs_id, 0, &Ics_id);
	SQLBindCol(hStmt, 2, SQL_C_WCHAR, cs_name, sizeof(cs_name), &Ics_name);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, cs_gender, sizeof(cs_gender), &Ics_gender);
	SQLBindCol(hStmt, 4, SQL_C_WCHAR, cs_phone, sizeof(cs_phone), &Ics_phone);
	SQLBindCol(hStmt, 5, SQL_C_WCHAR, cs_date, sizeof(cs_date), &Ics_date);

	TCHAR sql[256] = TEXT("select * from customer;");

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		Customer data;
		data.cs_id = cs_id;
		_tcscpy_s(data.cs_name, cs_name);
		_tcscpy_s(data.cs_gender, cs_gender);
		_tcscpy_s(data.cs_phone, cs_phone);
		_tcscpy_s(data.cs_date, cs_date);
		cslist->push_back(data);
	}
}

//검색
BOOL wbdb_GetTeamSelect(int cs_id_,TCHAR* cs_name_,TCHAR* cs_phone_,vector<Customer>*cslist)
{
	TCHAR sql[256];
	int cs_id;
	SQLTCHAR cs_name[20];
	SQLTCHAR cs_gender[2];
	SQLTCHAR cs_phone[20];
	SQLTCHAR cs_date[20];
	SQLINTEGER Ics_id, Ics_name, Ics_gender, Ics_phone, Ics_date;

	//컬럼과 데이터를 연결
	SQLBindCol(hStmt, 1, SQL_C_ULONG, &cs_id, 0, &Ics_id);
	SQLBindCol(hStmt, 2, SQL_C_WCHAR, cs_name, sizeof(cs_name), &Ics_name);
	SQLBindCol(hStmt, 3, SQL_C_WCHAR, cs_gender, sizeof(cs_gender), &Ics_gender);
	SQLBindCol(hStmt, 4, SQL_C_WCHAR, cs_phone, sizeof(cs_phone), &Ics_phone);
	SQLBindCol(hStmt, 5, SQL_C_WCHAR, cs_date, sizeof(cs_date), &Ics_date);

	int sel = ui_GetComboSel();
	if (sel == 0)
		 wsprintf(sql, TEXT("select * from customer where cs_id = %d;"),
			cs_id_);
	else if (sel == 1)
		wsprintf(sql, TEXT("select * from customer where cs_name = '%s';"),
			cs_name_);
	else 
		wsprintf(sql, TEXT("select * from customer where cs_phone = '%s';"),
			cs_phone_);
	

	if (SQLExecDirect(hStmt, (SQLTCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
	{
		return FALSE;
	}

	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
	{
		Customer data;
		data.cs_id = cs_id;
		_tcscpy_s(data.cs_name, cs_name);
		_tcscpy_s(data.cs_gender, cs_gender);
		_tcscpy_s(data.cs_phone, cs_phone);
		_tcscpy_s(data.cs_date, cs_date);
		cslist->push_back(data);
	}
}

//BOOL mydb_SelectData()
//{
//	SQLCHAR Name[256];
//
//	SQLINTEGER lName, lSnum, lPhone, lEmail;
//	int ssnum;
//
//	SQLCHAR Phone[256];
//	SQLCHAR Email[256];
//
//	SQLBindCol(hStmt, 1, SQL_C_CHAR, Name, sizeof(Name), &lName);
//	SQLBindCol(hStmt, 2, SQL_C_ULONG, &ssnum, 0, &lSnum);
//	SQLBindCol(hStmt, 3, SQL_C_CHAR, Phone, sizeof(Phone), &lPhone);
//	SQLBindCol(hStmt, 4, SQL_C_CHAR, Email, sizeof(Email), &lEmail);
//
//	char sql[256] = "select * from sb";
//
//	if (SQLExecDirect(hStmt, (SQLCHAR*)sql, SQL_NTS) != SQL_SUCCESS)
//	{
//		return FALSE;
//	}
//
//	char name[21], num[21], phoneNumber[21], email[41];
//	int count = 0;
//	for (int i = 0; SQLFetch(hStmt) != SQL_NO_DATA; i++)
//	{
//		wsprintf(name, "%s", Name);
//		wsprintf(num, "%d", ssnum);
//		wsprintf(phoneNumber, "%s", Phone);
//		wsprintf(email, "%s", Email);
//
//		control_GetData(count++, name, num, phoneNumber, email);
//
//	}
//	return TRUE;
//}
//
//BOOL mydb_DeleteData()
//{
//	char sql[256];
//
//	wsprintf(sql, "delete sb");
//	if (SQLExecDirect(hStmt, (SQLCHAR *)sql, SQL_NTS) != SQL_SUCCESS)
//	{
//		return FALSE;
//	}
//	return TRUE;
//}