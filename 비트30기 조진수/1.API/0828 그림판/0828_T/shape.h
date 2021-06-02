#pragma once

typedef struct tagSHARE
{
	int type;			//1: R, 2: E 3: T
	int penwidth;		//1, 3, 5
	COLORREF color;		//R, G, B
	int size = 50;		
	POINT pt;			//
}SHAPE;

void shape_Init();
void createShape1(HWND hwnd, LPARAM lParam); //마우스 클릭시 shape 생성
void createShape2(HWND hwnd); //무효화된 shape들 다시 그리기