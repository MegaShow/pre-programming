#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

typedef LRESULT CALLBACK (*FuncProc)(HWND,UINT,WPARAM,LPARAM);

HWND DLL_EXPORT CreateWin(HINSTANCE hInstance,FuncProc WndProc,char* title,int x,int y);
HWND DLL_EXPORT CreateEdit(HINSTANCE hInstance,HWND hwnd,int x,int y,int width,int height,char* str);
HWND DLL_EXPORT CreateText(HINSTANCE hInstance,HWND hwnd,int x,int y,int width,int height,char* str);
int DLL_EXPORT CallFunc();

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
