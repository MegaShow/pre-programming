//创建一个窗口
HWND CreateWin(HINSTANCE hInstance,FuncProc WndProc,char* title,int x,int y)
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
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass",title,WS_VISIBLE|(WS_OVERLAPPEDWINDOW-WS_THICKFRAME),
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

//开启窗口函数
int CallFunc()
{
   MSG Msg;
	while(GetMessage(&Msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&Msg); /* Translate key codes to chars if present */
		DispatchMessage(&Msg); /* Send it to WndProc */
	}
	return Msg.wParam;
}

//创建一个Edit
HWND CreateEdit(HINSTANCE hInstance,HWND hwnd,int x,int y,int width,int height,char* str)
{
    DWORD dwStyle = ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL | ES_WANTRETURN | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE;
    DWORD dwExStyle = WS_EX_CLIENTEDGE | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
    return CreateWindowEx(dwExStyle, //dwExStyle 扩展样式
                               "Edit", //lpClassName 窗口类名
                               str, //lpWindowName 窗口标题
                               dwStyle, //dwStyle 窗口样式
                               x, //x 左边位置
                               y, //y 顶边位置
                               width, //nWidth 宽度
                               height, //nHeight 高度
                               hwnd, //hWndParent 父窗口句柄
                               NULL, //hMenu 菜单句柄
                               hInstance, //hInstance 应用程序句柄
                               NULL//lpParam 附加参数
                               );
   /*return CreateWindow("EDIT",      // predefined class
                                    NULL,        // no window title
                                    WS_CHILD | WS_VISIBLE  |ES_NUMBER |
                                    ES_LEFT | ES_MULTILINE | ES_AUTOVSCROLL,
                                    x, y, width, height,  // set size in WM_SIZE message
                                    hwnd,        // parent window
                                    NULL,  // edit control ID
                                    NULL,
                                    NULL);       // pointer not needed
                                    */
}

//创建一个Text
HWND CreateText(HINSTANCE hInstance,HWND hwnd,int x,int y,int width,int height,char* str)
{
    //return CreateWindow("Text",str,SS_LEFT|WS_CHILD|WS_OVERLAPPED|WS_VISIBLE,x,y,width,height,hwnd,NULL,NULL,NULL);
    DWORD dwStyle = SS_LEFT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE;
    DWORD dwExStyle = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
    return CreateWindowEx(dwExStyle, //dwExStyle 扩展样式
	                      "Static", //lpClassName 窗口类名
	                      str, //lpWindowName 窗口标题
	                      dwStyle, //dwStyle 窗口样式
	                      x, //x 左边位置
	                      y, //y 顶边位置
	                      width, //nWidth 宽度
                          height, //nHeight 高度
	                      hwnd, //hWndParent 父窗口句柄
                          NULL, //hMenu 菜单句柄
	                      hInstance, //hInstance 应用程序句柄
	                      NULL//lpParam 附加参数
                          );
}


