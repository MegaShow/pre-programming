#ifndef _DLL_H_
#define _DLL_H_

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

typedef LRESULT CALLBACK (*FuncProc)(HWND,UINT,WPARAM,LPARAM);

HWND DLLIMPORT CreateWin(HINSTANCE hInstance,FuncProc WndProc,char title[50],int x,int y);
HWND DLLIMPORT CreateEdit(HWND hwnd,int x,int y,int width,int height);
HWND DLLIMPORT CreateText(HWND hwnd,int x,int y,int width,int height,const char str[]);

int DLLIMPORT CallFunc();



#endif
