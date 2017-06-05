namespace LSW
{
	bool load[5];
	HINSTANCE hDLL;

	typedef LRESULT CALLBACK (*FuncProc)(HWND,UINT,WPARAM,LPARAM);

	HWND CreateWin(HINSTANCE hInstance,FuncProc WndProc,char title[50],int x,int y);
    HWND CreateEdit(HWND hwnd,int x,int y,int width,int height);
    HWND CreateText(HWND hwnd,int x,int y,int width,int height,const char str[]);

    int CallFunc();
	int END();
}

HWND LSW::CreateWin(HINSTANCE hInstance,FuncProc WndProc,char title[50],int x,int y)
{
	typedef HWND (*func_CreateWin)(HINSTANCE hInstance,FuncProc WndProc,char title[50],int x,int y);
	func_CreateWin lsw_CreateWin;
	hDLL=LoadLibrary("LSW.dll");
	//_Z9CreateWinP11HINSTANCE__PFlP6HWND__jjlE
	lsw_CreateWin=(func_CreateWin)GetProcAddress(hDLL,MAKEINTRESOURCE(4));
	return (*lsw_CreateWin)(hInstance,WndProc,title,x,y);
}

HWND LSW::CreateEdit(HWND hwnd,int x,int y,int width,int height)
{
	typedef HWND (*func_CreateEdit)(HWND hwnd,int x,int y,int width,int height);
	func_CreateEdit lsw_CreateEdit;
    lsw_CreateEdit=(func_CreateEdit)GetProcAddress(hDLL,MAKEINTRESOURCE(2));
    return (*lsw_CreateEdit)(hwnd,x,y,width,height);
}

HWND LSW::CreateText(HWND hwnd,int x,int y,int width,int height,const char str[])
{
	typedef HWND (*func_CreateText)(HWND hwnd,int x,int y,int width,int height,const char str[]);
	func_CreateText lsw_CreateText;
    lsw_CreateText=(func_CreateText)GetProcAddress(hDLL,MAKEINTRESOURCE(3));
    return (*lsw_CreateText)(hwnd,x,y,width,height,str);
}

int LSW::CallFunc()
{
	typedef int (*func_CallFunc)();
	func_CallFunc lsw_CallFunc;
	lsw_CallFunc=(func_CallFunc)GetProcAddress(hDLL,MAKEINTRESOURCE(1));
	return (*lsw_CallFunc)();
}

int LSW::END()
{
	if(load[0]==1)
	{
	    FreeLibrary(hDLL);//卸载MyDll.dll文件
	}
	return 0;
}
