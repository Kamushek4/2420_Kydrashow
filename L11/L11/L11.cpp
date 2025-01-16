#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include "resource.h"

BOOL CALLBACK DialogFun(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    char Text[64];
    double x, y, z;
    switch (message)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDOK:
        case IDCANCEL:
            EndDialog(hwnd, LOWORD(wParam));
            return TRUE;
        case IDC_BUTTON1: 
        case IDC_BUTTON2:
            SendDlgItemMessage(hwnd, IDC_EDIT1, WM_GETTEXT, 63, (LPARAM)Text);
            if (sscanf_s(Text, "%lf", &x) < 1)
            {
                MessageBox(hwnd,
                    "Неверный формат второго операнда",
                    "Ошибка формата",
                    MB_OK | MB_ICONHAND);
                return TRUE;
            }
            SendDlgItemMessage(hwnd, IDC_EDIT2, WM_GETTEXT, 63, (LPARAM)Text);
            if (sscanf_s(Text, "%lf", &y) < 1)
            {
                MessageBox(hwnd,
                    "Неверный формат второго операнда",
                    "Ошибка формата",
                    MB_OK | MB_ICONHAND);
                return TRUE;
            }
            char Znak;
            if (LOWORD(wParam) == IDC_BUTTON1)
            {
                z = x + y;
                Znak = '+';
            }
            if (LOWORD(wParam) == IDC_BUTTON2)
            {
                z = x - y;
                Znak = '-';
            }
            sprintf(Text, "%f", z);
            SendDlgItemMessage(hwnd, IDC_EDIT3, WM_SETTEXT, 0, (LPARAM) Text);
            sprintf_s(Text, "%f %c %f = %f", x, Znak, y, z);
            SendDlgItemMessage(hwnd, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)Text);
            return TRUE;
        }
    }
    return FALSE;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DialogFun);
    return 0;
}

