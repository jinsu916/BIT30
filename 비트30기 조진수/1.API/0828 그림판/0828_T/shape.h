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
void createShape1(HWND hwnd, LPARAM lParam); //���콺 Ŭ���� shape ����
void createShape2(HWND hwnd); //��ȿȭ�� shape�� �ٽ� �׸���