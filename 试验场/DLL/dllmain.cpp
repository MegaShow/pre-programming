/* Replace "dll.h" with the name of your header */

#include <windows.h>
#include "dll.h"

HWND CreateWin(HINSTANCE hInstance,FuncProc WndProc,char title[50],int x,int y)
{
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(9);//(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass",title,WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		x, /* width */
		y, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
   return hwnd;
}

int CallFunc()
{
   MSG Msg;
	while(GetMessage(&Msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&Msg); /* Translate key codes to chars if present */
		DispatchMessage(&Msg); /* Send it to WndProc */
	}
	return Msg.wParam;
}

HWND CreateEdit(HWND hwnd,int x,int y,int width,int height)
{
   return CreateWindow("EDIT",      // predefined class 
                                    NULL,        // no window title 
                                    WS_CHILD | WS_VISIBLE  |ES_NUMBER | 
                                    ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL, 
                                    x, y, width, height,  // set size in WM_SIZE message 
                                    hwnd,        // parent window 
                                    NULL,  // edit control ID 
                                    NULL, 
                                    NULL);       // pointer not needed
}

HWND CreateText(HWND hwnd,int x,int y,int width,int height,char str[])
{
    return CreateWindow("Text",str,SS_LEFT|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,x,y,width,height,hwnd,NULL,NULL,NULL);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
