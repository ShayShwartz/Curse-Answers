#include <Windows.h>
#include <iostream>
#include <string>

const char g_szClassName[] = "myWindowClass";
const char filePath[] = "output.txt";

using namespace std;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	
	// Initzialize the Window
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;	
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW-2);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	
	// Register the window class
	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
					MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	
	// Creating the Window
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
							g_szClassName,
							"Shwartz's windows",
							WS_OVERLAPPEDWINDOW,
							CW_USEDEFAULT, CW_USEDEFAULT, 860, 640,
							NULL, NULL, hInstance, NULL);
	if(hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
		MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Message Loop
	while(GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}

	return Msg.wParam;
}


// Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static long long counter = 0;
	static HANDLE hFile;
	static SYSTEMTIME lt;
	static char timeStr[10];
	DWORD tmp;

	switch(msg)
	{
		case WM_KEYDOWN:
			if(wParam == VK_RETURN)
			{
				hFile = CreateFile(filePath, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, 0, NULL);
				if ( hFile == INVALID_HANDLE_VALUE)
				{
					MessageBox(hwnd, "CreateFile faild!", "ERROR", MB_ICONERROR);
					return -1;
				}
				GetDateFormat(LOCALE_SYSTEM_DEFAULT, 0, NULL,"dd/MM/yyyy", timeStr,10);
				SetFilePointer(hFile, 0, NULL, FILE_END);
				WriteFile(hFile,timeStr, 10, &tmp, NULL);
				GetLocalTime(&lt);
				GetTimeFormat(LOCALE_CUSTOM_DEFAULT, TIME_FORCE24HOURFORMAT, &lt," hh:mm:ss",timeStr, 9);
				WriteFile(hFile, timeStr, 9, &tmp,NULL);
				WriteFile(hFile,"\r\n", 2, &tmp,NULL);
				CloseHandle(hFile);
			}
			break;
		case WM_LBUTTONDOWN:
			counter++;
			SetWindowText(hwnd, to_string(counter).c_str());
			break;
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}
