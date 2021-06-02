//data.h

typedef struct tagTeam
{
	int team_id;
	TCHAR team_name[20];
}TEAM;

typedef struct tagCustomer
{
	int cs_id;
	TCHAR cs_name[20];
	TCHAR cs_gender[2];
	TCHAR cs_phone[20];
	TCHAR cs_date[20];
}Customer;