#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WinSunProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);

int WINAPI WinMain(
  HINSTANCE hInstance,		// handle to current instance
  HINSTANCE hPrevInstance,  // handle to previous instance
  LPSTR lpCmdLine,			// pointer to command line
  int nCmdShow				// show state of window
)
{
	WNDCLASS wndcls;
	wndcls.cbClsExtra = 0;
	wndcls.cbWndExtra = 0;
	wndcls.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndcls.hCursor = LoadCursor(NULL, IDC_CROSS);
	wndcls.hIcon = LoadIcon(NULL, IDI_ERROR);
	wndcls.hInstance = hInstance;
	wndcls.lpfnWndProc = WinSunProc;
	wndcls.lpszClassName = "VCLesson1";
	wndcls.lpszMenuName = NULL;
	wndcls.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wndcls);

	HWND hwnd;
	hwnd = CreateWindow("VCLesson1", "VC学习教程", WS_OVERLAPPEDWINDOW,
		0,0,600,400,NULL,NULL,hInstance,NULL);
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);

	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WinSunProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
)
{
	switch(uMsg)
	{
	case WM_CHAR:
		char szChar[20];
		sprintf(szChar, "char is %d", wParam);
		MessageBox(hwnd, szChar, "VCLesson1", 0);
		break;
	case WM_LBUTTONDOWN:
		MessageBox(hwnd, "mouse clicked", "VCLesson1", 0);
		HDC hdc;
		hdc = GetDC(hwnd);
		TextOut(hdc, 0, 50, "VC编程培训", strlen("VC编程培训"));
		ReleaseDC(hwnd, hdc);
		break;
	case WM_PAINT:
		HDC hDC;
		PAINTSTRUCT ps;
		hDC = BeginPaint(hwnd, &ps);
		TextOut(hDC, 0, 0, "VC编程培训, 重绘", strlen("VC编程培训, 重绘"));
		EndPaint(hwnd, &ps);
		break;
	case WM_CLOSE:
		if(IDYES == MessageBox(hwnd, "退出结束", "VCLesson1", MB_YESNO))
		{
			DestroyWindow(hwnd);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}