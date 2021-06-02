//����� p.127
#include <windows.h>
#include <tchar.h>
#include <vector>
using namespace std;
#include <stdio.h>

#define IDC_EDIT1 1
#define IDC_COMBO1 2
#define IDC_RADIO1 3
#define IDC_RADIO2 4
#define IDC_CHECKBOX1 5
#define IDC_CHECKBOX2 6
#define IDC_BUTTON1 7
#define IDC_LISTBOX1 8

HWND g_edit1, g_combo1, g_radio1, g_radio2, g_checkbox1, g_checkbox2;
HWND g_button1, g_listbox1;

typedef struct tagMember
{
	TCHAR name[20];
	int age;
	char gender;
	TCHAR hab[20];
}MEMBER;

vector<MEMBER>g_memberlist;

LRESULT OnCreate(HWND hwnd)
{
	//����ƽ ��Ʈ�� (��� ��)
	CreateWindow(TEXT("static"), TEXT("�̸�"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 10, 70, 20,
		hwnd, (HMENU)IDC_EDIT1, 0, 0);

	CreateWindow(TEXT("static"), TEXT("����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 40, 70, 20,
		hwnd, (HMENU)IDC_EDIT1, 0, 0);

	CreateWindow(TEXT("static"), TEXT("����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 70, 70, 20,
		hwnd, (HMENU)IDC_EDIT1, 0, 0);

	CreateWindow(TEXT("static"), TEXT("���"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		10, 100, 70, 20,
		hwnd, (HMENU)IDC_EDIT1, 0, 0);

	//����Ʈ ��Ʈ��
	g_edit1 = CreateWindow(TEXT("edit"), TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		90, 10, 200, 20, hwnd, (HMENU)IDC_EDIT1, 0, 0);

	//�޺��ڽ� ��Ʈ��(����Ʈ�ڽ� ��Ʈ�Ѱ� ����)
	g_combo1 = CreateWindow(TEXT("combobox"), TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_BORDER| CBS_DROPDOWNLIST,
		90, 40, 200, 200, hwnd, (HMENU)IDC_COMBO1, 0, 0);

	//������ư ��Ʈ��(�ټ��� �ϳ��� ����)
	g_radio1 = CreateWindow(TEXT("button"), TEXT("����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_AUTORADIOBUTTON,
		90, 70, 90, 20, hwnd, (HMENU)IDC_RADIO1, 0, 0);

	g_radio2 = CreateWindow(TEXT("button"), TEXT("����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_AUTORADIOBUTTON,
		200, 70, 90, 20, hwnd, (HMENU)IDC_RADIO2, 0, 0);

	//üũ�ڽ� ��Ʈ��(�ټ��� ���� ����)
	g_checkbox1 = CreateWindow(TEXT("button"), TEXT("����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_AUTOCHECKBOX,
		90, 100, 90, 20, hwnd, (HMENU)IDC_CHECKBOX1, 0, 0);

	g_checkbox2 = CreateWindow(TEXT("button"), TEXT("����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | BS_AUTOCHECKBOX,
		200, 100, 90, 20, hwnd, (HMENU)IDC_CHECKBOX2, 0, 0);

	//��ư ��Ʈ��
	g_button1 = CreateWindow(TEXT("button"), TEXT("����"),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		200, 130, 90, 30, hwnd, (HMENU)IDC_BUTTON1, 0, 0);

	//����Ʈ�ڽ� ��Ʈ��
	g_listbox1 = CreateWindow(TEXT("listbox"), TEXT(""),
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		300, 10, 300, 200, hwnd, (HMENU)IDC_LISTBOX1, 0, 0);

	//=====================================================
	//��Ʈ�� �ʱ�ȭ
	//�θ� -> �޺��ڽ�
	SendMessage(g_combo1, CB_ADDSTRING, 0, (WPARAM)TEXT("10"));
	SendMessage(g_combo1, CB_ADDSTRING, 0, (WPARAM)TEXT("20"));
	SendMessage(g_combo1, CB_ADDSTRING, 0, (WPARAM)TEXT("30"));



	return 0;
}

LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM)
{
	PostQuitMessage(0);
	return 0;
}

void OnNotifyEdit(HWND hwnd, WPARAM wParam)
{
	if (HIWORD(wParam) == EN_CHANGE) //���ڿ� ����ɶ�����..
	{
		TCHAR temp[256];
		GetWindowText(g_edit1, temp, sizeof(temp));

		//Ÿ��Ʋ�� ���
		SetWindowText(hwnd, temp);
	}
}

void OnNotifyCombo(HWND hwnd, WPARAM wParam)
{
	if (HIWORD(wParam) == CBN_SELCHANGE) //���� ����ɶ�����..
	{
		//���õ� �ε���
		int sel = SendMessage(g_combo1, CB_GETCURSEL, 0, 0);
		//���ε����� ������ �ִ� ���ڿ� ȹ��
		TCHAR temp[256];
		SendMessage(g_combo1, CB_GETLBTEXT, sel, (LPARAM)temp);

		//Ÿ��Ʋ�� ���
		SetWindowText(hwnd, temp);
	}
}

void OnNotifyRadio1(HWND hwnd, WPARAM wParam)
{
	if (HIWORD(wParam) == BN_CLICKED) //���� ����ɶ�����..
	{
		TCHAR temp[256];
		GetWindowText(g_radio1, temp, sizeof(temp));

		//Ÿ��Ʋ�� ���
		SetWindowText(hwnd, temp);
	}
}

void OnNotifyRadio2(HWND hwnd, WPARAM wParam)
{
	if (HIWORD(wParam) == BN_CLICKED) //���� ����ɶ�����..
	{
		TCHAR temp[256];
		GetWindowText(g_radio2, temp, sizeof(temp));

		//Ÿ��Ʋ�� ���
		SetWindowText(hwnd, temp);
	}
}

void OnNotifyCheck(HWND hwnd, WPARAM wParam)
{
	//üũ�ڽ��� ���������� �����ִ� üũ�ڽ��� ã�´�.
	if (HIWORD(wParam) == BN_CLICKED) //���� ����ɶ�����..
	{
		TCHAR arr[256] = TEXT("");
		if (SendMessage(g_checkbox1, BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			TCHAR str[20];
			GetWindowText(g_checkbox1, str, sizeof(str));
			_tcscpy_s(arr, str);
		}
		if (SendMessage(g_checkbox2, BM_GETCHECK, 0, 0) == BST_CHECKED)
		{
			TCHAR str[20];
			GetWindowText(g_checkbox2, str, sizeof(str));
			_tcscat_s(arr, str); //�ٿ��ֱ�
		}
		SetWindowText(hwnd, arr);
	}
}

void AddListBox(HWND hwnd)
{
	//����Ʈ�ڽ� �����۵��� ��� ����

	for (int i = 0; i < (int) g_memberlist.size(); i++)
	{
		MEMBER mem = g_memberlist[i];

		TCHAR str[256];
		wsprintf(str, TEXT("%s, %d, %c, %s"),
			mem.name, mem.age, mem.gender, mem.hab);

		SendMessage(g_listbox1, LB_ADDSTRING, 0, (LPARAM)str);
	}
}

void OnNotifyButton1(HWND hwnd, WPARAM wParam)
{
	//��ư�� �����޽����� �ϳ�..== Ŭ��
	//���� �˰���
	MEMBER member;

	//�̸�
	GetWindowText(g_edit1, member.name, sizeof(member.name));
	//����
	TCHAR temp[256];
	SendMessage(g_combo1, CB_GETLBTEXT,
		SendMessage(g_combo1, CB_GETCURSEL, 0, 0), (LPARAM)temp);
	member.age = _ttoi(temp);  //stdio.h

	//����
	if (SendMessage(g_radio1, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		member.gender = 'm';
	}
	else
		member.gender = 'f';
	//���
	if (SendMessage(g_checkbox1, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		TCHAR str[20];
		GetWindowText(g_checkbox1, str, sizeof(str));
		_tcscpy_s(member.hab, str);
	}
	if (SendMessage(g_checkbox2, BM_GETCHECK, 0, 0) == BST_CHECKED)
	{
		TCHAR str[20];
		GetWindowText(g_checkbox2, str, sizeof(str));
		_tcscat_s(member.hab, str); //�ٿ��ֱ�
	}
	g_memberlist.push_back(member);
	
	AddListBox(hwnd);
}

LRESULT ONCommand(HWND hwnd, WPARAM wParam, LPARAM)
{
	switch (LOWORD(wParam))//p.129 ID����
	{
	case IDC_EDIT1: OnNotifyEdit(hwnd, wParam); break;
	case IDC_COMBO1: OnNotifyCombo(hwnd, wParam); break;
	case IDC_RADIO1: OnNotifyRadio1(hwnd, wParam); break;
	case IDC_RADIO2: OnNotifyRadio2(hwnd, wParam); break;
	case IDC_CHECKBOX1: OnNotifyCheck(hwnd, wParam); break;
	case IDC_CHECKBOX2: OnNotifyCheck(hwnd, wParam); break;
	case IDC_BUTTON1: OnNotifyButton1(hwnd, wParam); break;
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
{
	switch (msg)
	{
	case WM_COMMAND:		return ONCommand(hwnd, wParam, IParam);
	case WM_CREATE:			return OnCreate(hwnd);
	case WM_DESTROY:		return OnDestroy(hwnd, wParam, IParam);
	}
	return DefWindowProc(hwnd, msg, wParam, IParam);
}

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR IpCmdLine, int nShowCmd)
{
	//1. ������ Ŭ���� �����
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hInstance = hInst;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = TEXT("First");
	wc.lpszMenuName = 0;
	wc.style = 0;
	//2. ���(������Ʈ����)
	RegisterClass(&wc);
	//3. ������ â �����
	HWND hwnd = CreateWindowEx(0,
		TEXT("first"),
		TEXT("Hello"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0,
		0, 0,
		hInst,
		0);
	//4. ������ �����ֱ�
	ShowWindow(hwnd, SW_SHOW);
	UpdateWindow(hwnd);

	//5. �޽���
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}