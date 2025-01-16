#include "framework.h"
#include "L10.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

POINT startPoint = { 0, 0 };
POINT endPoint = { 0, 0 };
bool isDrawing = false;

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// Структура и список кругов
struct Circle {
    int x, y;
    int radius;
};

struct CircleList {
    Circle C;
    CircleList* pNext;
};

CircleList* pFirst = 0, * p;

void add(CircleList*& pF, CircleList* p) {
    p->pNext = pF;
    pF = p;
}

int x, y;
HPEN pB, pY;
HBRUSH hBrush;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_L10, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance(hInstance, nCmdShow)) {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_L10));
    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance) {
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_L10));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_L10);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance; 

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd) {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

void DrawFilledCircle(HDC hdc, int x, int y, int radius) {
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 0)); // Создаем желтую кисть для заливки
    SelectObject(hdc, hBrush);
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
    DeleteObject(hBrush);
}

void DrawCircleOutline(HDC hdc, int x, int y, int radius) {
    // Рисуем обводку круга
    Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    HDC hdc;
    PAINTSTRUCT ps;

    switch (message) {
    case WM_CREATE:
        pB = CreatePen(PS_SOLID, 1, RGB(26, 180, 26));
        pY = CreatePen(PS_SOLID, 1, RGB(255, 255, 18)); 
        break;

    case WM_LBUTTONDOWN:
        isDrawing = true;
        x = LOWORD(lParam);
        y = HIWORD(lParam);
        break;

    case WM_MOUSEMOVE:
        if (isDrawing)
        {
            hdc = GetDC(hWnd);
            SelectObject(hdc, pY); // жёлтое перо
            DrawFilledCircle(hdc, x, y, 24);
            SelectObject(hdc, pB); // зелёное перо
            DrawCircleOutline(hdc, x, y, 24);
            ReleaseDC(hWnd, hdc);
            x = LOWORD(lParam);
            y = HIWORD(lParam);
        }
        break;

    case WM_LBUTTONUP: // Отпускаем левую кнопку мыши
        if (isDrawing) {
            isDrawing = false;
            p = new CircleList;
            p->C.x = x;
            p->C.y = y;
            p->C.radius = 24;
            add(pFirst, p);
        }
        break;

    case WM_PAINT: // Перерисовка
        hdc = BeginPaint(hWnd, &ps);
        p = pFirst;
        while (p) {
            SelectObject(hdc, pY); // Используем жёлтое перо
            DrawFilledCircle(hdc, p->C.x, p->C.y, p->C.radius);
            SelectObject(hdc, pB); // Используем зелёное перо
            DrawCircleOutline(hdc, p->C.x, p->C.y, p->C.radius);
            p = p->pNext;
        }
        EndPaint(hWnd, &ps);
        break;

    case WM_COMMAND: // Обработка меню приложения
    {
        int wmId = LOWORD(wParam);
        // Разбор выбора в меню:
        switch (wmId) {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_DESTROY: // Завершение программы
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе"
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}