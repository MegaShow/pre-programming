#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <cstring>
#include <string>
#include <windows.h>

HMENU g_hTopMenu = NULL; // 顶层菜单全局变量
static HWND hwnd,button,static_api,static_put,edit_hwnd;

BOOL CreateTopMenu()
{

    g_hTopMenu = CreateMenu();
    HMENU hMenu2 = CreateMenu();
    AppendMenu(hMenu2, MF_STRING, 1024,"关于");
    AppendMenu(g_hTopMenu,MF_POPUP,(UINT)hMenu2,"文件");

    return TRUE;
}


/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    CreateTopMenu();


    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("WinAPI Assistant"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           408,                 /* The programs width */
           300,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           g_hTopMenu,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );


    DWORD dwStyle = SS_LEFT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE;
    DWORD dwExStyle = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
    char* strWindowName = "  输入WinAPI函数名：";
    static_api=::CreateWindowEx(
	dwExStyle, //dwExStyle 扩展样式
	"Static", //lpClassName 窗口类名
	strWindowName, //lpWindowName 窗口标题
	dwStyle, //dwStyle 窗口样式
	0, //x 左边位置
	0, //y 顶边位置
	150, //nWidth 宽度
	20, //nHeight 高度
	hwnd, //hWndParent 父窗口句柄
	NULL, //hMenu 菜单句柄
	hThisInstance, //hInstance 应用程序句柄
	NULL //lpParam 附加参数
);

 dwStyle = SS_LEFT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE;
      dwExStyle =  WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
      strWindowName = "暂时只有CreateWindow的查询！";
      static_put=::CreateWindowEx(
	      dwExStyle, //dwExStyle 扩展样式
	"Static_two", //lpClassName 窗口类名
	strWindowName, //lpWindowName 窗口标题
	dwStyle, //dwStyle 窗口样式
	0, //x 左边位置
	20, //y 顶边位置
	408, //nWidth 宽度
	280, //nHeight 高度
	hwnd, //hWndParent 父窗口句柄
	NULL, //hMenu 菜单句柄
	hThisInstance, //hInstance 应用程序句柄
	NULL //lpParam 附加参数
);
    dwStyle = BS_PUSHBUTTON | BS_TEXT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE;
    dwExStyle = WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
    strWindowName = "搜索";
    button=::CreateWindowEx(
	dwExStyle, //dwExStyle 扩展样式
	"Button", //lpClassName 窗口类名
	strWindowName, //lpWindowName 窗口标题
	dwStyle, //dwStyle 窗口样式
	350, //x 左边位置
	0, //y 顶边位置
	50, //nWidth 宽度
	20, //nHeight 高度
	hwnd, //hWndParent 父窗口句柄
	NULL, //hMenu 菜单句柄
	hThisInstance, //hInstance 应用程序句柄
	NULL //lpParam 附加参数
);




    dwStyle = ES_LEFT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE;
    dwExStyle = WS_EX_CLIENTEDGE | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
    strWindowName = "EDIT";
    edit_hwnd=::CreateWindowEx(
	          dwExStyle, //dwExStyle 扩展样式
	          "Edit", //lpClassName 窗口类名
	          strWindowName, //lpWindowName 窗口标题
	          dwStyle, //dwStyle 窗口样式
	          150, //x 左边位置
	          0, //y 顶边位置
	          200, //nWidth 宽度
	          20, //nHeight 高度
	          hwnd, //hWndParent 父窗口句柄
	          NULL, //hMenu 菜单句柄
	          hThisInstance, //hInstance 应用程序句柄
	          NULL //lpParam 附加参数
      );




    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
        case WM_COMMAND:
            //if(GetDlgItem(hwnd, LOWORD(wParam)) == lParam)
            //{

                switch(HIWORD(wParam))
                {
                case BN_CLICKED:
                    if(LOWORD(wParam))
                    {break;}
                    char api_name[30];
                    GetWindowText(edit_hwnd,api_name,30);
                    std::string api = api_name;
                    if(api=="CreateWindow")
                    {
                        WinExec("notepad.exe API//CreateWindow.txt",SW_SHOW);
                    }
                    else
                    {
                        char str_put[49]="未找到或不存在函数";
                        strcat(str_put,api_name);
                        MessageBox(hwnd,str_put,_T("搜索结果"),MB_OK);
                    }
                    break;
                //default:
                //    break;
                //    return DefWindowProc(hwnd, message, wParam, lParam);
                }
            //};
            switch(LOWORD(wParam))
            {
                case 1024:
                    MessageBox(hwnd,_T("暂时只有CreateWindow的查询！\n\nWinAPI Assistant v0.01\nmade by 萧叶藏刀"),_T("版本信息"),MB_OK);
                    break;
            }

            break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
