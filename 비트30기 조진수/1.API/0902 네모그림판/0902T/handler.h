//handler.h

LRESULT OnCreate(HWND hwnd, WPARAM wParam, LPARAM);
LRESULT OnDestroy(HWND hwnd, WPARAM wParam, LPARAM);
LRESULT OnPaint(HWND hwnd, WPARAM wParam, LPARAM);
LRESULT OnLButtonDown(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnCommand(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnInitMenuPopup(HWND hwnd, WPARAM wParam, LPARAM lParam);
LRESULT OnMouseMove(HWND hwnd, WPARAM wParam, LPARAM lParam);
void OnShape(HWND hwnd, int type);


