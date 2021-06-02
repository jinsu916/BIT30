//wbdb.h

//데이터베이스 사용하기위한 2가지 헤더
#include <sql.h>
#include <sqlext.h>
//---------------------------------------
BOOL wbdb_DBConnect();
BOOL wbdb_DBDConnect();

//DDL---------------------------------------
BOOL wbdb_CreateTeamTable();
BOOL wbdb_DropTeamTable();
BOOL wbdb_CreateMemberTable();
BOOL wbdb_DropMemberTable();
BOOL wbdb_CreateSequence();
BOOL wbdb_DropSequence();
//-------------------------------------------
//select
BOOL wbdb_GetTeamSelect(int cs_id_, TCHAR* cs_name_, TCHAR* cs_phone_, vector<Customer>*cslist);
//insert
BOOL wbdb_InsertTeam(int cs_id, TCHAR* cs_name, TCHAR* cs_gender, TCHAR* cs_phone);
//update
BOOL wbdb_UpdateTeam(int cs_id, TCHAR* cs_name, TCHAR* cs_phone);
//delete
BOOL wbdb_DeleteTeam(int cs_id);
//select
BOOL wbdb_GetTeamSelectAll(vector<Customer>*cslist);

BOOL CommandSql(TCHAR *str);




//
////BOOL mydb_InsertData(Student *pData);
//
//BOOL mydb_SelectData();
//
//BOOL mydb_DeleteData();