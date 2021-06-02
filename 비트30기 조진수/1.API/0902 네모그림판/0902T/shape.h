//shape.h

typedef struct tagSHAPE
{
	POINT pt;
	COLORREF color;
	int type;
}SHAPE;

void shape_Init();
void createShape1(HWND hwnd, LPARAM lParam);
void createShape2(HWND hwnd);
void shape_Rect(HWND hwnd);