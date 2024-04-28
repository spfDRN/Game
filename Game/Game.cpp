// Game.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Game.h"
#include "windows.h"
#include <Windows.h>
#include <stdio.h>


#define _CRT_SECURE_NO_WARNINGS
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
short step = 0;
RECT  WinRect;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GAME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAME));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GAME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//


void Robot(HDC hdc, int cx, int cy) {
    HBRUSH hBrush;
    HBRUSH hBrush2;
    HBRUSH hBrush3;
    HBRUSH hBrush4;
    HBRUSH hBrush5;
    HBRUSH hBrush6;
    HBRUSH hBrush7;
    HBRUSH hBrush8;
    HBRUSH hBrush9;
    HBRUSH hBrush10;
    HBRUSH hBrush11;
    HBRUSH hBrush12;
    hBrush = CreateSolidBrush(RGB(30, 30, 30)); //black
    hBrush2 = CreateSolidBrush(RGB(255, 0, 0)); //red
    hBrush3 = CreateSolidBrush(RGB(99, 0, 42)); //red2
    hBrush4 = CreateSolidBrush(RGB(173, 173, 173)); //Lgray
    hBrush5 = CreateSolidBrush(RGB(128, 128, 128)); //gray
    hBrush6 = CreateSolidBrush(RGB(255, 255, 255)); //White
    hBrush7 = CreateSolidBrush(RGB(255, 205, 0)); //Yellow
    hBrush8 = CreateSolidBrush(RGB(169, 169, 169)); //White2
    hBrush9 = CreateSolidBrush(RGB(0, 128, 0)); //Green2
    hBrush10 = CreateSolidBrush(RGB(0, 180, 0)); //Green
    hBrush11 = CreateSolidBrush(RGB(0, 0, 255)); //Green
    hBrush12 = CreateSolidBrush(RGB(205, 133, 63)); //

    //240 

    RECT rect1 = { 100 - 122 + cx, 100 - 162 + cy, 144 - 122 + cx, 122 - 162 + cy }; //голова верх
    FillRect(hdc, &rect1, hBrush5);
    RECT rect2 = { 96 - 122 + cx, 135 - 162 + cy, 148 - 122 + cx, 119 - 162 + cy }; //голова
    FillRect(hdc, &rect2, hBrush5);
    RECT rect3 = { 104 - 122 + cx, 135 - 162 + cy, 140 - 122 + cx, 175 - 162 + cy }; //тело
    FillRect(hdc, &rect3, hBrush8);
    RECT rect4 = { 108 - 122 + cx, 175 - 162 + cy, 136 - 122 + cx, 183 - 162 + cy }; //ноги верх
    FillRect(hdc, &rect4, hBrush3);
    RECT rect5 = { 110 - 122 + cx, 183 - 162 + cy, 134 - 122 + cx, 185 - 162 + cy }; //ноги верх 2
    FillRect(hdc, &rect5, hBrush3);
    RECT rect6 = { 110 - 122 + cx, 185 - 162 + cy, 120 - 122 + cx, 200 - 162 + cy }; //лев нога
    FillRect(hdc, &rect6, hBrush4);
    RECT rect7 = { 102 - 122 + cx, 200 - 162 + cy, 120 - 122 + cx, 208 - 162 + cy }; //лев нога 2
    FillRect(hdc, &rect7, hBrush);
    RECT rect8 = { 124 - 122 + cx, 185 - 162 + cy, 134 - 122 + cx, 200 - 162 + cy }; //прав нога 
    FillRect(hdc, &rect8, hBrush4);
    RECT rect9 = { 124 - 122 + cx, 200 - 162 + cy, 142 - 122 + cx, 208 - 162 + cy }; //прав нога 2
    FillRect(hdc, &rect9, hBrush);

    RECT rect10 = { 92 - 122 + cx, 139 - 162 + cy, 104 - 122 + cx, 149 - 162 + cy }; //Лев рука
    FillRect(hdc, &rect10, hBrush9);
    RECT rect80 = { 92 - 122 + cx, 141 - 162 + cy, 98 - 122 + cx, 146 - 162 + cy }; //Лев рука
    FillRect(hdc, &rect80, hBrush9);
    RECT rect79 = { 96 - 122 + cx, 139 - 162 + cy, 106 - 122 + cx, 143 - 162 + cy }; //Лев рука
    FillRect(hdc, &rect79, hBrush9);
    RECT rect11 = { 90 - 122 + cx, 141 - 162 + cy, 98 - 122 + cx, 151 - 162 + cy }; //Лев рукa 2
    FillRect(hdc, &rect11, hBrush9);
    RECT rect12 = { 88 - 122 + cx, 143 - 162 + cy, 98 - 122 + cx, 151 - 162 + cy }; //Лев рукa 3
    FillRect(hdc, &rect12, hBrush9);
    RECT rect13 = { 86 - 122 + cx, 145 - 162 + cy, 96 - 122 + cx, 165 - 162 + cy }; //Лев рукa 4
    FillRect(hdc, &rect13, hBrush9);

    RECT rect100 = { 86 - 122 + cx, 155 - 162 + cy, 96 - 122 + cx, 165 - 162 + cy }; //Лев руЧКАА темн
    FillRect(hdc, &rect100, hBrush5);
    RECT rect101 = { 88 - 122 + cx, 157 - 162 + cy, 94 - 122 + cx, 163 - 162 + cy }; //Лев руЧКАА свет
    FillRect(hdc, &rect101, hBrush4);
    RECT rect102 = { 86 - 122 + cx, 155 - 162 + cy, 88 - 122 + cx, 157 - 162 + cy }; //Лев руЧКАА темн
    FillRect(hdc, &rect102, hBrush5);


    RECT rect14 = { 88 - 122 + cx, 165 - 162 + cy, 94 - 122 + cx, 167 - 162 + cy }; //Лев рукa 5
    FillRect(hdc, &rect14, hBrush4);

    RECT rect15 = { 86 - 122 + cx, 167 - 162 + cy, 96 - 122 + cx, 179 - 162 + cy }; //Лев рукa 6
    FillRect(hdc, &rect15, hBrush4);
    RECT rect16 = { 96 - 122 + cx, 169 - 162 + cy, 102 - 122 + cx, 173 - 162 + cy }; //Лев Палец
    FillRect(hdc, &rect16, hBrush4);
    RECT rect29 = { 96 - 122 + cx, 169 - 162 + cy, 98 - 122 + cx, 173 - 162 + cy }; //Прав Палец
    FillRect(hdc, &rect29, hBrush5);

    RECT rect17 = { 140 - 122 + cx, 139 - 162 + cy, 152 - 122 + cx, 149 - 162 + cy }; //Прав рука
    FillRect(hdc, &rect17, hBrush9);
    RECT rect18 = { 146 - 122 + cx, 141 - 162 + cy, 154 - 122 + cx, 151 - 162 + cy }; //Прав рука 2
    FillRect(hdc, &rect18, hBrush9);
    RECT rect19 = { 146 - 122 + cx, 143 - 162 + cy, 156 - 122 + cx, 151 - 162 + cy }; //Прав рука 3
    FillRect(hdc, &rect19, hBrush9);
    RECT rect20 = { 148 - 122 + cx, 145 - 162 + cy, 158 - 122 + cx, 165 - 162 + cy }; //прав рука 4
    FillRect(hdc, &rect20, hBrush9);
    RECT rect21 = { 150 - 122 + cx, 165 - 162 + cy, 156 - 122 + cx, 167 - 162 + cy }; //прав рука 5
    FillRect(hdc, &rect21, hBrush4);
    RECT rect22 = { 148 - 122 + cx, 167 - 162 + cy, 158 - 122 + cx, 179 - 162 + cy }; //Прав рука 6
    FillRect(hdc, &rect22, hBrush4);
    RECT rect23 = { 142 - 122 + cx, 169 - 162 + cy, 148 - 122 + cx, 173 - 162 + cy }; //Прав Палец
    FillRect(hdc, &rect23, hBrush4);
    RECT rect28 = { 146 - 122 + cx, 169 - 162 + cy, 148 - 122 + cx, 173 - 162 + cy }; //Прав Палец
    FillRect(hdc, &rect28, hBrush5);

    RECT rect103 = { 148 - 122 + cx, 155 - 162 + cy, 158 - 122 + cx, 165 - 162 + cy }; //Лев руЧКАА темн
    FillRect(hdc, &rect103, hBrush5);
    RECT rect104 = { 150 - 122 + cx, 157 - 162 + cy, 156 - 122 + cx, 163 - 162 + cy }; //Лев руЧКАА свет
    FillRect(hdc, &rect104, hBrush4);
    RECT rect105 = { 86 - 122 + cx, 155 - 162 + cy, 88 - 122 + cx, 157 - 162 + cy }; //Лев руЧКАА темн
    FillRect(hdc, &rect105, hBrush5);

    RECT rect24 = { 110 - 122 + cx, 88 - 162 + cy, 118 - 122 + cx, 98 - 162 + cy }; //Лев Лампа
    FillRect(hdc, &rect24, hBrush7);
    RECT rect25 = { 112 - 122 + cx, 86 - 162 + cy, 116 - 122 + cx, 100 - 162 + cy }; //Лев Лампа 1
    FillRect(hdc, &rect25, hBrush7);
    RECT rect110 = { 112 - 122 + cx, 88 - 162 + cy, 116 - 122 + cx, 90 - 162 + cy };
    FillRect(hdc, &rect110, hBrush6);
    RECT rect106 = { 114 - 122 + cx, 90 - 162 + cy, 116 - 122 + cx, 92 - 162 + cy };
    FillRect(hdc, &rect106, hBrush2);
    RECT rect107 = { 112 - 122 + cx, 92 - 162 + cy, 114 - 122 + cx, 94 - 162 + cy };
    FillRect(hdc, &rect107, hBrush2);
    RECT rect108 = { 114 - 122 + cx, 94 - 162 + cy, 116 - 122 + cx, 96 - 162 + cy };
    FillRect(hdc, &rect108, hBrush2);
    RECT rect109 = { 112 - 122 + cx, 96 - 162 + cy, 114 - 122 + cx, 98 - 162 + cy };
    FillRect(hdc, &rect109, hBrush2);

    RECT rect26 = { 128 - 122 + cx, 88 - 162 + cy, 136 - 122 + cx, 98 - 162 + cy }; //Прав Лампа
    FillRect(hdc, &rect26, hBrush7);
    RECT rect27 = { 130 - 122 + cx, 86 - 162 + cy, 134 - 122 + cx, 100 - 162 + cy }; //Прав Лампа 1
    FillRect(hdc, &rect27, hBrush7);
    RECT rect111 = { 130 - 122 + cx, 88 - 162 + cy, 134 - 122 + cx, 90 - 162 + cy };
    FillRect(hdc, &rect111, hBrush6);
    RECT rect112 = { 130 - 122 + cx, 90 - 162 + cy, 132 - 122 + cx, 92 - 162 + cy };
    FillRect(hdc, &rect112, hBrush2);
    RECT rect113 = { 132 - 122 + cx, 92 - 162 + cy, 134 - 122 + cx, 94 - 162 + cy };
    FillRect(hdc, &rect113, hBrush2);
    RECT rect114 = { 130 - 122 + cx, 94 - 162 + cy, 132 - 122 + cx, 96 - 162 + cy };
    FillRect(hdc, &rect114, hBrush2);
    RECT rect115 = { 132 - 122 + cx, 96 - 162 + cy, 134 - 122 + cx, 98 - 162 + cy };
    FillRect(hdc, &rect115, hBrush2);


    RECT rect30 = { 148 - 122 + cx, 176 - 162 + cy, 158 - 122 + cx, 179 - 162 + cy }; //GRAY
    FillRect(hdc, &rect30, hBrush5);
    RECT rect31 = { 148 - 122 + cx, 167 - 162 + cy, 158 - 122 + cx, 169 - 162 + cy };
    FillRect(hdc, &rect31, hBrush5);
    RECT rect32 = { 86 - 122 + cx, 176 - 162 + cy, 96 - 122 + cx, 179 - 162 + cy };
    FillRect(hdc, &rect32, hBrush5);
    RECT rect33 = { 86 - 122 + cx, 167 - 162 + cy, 96 - 122 + cx, 169 - 162 + cy };
    FillRect(hdc, &rect33, hBrush5);
    RECT rect34 = { 102 - 122 + cx, 200 - 162 + cy, 120 - 122 + cx, 206 - 162 + cy };
    FillRect(hdc, &rect34, hBrush5);
    RECT rect35 = { 124 - 122 + cx, 200 - 162 + cy, 142 - 122 + cx, 206 - 162 + cy };
    FillRect(hdc, &rect35, hBrush5);

    RECT rect36 = { 102 - 122 + cx, 206 - 162 + cy, 120 - 122 + cx, 208 - 162 + cy }; //red2
    FillRect(hdc, &rect36, hBrush3);
    RECT rect37 = { 124 - 122 + cx, 206 - 162 + cy, 142 - 122 + cx, 208 - 162 + cy };
    FillRect(hdc, &rect37, hBrush3);

    RECT rect38 = { 108 - 122 + cx, 108 - 162 + cy, 120 - 122 + cx, 116 - 162 + cy }; //Левый глаз
    FillRect(hdc, &rect38, hBrush7);
    RECT rect39 = { 110 - 122 + cx, 106 - 162 + cy, 118 - 122 + cx, 118 - 162 + cy }; //
    FillRect(hdc, &rect39, hBrush7);

    RECT rect40 = { 126 - 122 + cx, 108 - 162 + cy, 138 - 122 + cx, 116 - 162 + cy }; //Правый глаз
    FillRect(hdc, &rect40, hBrush7);
    RECT rect41 = { 128 - 122 + cx, 106 - 162 + cy, 136 - 122 + cx, 118 - 162 + cy }; //
    FillRect(hdc, &rect41, hBrush7);

    RECT rect42 = { 108 - 122 + cx, 108 - 162 + cy, 112 - 122 + cx, 116 - 162 + cy }; //Свет Глаз лев
    FillRect(hdc, &rect42, hBrush6);
    RECT rect43 = { 112 - 122 + cx, 110 - 162 + cy, 114 - 122 + cx, 114 - 162 + cy };
    FillRect(hdc, &rect43, hBrush6);
    RECT rect46 = { 113 - 122 + cx, 110 - 162 + cy, 117 - 122 + cx, 114 - 162 + cy }; //Глазок Л
    FillRect(hdc, &rect46, hBrush3);

    RECT rect44 = { 126 - 122 + cx, 108 - 162 + cy, 130 - 122 + cx, 116 - 162 + cy }; //Свет Глаз Прав
    FillRect(hdc, &rect44, hBrush6);
    RECT rect45 = { 130 - 122 + cx, 110 - 162 + cy, 132 - 122 + cx, 114 - 162 + cy };
    FillRect(hdc, &rect45, hBrush6);
    RECT rect47 = { 131 - 122 + cx, 110 - 162 + cy, 135 - 122 + cx, 114 - 162 + cy }; //Глазок П
    FillRect(hdc, &rect47, hBrush3);

    RECT rect48 = { 120 - 122 + cx, 118 - 162 + cy, 126 - 122 + cx, 122 - 162 + cy }; //Нос
    FillRect(hdc, &rect48, hBrush3);

    RECT rect49 = { 102 - 122 + cx, 124 - 162 + cy, 142 - 122 + cx, 132 - 162 + cy }; //Рот
    FillRect(hdc, &rect49, hBrush);
    RECT rect50 = { 112 - 122 + cx, 124 - 162 + cy, 118 - 122 + cx, 130 - 162 + cy }; //Зуб лев
    FillRect(hdc, &rect50, hBrush6);
    RECT rect51 = { 128 - 122 + cx, 124 - 162 + cy, 134 - 122 + cx, 130 - 162 + cy }; //Зуб прав
    FillRect(hdc, &rect51, hBrush6);

    RECT rect52 = { 104 - 122 + cx, 136 - 162 + cy, 108 - 122 + cx, 169 - 162 + cy }; //тело зелен
    FillRect(hdc, &rect52, hBrush9);
    RECT rect53 = { 108 - 122 + cx, 136 - 162 + cy, 112 - 122 + cx, 169 - 162 + cy }; //тело свет зелен
    FillRect(hdc, &rect53, hBrush10);
    RECT rect54 = { 112 - 122 + cx, 140 - 162 + cy, 114 - 122 + cx, 169 - 162 + cy }; //тело свет зелен
    FillRect(hdc, &rect54, hBrush10);
    RECT rect55 = { 114 - 122 + cx, 144 - 162 + cy, 116 - 122 + cx, 169 - 162 + cy }; //тело свет зелен
    FillRect(hdc, &rect55, hBrush10);
    RECT rect56 = { 116 - 122 + cx, 148 - 162 + cy, 118 - 122 + cx, 169 - 162 + cy }; //тело свет зелен
    FillRect(hdc, &rect56, hBrush10);
    RECT rect57 = { 118 - 122 + cx, 154 - 162 + cy, 120 - 122 + cx, 169 - 162 + cy }; //тело свет зелен
    FillRect(hdc, &rect57, hBrush10);

    RECT rect70 = { 136 - 122 + cx, 136 - 162 + cy, 140 - 122 + cx, 169 - 162 + cy }; //тело зелен
    FillRect(hdc, &rect70, hBrush9);
    RECT rect71 = { 132 - 122 + cx, 136 - 162 + cy, 136 - 122 + cx, 169 - 162 + cy }; //тело зелен
    FillRect(hdc, &rect71, hBrush10);
    RECT rect72 = { 130 - 122 + cx, 140 - 162 + cy, 132 - 122 + cx, 169 - 162 + cy }; //тело зелен
    FillRect(hdc, &rect72, hBrush10);
    RECT rect73 = { 128 - 122 + cx, 144 - 162 + cy, 132 - 122 + cx, 169 - 162 + cy }; //тело зелен
    FillRect(hdc, &rect73, hBrush10);
    RECT rect74 = { 126 - 122 + cx, 148 - 162 + cy, 132 - 122 + cx, 169 - 162 + cy }; //тело зелен
    FillRect(hdc, &rect74, hBrush10);
    RECT rect75 = { 124 - 122 + cx, 154 - 162 + cy, 132 - 122 + cx, 169 - 162 + cy }; //тело зелен
    FillRect(hdc, &rect75, hBrush10);

    RECT rect76 = { 118 - 122 + cx, 160 - 162 + cy, 126 - 122 + cx, 164 - 162 + cy }; //Кнопка гор
    FillRect(hdc, &rect76, hBrush2);

    RECT rect78 = { 120 - 122 + cx, 158 - 162 + cy, 124 - 122 + cx, 166 - 162 + cy }; //Кнопка гор
    FillRect(hdc, &rect78, hBrush2);

    RECT rect77 = { 120 - 122 + cx, 160 - 162 + cy, 124 - 122 + cx, 164 - 162 + cy }; //Кнопка желтая
    FillRect(hdc, &rect77, hBrush7);

    DeleteObject(hBrush);
    DeleteObject(hBrush2);
    DeleteObject(hBrush3);
    DeleteObject(hBrush4);
    DeleteObject(hBrush5);
    DeleteObject(hBrush6);
    DeleteObject(hBrush7);
    DeleteObject(hBrush8);
    DeleteObject(hBrush9);
    DeleteObject(hBrush10);
    DeleteObject(hBrush11);
    DeleteObject(hBrush12);
#ifdef DEBUG_GAME
    // Зона захвата 
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 20, cy - 20, cx + 20, cy + 20);

    MoveToEx(hdc, cx - 40, cy, NULL);
    LineTo(hdc, cx + 40, cy);
    MoveToEx(hdc, cx, cy - 40, NULL);
    LineTo(hdc, cx, cy + 40);

    DeleteObject(hPenZone);
#endif

}
void zayc(HDC hdc, int cx, int cy) {
    HBRUSH hBrush;
    HBRUSH hBrush2;
    HBRUSH hBrush3;
    HBRUSH hBrush4;
    HBRUSH hBrush5;
    HBRUSH hBrush6;
    HBRUSH hBrush7;
    HBRUSH hBrush8;
    HBRUSH hBrush9;
    HBRUSH hBrush10;
    HBRUSH hBrush11;
    HBRUSH hBrush12;
    hBrush = CreateSolidBrush(RGB(30, 30, 30)); //black
    hBrush2 = CreateSolidBrush(RGB(255, 0, 0)); //red
    hBrush3 = CreateSolidBrush(RGB(99, 0, 42)); //red2
    hBrush4 = CreateSolidBrush(RGB(173, 173, 173)); //Lgray
    hBrush5 = CreateSolidBrush(RGB(128, 128, 128)); //gray
    hBrush6 = CreateSolidBrush(RGB(255, 255, 255)); //White
    hBrush7 = CreateSolidBrush(RGB(255, 205, 0)); //Yellow
    hBrush8 = CreateSolidBrush(RGB(169, 169, 169)); //White2
    hBrush9 = CreateSolidBrush(RGB(0, 128, 0)); //Green2
    hBrush10 = CreateSolidBrush(RGB(0, 180, 0)); //Green
    hBrush11 = CreateSolidBrush(RGB(0, 0, 255)); //Green
    hBrush12 = CreateSolidBrush(RGB(205, 133, 63)); //

    RECT rect200 = { 200 - 202 + cx, 100 - 162 + cy, 224 - 202 + cx, 120 - 162 + cy }; //
    FillRect(hdc, &rect200, hBrush12);
    RECT rect201 = { 198 - 202 + cx, 104 - 162 + cy, 222 - 202 + cx, 126 - 162 + cy }; //
    FillRect(hdc, &rect201, hBrush12);
    RECT rect202 = { 196 - 202 + cx, 106 - 162 + cy, 222 - 202 + cx, 128 - 162 + cy }; //
    FillRect(hdc, &rect202, hBrush12);
    RECT rect203 = { 192 - 202 + cx, 110 - 162 + cy, 222 - 202 + cx, 128 - 162 + cy }; //
    FillRect(hdc, &rect203, hBrush12);
    RECT rect204 = { 190 - 202 + cx, 112 - 162 + cy, 220 - 202 + cx, 126 - 162 + cy }; //
    FillRect(hdc, &rect204, hBrush12);
    RECT rect205 = { 188 - 202 + cx, 114 - 162 + cy, 220 - 202 + cx, 124 - 162 + cy }; //
    FillRect(hdc, &rect205, hBrush12);
    RECT rect206 = { 194 - 202 + cx, 128 - 162 + cy, 220 - 202 + cx, 130 - 162 + cy }; //
    FillRect(hdc, &rect206, hBrush12);
    RECT rect207 = { 196 - 202 + cx, 130 - 162 + cy, 218 - 202 + cx, 132 - 162 + cy }; //
    FillRect(hdc, &rect207, hBrush12);
    RECT rect208 = { 200 - 202 + cx, 132 - 162 + cy, 210 - 202 + cx, 134 - 162 + cy }; //Шея
    FillRect(hdc, &rect208, hBrush12);
    RECT rect287 = { 200 - 202 + cx, 132 - 162 + cy, 202 - 202 + cx, 134 - 162 + cy }; //Шея
    FillRect(hdc, &rect287, hBrush);
    RECT rect288 = { 204 - 202 + cx, 132 - 162 + cy, 206 - 202 + cx, 134 - 162 + cy }; //Шея
    FillRect(hdc, &rect288, hBrush);
    RECT rect289 = { 208 - 202 + cx, 132 - 162 + cy, 210 - 202 + cx, 134 - 162 + cy }; //Шея
    FillRect(hdc, &rect289, hBrush);
    RECT rect209 = { 198 - 202 + cx, 132 - 162 + cy, 200 - 202 + cx, 134 - 162 + cy }; //Воротник бел
    FillRect(hdc, &rect209, hBrush7);
    RECT rect210 = { 198 - 202 + cx, 134 - 162 + cy, 208 - 202 + cx, 136 - 162 + cy }; //Воротник бел
    FillRect(hdc, &rect210, hBrush7);

    RECT rect290 = { 216 - 202 + cx, 130 - 162 + cy, 218 - 202 + cx, 132 - 162 + cy }; //ШЕЯ
    FillRect(hdc, &rect290, hBrush);
    RECT rect291 = { 218 - 202 + cx, 128 - 162 + cy, 220 - 202 + cx, 130 - 162 + cy }; //
    FillRect(hdc, &rect291, hBrush);
    RECT rect305 = { 220 - 202 + cx, 126 - 162 + cy, 222 - 202 + cx, 128 - 162 + cy }; //
    FillRect(hdc, &rect305, hBrush);
    RECT rect306 = { 220 - 202 + cx, 122 - 162 + cy, 222 - 202 + cx, 124 - 162 + cy }; //
    FillRect(hdc, &rect306, hBrush);
    RECT rect292 = { 194 - 202 + cx, 128 - 162 + cy, 196 - 202 + cx, 130 - 162 + cy }; //
    FillRect(hdc, &rect292, hBrush);
    RECT rect293 = { 196 - 202 + cx, 130 - 162 + cy, 198 - 202 + cx, 132 - 162 + cy }; //
    FillRect(hdc, &rect293, hBrush);
    RECT rect294 = { 192 - 202 + cx, 126 - 162 + cy, 194 - 202 + cx, 128 - 162 + cy }; //
    FillRect(hdc, &rect294, hBrush);
    RECT rect295 = { 190 - 202 + cx, 124 - 162 + cy, 192 - 202 + cx, 126 - 162 + cy }; //
    FillRect(hdc, &rect295, hBrush);
    RECT rect296 = { 188 - 202 + cx, 122 - 162 + cy, 190 - 202 + cx, 124 - 162 + cy }; //
    FillRect(hdc, &rect296, hBrush);
    RECT rect297 = { 188 - 202 + cx, 118 - 162 + cy, 190 - 202 + cx, 120 - 162 + cy }; //
    FillRect(hdc, &rect297, hBrush);
    RECT rect298 = { 188 - 202 + cx, 114 - 162 + cy, 190 - 202 + cx, 116 - 162 + cy }; //
    FillRect(hdc, &rect298, hBrush);
    RECT rect299 = { 192 - 202 + cx, 110 - 162 + cy, 194 - 202 + cx, 112 - 162 + cy }; //
    FillRect(hdc, &rect299, hBrush);

    RECT rect300 = { 200 - 202 + cx, 110 - 162 + cy, 206 - 202 + cx, 112 - 162 + cy }; //
    FillRect(hdc, &rect300, hBrush);
    RECT rect301 = { 202 - 202 + cx, 108 - 162 + cy, 204 - 202 + cx, 114 - 162 + cy }; //
    FillRect(hdc, &rect301, hBrush);
    RECT rect302 = { 204 - 202 + cx, 106 - 162 + cy, 206 - 202 + cx, 108 - 162 + cy }; //
    FillRect(hdc, &rect302, hBrush);
    RECT rect303 = { 204 - 202 + cx, 108 - 162 + cy, 206 - 202 + cx, 110 - 162 + cy }; //
    FillRect(hdc, &rect303, hBrush6);
    RECT rect304 = { 206 - 202 + cx, 102 - 162 + cy, 210 - 202 + cx, 104 - 162 + cy }; //
    FillRect(hdc, &rect304, hBrush);
    RECT rect307 = { 222 - 202 + cx, 118 - 162 + cy, 224 - 202 + cx, 120 - 162 + cy }; //
    FillRect(hdc, &rect307, hBrush);
    RECT rect308 = { 200 - 202 + cx, 114 - 162 + cy, 204 - 202 + cx, 116 - 162 + cy }; //
    FillRect(hdc, &rect308, hBrush2);
    RECT rect309 = { 200 - 202 + cx, 114 - 162 + cy, 204 - 202 + cx, 116 - 162 + cy }; //
    FillRect(hdc, &rect309, hBrush9);
    RECT rect310 = { 196 - 202 + cx, 112 - 162 + cy, 202 - 202 + cx, 114 - 162 + cy }; //
    FillRect(hdc, &rect310, hBrush9);
    RECT rect311 = { 198 - 202 + cx, 110 - 162 + cy, 200 - 202 + cx, 112 - 162 + cy }; //
    FillRect(hdc, &rect311, hBrush9);
    RECT rect312 = { 200 - 202 + cx, 108 - 162 + cy, 202 - 202 + cx, 110 - 162 + cy }; //
    FillRect(hdc, &rect312, hBrush9);
    RECT rect313 = { 202 - 202 + cx, 106 - 162 + cy, 204 - 202 + cx, 108 - 162 + cy }; //
    FillRect(hdc, &rect313, hBrush9);

    RECT rect314 = { 204 - 202 + cx, 116 - 162 + cy, 206 - 202 + cx, 124 - 162 + cy }; //
    FillRect(hdc, &rect314, hBrush);
    RECT rect315 = { 200 - 202 + cx, 122 - 162 + cy, 206 - 202 + cx, 124 - 162 + cy }; //
    FillRect(hdc, &rect315, hBrush);
    RECT rect316 = { 198 - 202 + cx, 118 - 162 + cy, 200 - 202 + cx, 122 - 162 + cy }; //
    FillRect(hdc, &rect316, hBrush);
    RECT rect317 = { 206 - 202 + cx, 124 - 162 + cy, 212 - 202 + cx, 126 - 162 + cy }; //
    FillRect(hdc, &rect317, hBrush);
    RECT rect318 = { 212 - 202 + cx, 122 - 162 + cy, 214 - 202 + cx, 124 - 162 + cy }; //
    FillRect(hdc, &rect318, hBrush);
    RECT rect319 = { 206 - 202 + cx, 116 - 162 + cy, 208 - 202 + cx, 122 - 162 + cy }; //
    FillRect(hdc, &rect319, hBrush);
    RECT rect320 = { 206 - 202 + cx, 118 - 162 + cy, 208 - 202 + cx, 120 - 162 + cy }; //
    FillRect(hdc, &rect320, hBrush6);
    RECT rect321 = { 202 - 202 + cx, 124 - 162 + cy, 206 - 202 + cx, 126 - 162 + cy }; //
    FillRect(hdc, &rect321, hBrush6);
    RECT rect322 = { 208 - 202 + cx, 118 - 162 + cy, 210 - 202 + cx, 120 - 162 + cy }; //
    FillRect(hdc, &rect322, hBrush);

    RECT rect323 = { 210 - 202 + cx, 116 - 162 + cy, 216 - 202 + cx, 118 - 162 + cy }; //
    FillRect(hdc, &rect323, hBrush9);
    RECT rect324 = { 214 - 202 + cx, 118 - 162 + cy, 218 - 202 + cx, 120 - 162 + cy }; //
    FillRect(hdc, &rect324, hBrush9);
    RECT rect325 = { 216 - 202 + cx, 114 - 162 + cy, 218 - 202 + cx, 118 - 162 + cy }; //
    FillRect(hdc, &rect325, hBrush);
    RECT rect326 = { 214 - 202 + cx, 112 - 162 + cy, 216 - 202 + cx, 116 - 162 + cy }; //
    FillRect(hdc, &rect326, hBrush);
    RECT rect327 = { 216 - 202 + cx, 112 - 162 + cy, 218 - 202 + cx, 114 - 162 + cy }; //
    FillRect(hdc, &rect327, hBrush6);
    RECT rect328 = { 216 - 202 + cx, 110 - 162 + cy, 218 - 202 + cx, 112 - 162 + cy }; //
    FillRect(hdc, &rect328, hBrush);
    RECT rect329 = { 212 - 202 + cx, 112 - 162 + cy, 214 - 202 + cx, 116 - 162 + cy }; //
    FillRect(hdc, &rect329, hBrush9);
    RECT rect330 = { 214 - 202 + cx, 110 - 162 + cy, 216 - 202 + cx, 112 - 162 + cy }; //
    FillRect(hdc, &rect330, hBrush9);
    RECT rect331 = { 220 - 202 + cx, 108 - 162 + cy, 222 - 202 + cx, 110 - 162 + cy }; //
    FillRect(hdc, &rect331, hBrush);
    RECT rect332 = { 218 - 202 + cx, 106 - 162 + cy, 220 - 202 + cx, 108 - 162 + cy }; //
    FillRect(hdc, &rect332, hBrush);
    RECT rect333 = { 220 - 202 + cx, 98 - 162 + cy, 230 - 202 + cx, 104 - 162 + cy }; //
    FillRect(hdc, &rect333, hBrush12);
    RECT rect334 = { 222 - 202 + cx, 96 - 162 + cy, 238 - 202 + cx, 102 - 162 + cy }; //
    FillRect(hdc, &rect334, hBrush12);
    RECT rect335 = { 224 - 202 + cx, 94 - 162 + cy, 244 - 202 + cx, 100 - 162 + cy }; //
    FillRect(hdc, &rect335, hBrush12);
    RECT rect336 = { 228 - 202 + cx, 92 - 162 + cy, 240 - 202 + cx, 98 - 162 + cy }; //
    FillRect(hdc, &rect336, hBrush12);


    RECT rect337 = { 206 - 202 + cx, 98 - 162 + cy, 218 - 202 + cx, 100 - 162 + cy }; //
    FillRect(hdc, &rect337, hBrush12);
    RECT rect339 = { 208 - 202 + cx, 90 - 162 + cy, 220 - 202 + cx, 98 - 162 + cy }; //
    FillRect(hdc, &rect339, hBrush12);
    RECT rect340 = { 210 - 202 + cx, 88 - 162 + cy, 224 - 202 + cx, 94 - 162 + cy }; //
    FillRect(hdc, &rect340, hBrush12);
    RECT rect341 = { 212 - 202 + cx, 86 - 162 + cy, 230 - 202 + cx, 90 - 162 + cy }; //
    FillRect(hdc, &rect341, hBrush12);
    RECT rect342 = { 214 - 202 + cx, 84 - 162 + cy, 226 - 202 + cx, 86 - 162 + cy }; //
    FillRect(hdc, &rect342, hBrush12);

    RECT rect211 = { 194 - 202 + cx, 136 - 162 + cy, 210 - 202 + cx, 160 - 162 + cy }; //
    FillRect(hdc, &rect211, hBrush10);
    RECT rect212 = { 192 - 202 + cx, 138 - 162 + cy, 212 - 202 + cx, 158 - 162 + cy }; //
    FillRect(hdc, &rect212, hBrush10);
    RECT rect213 = { 190 - 202 + cx, 140 - 162 + cy, 216 - 202 + cx, 152 - 162 + cy }; //
    FillRect(hdc, &rect213, hBrush10);
    RECT rect217 = { 188 - 202 + cx, 142 - 162 + cy, 218 - 202 + cx, 148 - 162 + cy }; //
    FillRect(hdc, &rect217, hBrush10);
    RECT rect218 = { 186 - 202 + cx, 144 - 162 + cy, 220 - 202 + cx, 146 - 162 + cy }; //
    FillRect(hdc, &rect218, hBrush10);
    RECT rect219 = { 200 - 202 + cx, 146 - 162 + cy, 222 - 202 + cx, 148 - 162 + cy }; //
    FillRect(hdc, &rect219, hBrush10);
    RECT rect220 = { 200 - 202 + cx, 148 - 162 + cy, 220 - 202 + cx, 150 - 162 + cy }; //
    FillRect(hdc, &rect220, hBrush10);

    RECT rect214 = { 188 - 202 + cx, 148 - 162 + cy, 192 - 202 + cx, 158 - 162 + cy }; //Рука 1 л
    FillRect(hdc, &rect214, hBrush12);
    RECT rect215 = { 190 - 202 + cx, 158 - 162 + cy, 192 - 202 + cx, 160 - 162 + cy }; //Рука 2 л
    FillRect(hdc, &rect215, hBrush12);
    RECT rect216 = { 186 - 202 + cx, 152 - 162 + cy, 188 - 202 + cx, 156 - 162 + cy }; //Палец лев
    FillRect(hdc, &rect216, hBrush12);

    RECT rect221 = { 200 - 202 + cx, 148 - 162 + cy, 220 - 202 + cx, 150 - 162 + cy }; //
    FillRect(hdc, &rect221, hBrush10);

    RECT rect222 = { 216 - 202 + cx, 150 - 162 + cy, 218 - 202 + cx, 152 - 162 + cy }; //Прав РУКА
    FillRect(hdc, &rect222, hBrush12);
    RECT rect223 = { 212 - 202 + cx, 152 - 162 + cy, 218 - 202 + cx, 158 - 162 + cy }; //
    FillRect(hdc, &rect223, hBrush12);
    RECT rect224 = { 212 - 202 + cx, 158 - 162 + cy, 216 - 202 + cx, 160 - 162 + cy }; //
    FillRect(hdc, &rect224, hBrush12);
    RECT rect225 = { 212 - 202 + cx, 160 - 162 + cy, 214 - 202 + cx, 162 - 162 + cy }; //
    FillRect(hdc, &rect225, hBrush12);

    RECT rect226 = { 192 - 202 + cx, 158 - 162 + cy, 194 - 202 + cx, 162 - 162 + cy }; //Лев пикс бел
    FillRect(hdc, &rect226, hBrush5);
    RECT rect227 = { 210 - 202 + cx, 158 - 162 + cy, 212 - 202 + cx, 164 - 162 + cy }; //Прав пикс бел
    FillRect(hdc, &rect227, hBrush5);
    RECT rect228 = { 194 - 202 + cx, 160 - 162 + cy, 210 - 202 + cx, 164 - 162 + cy }; //бел пояс
    FillRect(hdc, &rect228, hBrush5);
    RECT rect229 = { 196 - 202 + cx, 160 - 162 + cy, 210 - 202 + cx, 166 - 162 + cy }; //бел пояс
    FillRect(hdc, &rect229, hBrush5);
    RECT rect230 = { 192 - 202 + cx, 162 - 162 + cy, 194 - 202 + cx, 170 - 162 + cy }; //штаны
    FillRect(hdc, &rect230, hBrush10);
    RECT rect231 = { 194 - 202 + cx, 164 - 162 + cy, 196 - 202 + cx, 178 - 162 + cy }; //штаны
    FillRect(hdc, &rect231, hBrush10);
    RECT rect232 = { 196 - 202 + cx, 178 - 162 + cy, 198 - 202 + cx, 180 - 162 + cy };
    FillRect(hdc, &rect232, hBrush);
    RECT rect233 = { 198 - 202 + cx, 180 - 162 + cy, 204 - 202 + cx, 182 - 162 + cy };
    FillRect(hdc, &rect233, hBrush);
    RECT rect234 = { 204 - 202 + cx, 176 - 162 + cy, 206 - 202 + cx, 180 - 162 + cy };
    FillRect(hdc, &rect234, hBrush);
    RECT rect235 = { 202 - 202 + cx, 174 - 162 + cy, 204 - 202 + cx, 176 - 162 + cy };
    FillRect(hdc, &rect235, hBrush);
    RECT rect236 = { 202 - 202 + cx, 174 - 162 + cy, 204 - 202 + cx, 176 - 162 + cy };
    FillRect(hdc, &rect236, hBrush);
    RECT rect237 = { 206 - 202 + cx, 180 - 162 + cy, 218 - 202 + cx, 182 - 162 + cy };
    FillRect(hdc, &rect237, hBrush);
    RECT rect238 = { 218 - 202 + cx, 176 - 162 + cy, 220 - 202 + cx, 180 - 162 + cy };
    FillRect(hdc, &rect238, hBrush);
    RECT rect239 = { 216 - 202 + cx, 172 - 162 + cy, 218 - 202 + cx, 176 - 162 + cy };
    FillRect(hdc, &rect239, hBrush);
    RECT rect240 = { 214 - 202 + cx, 166 - 162 + cy, 216 - 202 + cx, 170 - 162 + cy };
    FillRect(hdc, &rect240, hBrush);
    RECT rect241 = { 210 - 202 + cx, 164 - 162 + cy, 214 - 202 + cx, 166 - 162 + cy };
    FillRect(hdc, &rect241, hBrush);
    RECT rect242 = { 204 - 202 + cx, 166 - 162 + cy, 210 - 202 + cx, 168 - 162 + cy };
    FillRect(hdc, &rect242, hBrush);
    RECT rect243 = { 204 - 202 + cx, 166 - 162 + cy, 210 - 202 + cx, 168 - 162 + cy };
    FillRect(hdc, &rect243, hBrush);
    RECT rect244 = { 200 - 202 + cx, 166 - 162 + cy, 202 - 202 + cx, 168 - 162 + cy };
    FillRect(hdc, &rect244, hBrush);
    RECT rect245 = { 194 - 202 + cx, 166 - 162 + cy, 200 - 202 + cx, 178 - 162 + cy };
    FillRect(hdc, &rect245, hBrush10);
    RECT rect246 = { 198 - 202 + cx, 176 - 162 + cy, 204 - 202 + cx, 180 - 162 + cy };
    FillRect(hdc, &rect246, hBrush10);
    RECT rect247 = { 200 - 202 + cx, 168 - 162 + cy, 202 - 202 + cx, 180 - 162 + cy };
    FillRect(hdc, &rect247, hBrush10);
    RECT rect248 = { 202 - 202 + cx, 166 - 162 + cy, 204 - 202 + cx, 174 - 162 + cy };
    FillRect(hdc, &rect248, hBrush10);
    RECT rect249 = { 202 - 202 + cx, 168 - 162 + cy, 216 - 202 + cx, 174 - 162 + cy };
    FillRect(hdc, &rect249, hBrush10);
    RECT rect250 = { 204 - 202 + cx, 170 - 162 + cy, 216 - 202 + cx, 176 - 162 + cy };
    FillRect(hdc, &rect250, hBrush10);
    RECT rect251 = { 206 - 202 + cx, 176 - 162 + cy, 218 - 202 + cx, 180 - 162 + cy };
    FillRect(hdc, &rect251, hBrush10);
    RECT rect252 = { 210 - 202 + cx, 166 - 162 + cy, 214 - 202 + cx, 168 - 162 + cy };
    FillRect(hdc, &rect252, hBrush10);


    RECT rect253 = { 200 - 202 + cx, 182 - 162 + cy, 218 - 202 + cx, 186 - 162 + cy };
    FillRect(hdc, &rect253, hBrush12);
    RECT rect254 = { 202 - 202 + cx, 186 - 162 + cy, 210 - 202 + cx, 190 - 162 + cy };
    FillRect(hdc, &rect254, hBrush12);
    RECT rect255 = { 212 - 202 + cx, 186 - 162 + cy, 218 - 202 + cx, 190 - 162 + cy };
    FillRect(hdc, &rect255, hBrush12);
    RECT rect256 = { 210 - 202 + cx, 186 - 162 + cy, 212 - 202 + cx, 188 - 162 + cy };
    FillRect(hdc, &rect256, hBrush12);
    RECT rect257 = { 214 - 202 + cx, 190 - 162 + cy, 220 - 202 + cx, 198 - 162 + cy };
    FillRect(hdc, &rect257, hBrush12);
    RECT rect258 = { 204 - 202 + cx, 190 - 162 + cy, 212 - 202 + cx, 198 - 162 + cy };
    FillRect(hdc, &rect258, hBrush12);
    RECT rect259 = { 206 - 202 + cx, 198 - 162 + cy, 212 - 202 + cx, 204 - 162 + cy };
    FillRect(hdc, &rect259, hBrush12);
    RECT rect260 = { 190 - 202 + cx, 204 - 162 + cy, 212 - 202 + cx, 208 - 162 + cy };
    FillRect(hdc, &rect260, hBrush12);
    RECT rect261 = { 192 - 202 + cx, 202 - 162 + cy, 198 - 202 + cx, 204 - 162 + cy };
    FillRect(hdc, &rect261, hBrush12);
    RECT rect262 = { 188 - 202 + cx, 204 - 162 + cy, 190 - 202 + cx, 206 - 162 + cy };
    FillRect(hdc, &rect262, hBrush12);
    RECT rect263 = { 200 - 202 + cx, 208 - 162 + cy, 210 - 202 + cx, 210 - 162 + cy };
    FillRect(hdc, &rect263, hBrush12);
    RECT rect264 = { 214 - 202 + cx, 198 - 162 + cy, 222 - 202 + cx, 202 - 162 + cy };
    FillRect(hdc, &rect264, hBrush12);
    RECT rect265 = { 216 - 202 + cx, 202 - 162 + cy, 230 - 202 + cx, 206 - 162 + cy };
    FillRect(hdc, &rect265, hBrush12);
    RECT rect266 = { 230 - 202 + cx, 204 - 162 + cy, 234 - 202 + cx, 206 - 162 + cy };
    FillRect(hdc, &rect266, hBrush12);
    RECT rect267 = { 218 - 202 + cx, 206 - 162 + cy, 230 - 202 + cx, 208 - 162 + cy };
    FillRect(hdc, &rect267, hBrush12);
    RECT rect268 = { 230 - 202 + cx, 206 - 162 + cy, 232 - 202 + cx, 208 - 162 + cy };
    RECT rect276 = { 204 - 202 + cx, 180 - 162 + cy, 206 - 202 + cx, 182 - 162 + cy };
    FillRect(hdc, &rect276, hBrush12);

    FillRect(hdc, &rect268, hBrush);
    RECT rect269 = { 218 - 202 + cx, 208 - 162 + cy, 230 - 202 + cx, 210 - 162 + cy };
    FillRect(hdc, &rect269, hBrush);
    RECT rect270 = { 216 - 202 + cx, 206 - 162 + cy, 218 - 202 + cx, 208 - 162 + cy };
    FillRect(hdc, &rect270, hBrush);
    RECT rect271 = { 216 - 202 + cx, 206 - 162 + cy, 218 - 202 + cx, 208 - 162 + cy };
    FillRect(hdc, &rect271, hBrush);

    RECT rect272 = { 210 - 202 + cx, 208 - 162 + cy, 212 - 202 + cx, 210 - 162 + cy };
    FillRect(hdc, &rect272, hBrush);
    RECT rect273 = { 200 - 202 + cx, 210 - 162 + cy, 210 - 202 + cx, 212 - 162 + cy };
    FillRect(hdc, &rect273, hBrush);
    RECT rect274 = { 192 - 202 + cx, 208 - 162 + cy, 200 - 202 + cx, 210 - 162 + cy };
    FillRect(hdc, &rect274, hBrush);
    RECT rect275 = { 190 - 202 + cx, 206 - 162 + cy, 192 - 202 + cx, 208 - 162 + cy };
    FillRect(hdc, &rect275, hBrush);

    RECT rect277 = { 216 - 202 + cx, 164 - 162 + cy, 220 - 202 + cx, 172 - 162 + cy }; //ХВОСТ
    FillRect(hdc, &rect277, hBrush12);
    RECT rect278 = { 218 - 202 + cx, 162 - 162 + cy, 220 - 202 + cx, 164 - 162 + cy }; //
    FillRect(hdc, &rect278, hBrush12);
    RECT rect279 = { 220 - 202 + cx, 160 - 162 + cy, 226 - 202 + cx, 170 - 162 + cy }; //
    FillRect(hdc, &rect279, hBrush12);
    RECT rect280 = { 220 - 202 + cx, 170 - 162 + cy, 222 - 202 + cx, 172 - 162 + cy };
    FillRect(hdc, &rect280, hBrush);
    RECT rect281 = { 224 - 202 + cx, 168 - 162 + cy, 226 - 202 + cx, 170 - 162 + cy };
    FillRect(hdc, &rect281, hBrush);
    RECT rect282 = { 226 - 202 + cx, 166 - 162 + cy, 228 - 202 + cx, 168 - 162 + cy };
    FillRect(hdc, &rect282, hBrush);
    RECT rect283 = { 226 - 202 + cx, 162 - 162 + cy, 228 - 202 + cx, 164 - 162 + cy };
    FillRect(hdc, &rect283, hBrush);
    RECT rect284 = { 226 - 202 + cx, 164 - 162 + cy, 228 - 202 + cx, 166 - 162 + cy };
    FillRect(hdc, &rect284, hBrush12);
    RECT rect285 = { 226 - 202 + cx, 160 - 162 + cy, 228 - 202 + cx, 162 - 162 + cy };
    FillRect(hdc, &rect285, hBrush12);
    RECT rect286 = { 224 - 202 + cx, 158 - 162 + cy, 226 - 202 + cx, 160 - 162 + cy };
    FillRect(hdc, &rect286, hBrush12);

    DeleteObject(hBrush);
    DeleteObject(hBrush2);
    DeleteObject(hBrush3);
    DeleteObject(hBrush4);
    DeleteObject(hBrush5);
    DeleteObject(hBrush6);
    DeleteObject(hBrush7);
    DeleteObject(hBrush8);
    DeleteObject(hBrush9);
    DeleteObject(hBrush10);
    DeleteObject(hBrush11);
    DeleteObject(hBrush12);
#ifdef DEBUG_GAME
    // Зона захвата 
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 20, cy - 20, cx + 20, cy + 20);

    MoveToEx(hdc, cx - 40, cy, NULL);
    LineTo(hdc, cx + 40, cy);
    MoveToEx(hdc, cx, cy - 40, NULL);
    LineTo(hdc, cx, cy + 40);

    DeleteObject(hPenZone);
#endif

}
void volk(HDC hdc, int cx, int cy) {
    HBRUSH hBrush;
    HBRUSH hBrush2;
    HBRUSH hBrush3;
    HBRUSH hBrush4;
    HBRUSH hBrush5;
    HBRUSH hBrush6;
    HBRUSH hBrush7;
    HBRUSH hBrush8;
    HBRUSH hBrush9;
    HBRUSH hBrush10;
    HBRUSH hBrush11;
    HBRUSH hBrush12;
    hBrush = CreateSolidBrush(RGB(30, 30, 30)); //black
    hBrush2 = CreateSolidBrush(RGB(255, 0, 0)); //red
    hBrush3 = CreateSolidBrush(RGB(99, 0, 42)); //red2
    hBrush4 = CreateSolidBrush(RGB(173, 173, 173)); //Lgray
    hBrush5 = CreateSolidBrush(RGB(128, 128, 128)); //gray
    hBrush6 = CreateSolidBrush(RGB(255, 255, 255)); //White
    hBrush7 = CreateSolidBrush(RGB(255, 205, 0)); //Yellow
    hBrush8 = CreateSolidBrush(RGB(169, 169, 169)); //White2
    hBrush9 = CreateSolidBrush(RGB(0, 128, 0)); //Green2
    hBrush10 = CreateSolidBrush(RGB(0, 180, 0)); //Green
    hBrush11 = CreateSolidBrush(RGB(0, 0, 255)); //Green
    hBrush12 = CreateSolidBrush(RGB(205, 133, 63)); //
    //240

    RECT rect400 = { 300 - 340 + cx, 100 - 162 + cy, 306 - 340 + cx, 102 - 162 + cy };
    FillRect(hdc, &rect400, hBrush);
    RECT rect401 = { 298 - 340 + cx, 102 - 162 + cy, 308 - 340 + cx, 110 - 162 + cy };
    FillRect(hdc, &rect401, hBrush);
    RECT rect402 = { 300 - 340 + cx, 110 - 162 + cy, 306 - 340 + cx, 112 - 162 + cy };
    FillRect(hdc, &rect402, hBrush);
    RECT rect403 = { 296 - 340 + cx, 112 - 162 + cy, 330 - 340 + cx, 120 - 162 + cy };
    FillRect(hdc, &rect403, hBrush5);
    RECT rect404 = { 298 - 340 + cx, 120 - 162 + cy, 318 - 340 + cx, 124 - 162 + cy };
    FillRect(hdc, &rect404, hBrush5);
    RECT rect405 = { 300 - 340 + cx, 124 - 162 + cy, 316 - 340 + cx, 126 - 162 + cy };
    FillRect(hdc, &rect405, hBrush5);
    RECT rect406 = { 302 - 340 + cx, 126 - 162 + cy, 306 - 340 + cx, 128 - 162 + cy };
    FillRect(hdc, &rect406, hBrush5);
    RECT rect407 = { 304 - 340 + cx, 128 - 162 + cy, 306 - 340 + cx, 130 - 162 + cy };
    FillRect(hdc, &rect407, hBrush5);
    RECT rect408 = { 310 - 340 + cx, 126 - 162 + cy, 320 - 340 + cx, 128 - 162 + cy };
    FillRect(hdc, &rect408, hBrush);
    RECT rect409 = { 312 - 340 + cx, 128 - 162 + cy, 320 - 340 + cx, 130 - 162 + cy };
    FillRect(hdc, &rect409, hBrush);
    RECT rect410 = { 308 - 340 + cx, 128 - 162 + cy, 312 - 340 + cx, 130 - 162 + cy };
    FillRect(hdc, &rect410, hBrush5);
    RECT rect411 = { 306 - 340 + cx, 130 - 162 + cy, 330 - 340 + cx, 134 - 162 + cy };
    FillRect(hdc, &rect411, hBrush5);
    RECT rect412 = { 308 - 340 + cx, 134 - 162 + cy, 330 - 340 + cx, 136 - 162 + cy };
    FillRect(hdc, &rect412, hBrush5);
    RECT rect413 = { 320 - 340 + cx, 110 - 162 + cy, 330 - 340 + cx, 136 - 162 + cy };
    FillRect(hdc, &rect413, hBrush5);
    RECT rect414 = { 324 - 340 + cx, 108 - 162 + cy, 350 - 340 + cx, 136 - 162 + cy };
    FillRect(hdc, &rect414, hBrush5);
    RECT rect415 = { 330 - 340 + cx, 100 - 162 + cy, 346 - 340 + cx, 136 - 162 + cy };
    FillRect(hdc, &rect415, hBrush5);

    RECT rect416 = { 328 - 340 + cx, 102 - 162 + cy, 332 - 340 + cx, 108 - 162 + cy };
    FillRect(hdc, &rect416, hBrush);
    RECT rect417 = { 332 - 340 + cx, 102 - 162 + cy, 334 - 340 + cx, 108 - 162 + cy };
    FillRect(hdc, &rect417, hBrush6);

    RECT rect418 = { 336 - 340 + cx, 102 - 162 + cy, 340 - 340 + cx, 108 - 162 + cy };
    FillRect(hdc, &rect418, hBrush);
    RECT rect419 = { 340 - 340 + cx, 102 - 162 + cy, 342 - 340 + cx, 108 - 162 + cy };
    FillRect(hdc, &rect419, hBrush6);

    RECT rect420 = { 338 - 340 + cx, 110 - 162 + cy, 356 - 340 + cx, 130 - 162 + cy };
    FillRect(hdc, &rect420, hBrush5);
    RECT rect421 = { 346 - 340 + cx, 102 - 162 + cy, 354 - 340 + cx, 134 - 162 + cy };
    FillRect(hdc, &rect421, hBrush5);
    RECT rect422 = { 336 - 340 + cx, 136 - 162 + cy, 346 - 340 + cx, 138 - 162 + cy };
    FillRect(hdc, &rect422, hBrush5);
    RECT rect423 = { 338 - 340 + cx, 138 - 162 + cy, 344 - 340 + cx, 140 - 162 + cy };
    FillRect(hdc, &rect423, hBrush5);
    RECT rect424 = { 330 - 340 + cx, 140 - 162 + cy, 350 - 340 + cx, 180 - 162 + cy };
    FillRect(hdc, &rect424, hBrush5);
    RECT rect425 = { 328 - 340 + cx, 144 - 162 + cy, 352 - 340 + cx, 176 - 162 + cy };
    FillRect(hdc, &rect425, hBrush5);
    RECT rect426 = { 326 - 340 + cx, 148 - 162 + cy, 354 - 340 + cx, 172 - 162 + cy };
    FillRect(hdc, &rect426, hBrush5);
    RECT rect427 = { 324 - 340 + cx, 152 - 162 + cy, 356 - 340 + cx, 176 - 162 + cy };
    FillRect(hdc, &rect427, hBrush5);
    RECT rect428 = { 322 - 340 + cx, 156 - 162 + cy, 358 - 340 + cx, 168 - 162 + cy };
    FillRect(hdc, &rect428, hBrush5);

    RECT rect429 = { 330 - 340 + cx, 180 - 162 + cy, 338 - 340 + cx, 200 - 162 + cy };
    FillRect(hdc, &rect429, hBrush5);
    RECT rect430 = { 342 - 340 + cx, 180 - 162 + cy, 350 - 340 + cx, 200 - 162 + cy };
    FillRect(hdc, &rect430, hBrush5);

    RECT rect431 = { 316 - 340 + cx, 200 - 162 + cy, 338 - 340 + cx, 208 - 162 + cy };
    FillRect(hdc, &rect431, hBrush4);
    RECT rect446 = { 314 - 340 + cx, 200 - 162 + cy, 318 - 340 + cx, 202 - 162 + cy };
    FillRect(hdc, &rect446, hBrush);
    RECT rect447 = { 314 - 340 + cx, 204 - 162 + cy, 318 - 340 + cx, 206 - 162 + cy };
    FillRect(hdc, &rect447, hBrush);
    RECT rect432 = { 318 - 340 + cx, 208 - 162 + cy, 338 - 340 + cx, 210 - 162 + cy };
    FillRect(hdc, &rect432, hBrush5);

    RECT rect433 = { 342 - 340 + cx, 200 - 162 + cy, 364 - 340 + cx, 208 - 162 + cy };
    FillRect(hdc, &rect433, hBrush4);
    RECT rect444 = { 362 - 340 + cx, 200 - 162 + cy, 366 - 340 + cx, 202 - 162 + cy };
    FillRect(hdc, &rect444, hBrush);
    RECT rect445 = { 362 - 340 + cx, 204 - 162 + cy, 366 - 340 + cx, 206 - 162 + cy };
    FillRect(hdc, &rect445, hBrush);
    RECT rect434 = { 342 - 340 + cx, 208 - 162 + cy, 362 - 340 + cx, 210 - 162 + cy };
    FillRect(hdc, &rect434, hBrush5);

    RECT rect435 = { 320 - 340 + cx, 144 - 162 + cy, 360 - 340 + cx, 150 - 162 + cy };
    FillRect(hdc, &rect435, hBrush5);
    RECT rect436 = { 316 - 340 + cx, 144 - 162 + cy, 320 - 340 + cx, 164 - 162 + cy };
    FillRect(hdc, &rect436, hBrush5);
    RECT rect443 = { 318 - 340 + cx, 144 - 162 + cy, 324 - 340 + cx, 152 - 162 + cy };
    FillRect(hdc, &rect443, hBrush5);
    RECT rect437 = { 314 - 340 + cx, 146 - 162 + cy, 320 - 340 + cx, 164 - 162 + cy };
    FillRect(hdc, &rect437, hBrush5);
    RECT rect438 = { 310 - 340 + cx, 164 - 162 + cy, 320 - 340 + cx, 174 - 162 + cy };
    FillRect(hdc, &rect438, hBrush4);
    RECT rect439 = { 312 - 340 + cx, 174 - 162 + cy, 320 - 340 + cx, 176 - 162 + cy };
    FillRect(hdc, &rect439, hBrush4);
    RECT rect440 = { 308 - 340 + cx, 172 - 162 + cy, 312 - 340 + cx, 174 - 162 + cy };
    FillRect(hdc, &rect440, hBrush);
    RECT rect441 = { 308 - 340 + cx, 168 - 162 + cy, 312 - 340 + cx, 170 - 162 + cy };
    FillRect(hdc, &rect441, hBrush);
    RECT rect442 = { 308 - 340 + cx, 164 - 162 + cy, 312 - 340 + cx, 166 - 162 + cy };
    FillRect(hdc, &rect442, hBrush);

    RECT rect450 = { 358 - 340 + cx, 144 - 162 + cy, 366 - 340 + cx, 152 - 162 + cy };
    FillRect(hdc, &rect450, hBrush5);
    RECT rect451 = { 360 - 340 + cx, 146 - 162 + cy, 366 - 340 + cx, 164 - 162 + cy };
    FillRect(hdc, &rect451, hBrush5);
    RECT rect452 = { 360 - 340 + cx, 164 - 162 + cy, 368 - 340 + cx, 176 - 162 + cy };
    FillRect(hdc, &rect452, hBrush4);
    RECT rect453 = { 366 - 340 + cx, 172 - 162 + cy, 370 - 340 + cx, 174 - 162 + cy };
    FillRect(hdc, &rect453, hBrush);
    RECT rect454 = { 366 - 340 + cx, 168 - 162 + cy, 370 - 340 + cx, 170 - 162 + cy };
    FillRect(hdc, &rect454, hBrush);
    RECT rect455 = { 366 - 340 + cx, 164 - 162 + cy, 370 - 340 + cx, 166 - 162 + cy };
    FillRect(hdc, &rect455, hBrush);
    RECT rect456 = { 330 - 340 + cx, 98 - 162 + cy, 360 - 340 + cx, 100 - 162 + cy };
    FillRect(hdc, &rect456, hBrush);
    RECT rect457 = { 332 - 340 + cx, 94 - 162 + cy, 356 - 340 + cx, 100 - 162 + cy };
    FillRect(hdc, &rect457, hBrush);
    RECT rect458 = { 346 - 340 + cx, 94 - 162 + cy, 358 - 340 + cx, 108 - 162 + cy };
    FillRect(hdc, &rect458, hBrush);
    RECT rect459 = { 356 - 340 + cx, 106 - 162 + cy, 360 - 340 + cx, 108 - 162 + cy };
    FillRect(hdc, &rect459, hBrush);
    RECT rect460 = { 334 - 340 + cx, 92 - 162 + cy, 336 - 340 + cx, 100 - 162 + cy };
    FillRect(hdc, &rect460, hBrush);
    RECT rect461 = { 338 - 340 + cx, 90 - 162 + cy, 340 - 340 + cx, 100 - 162 + cy };
    FillRect(hdc, &rect461, hBrush);
    RECT rect462 = { 342 - 340 + cx, 89 - 162 + cy, 344 - 340 + cx, 100 - 162 + cy };
    FillRect(hdc, &rect462, hBrush);
    RECT rect463 = { 342 - 340 + cx, 89 - 162 + cy, 350 - 340 + cx, 100 - 162 + cy };
    FillRect(hdc, &rect463, hBrush);
    RECT rect464 = { 342 - 340 + cx, 91 - 162 + cy, 356 - 340 + cx, 100 - 162 + cy };
    FillRect(hdc, &rect464, hBrush);


    DeleteObject(hBrush);
    DeleteObject(hBrush2);
    DeleteObject(hBrush3);
    DeleteObject(hBrush4);
    DeleteObject(hBrush5);
    DeleteObject(hBrush6);
    DeleteObject(hBrush7);
    DeleteObject(hBrush8);
    DeleteObject(hBrush9);
    DeleteObject(hBrush10);
    DeleteObject(hBrush11);
    DeleteObject(hBrush12);
#ifdef DEBUG_GAME
    // Зона захвата 
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 20, cy - 20, cx + 20, cy + 20);

    MoveToEx(hdc, cx - 40, cy, NULL);
    LineTo(hdc, cx + 40, cy);
    MoveToEx(hdc, cx, cy - 40, NULL);
    LineTo(hdc, cx, cy + 40);

    DeleteObject(hPenZone);
#endif

} //done
void money(HDC hdc, int cx, int cy) {
    HBRUSH hBrush;
    HBRUSH hBrush2;
    HBRUSH hBrush3;
    HBRUSH hBrush4;
    HBRUSH hBrush5;

    hBrush = CreateSolidBrush(RGB(0, 0, 0)); //black
    hBrush2 = CreateSolidBrush(RGB(255, 0, 0)); //red
    hBrush3 = CreateSolidBrush(RGB(255, 230, 0)); //yellow
    hBrush4 = CreateSolidBrush(RGB(255, 230, 240)); //lyellow
    hBrush5 = CreateSolidBrush(RGB(175, 150, 0)); //byelllow
    RECT rect1 = { 100 - 106 + cx, 100 - 124 + cy, 112 - 106 + cx, 103 - 124 + cy };
    FillRect(hdc, &rect1, hBrush);
    RECT rect2 = { 94 - 106 + cx, 103 - 124 + cy, 100 - 106 + cx, 106 - 124 + cy };
    FillRect(hdc, &rect2, hBrush);
    RECT rect3 = { 112 - 106 + cx, 103 - 124 + cy, 118 - 106 + cx, 106 - 124 + cy };
    FillRect(hdc, &rect3, hBrush);
    RECT rect4 = { 118 - 106 + cx, 106 - 124 + cy, 121 - 106 + cx, 112 - 124 + cy };
    FillRect(hdc, &rect4, hBrush);
    RECT rect5 = { 91 - 106 + cx, 106 - 124 + cy, 94 - 106 + cx, 112 - 124 + cy };
    FillRect(hdc, &rect5, hBrush);
    RECT rect6 = { 91 - 106 + cx, 112 - 124 + cy, 88 - 106 + cx, 136 - 124 + cy };
    FillRect(hdc, &rect6, hBrush);
    RECT rect7 = { 121 - 106 + cx, 112 - 124 + cy, 124 - 106 + cx, 136 - 124 + cy };
    FillRect(hdc, &rect7, hBrush);
    RECT rect8 = { 118 - 106 + cx, 136 - 124 + cy, 121 - 106 + cx, 142 - 124 + cy };
    FillRect(hdc, &rect8, hBrush);
    RECT rect9 = { 91 - 106 + cx, 136 - 124 + cy, 94 - 106 + cx, 142 - 124 + cy };
    FillRect(hdc, &rect9, hBrush);
    RECT rect10 = { 94 - 106 + cx, 142 - 124 + cy, 100 - 106 + cx, 145 - 124 + cy };
    FillRect(hdc, &rect10, hBrush);
    RECT rect11 = { 100 - 106 + cx, 145 - 124 + cy, 112 - 106 + cx, 148 - 124 + cy };
    FillRect(hdc, &rect11, hBrush);
    RECT rect12 = { 112 - 106 + cx, 142 - 124 + cy, 118 - 106 + cx, 145 - 124 + cy };
    FillRect(hdc, &rect12, hBrush);
    RECT rect13 = { 100 - 106 + cx, 103 - 124 + cy, 112 - 106 + cx, 145 - 124 + cy };
    FillRect(hdc, &rect13, hBrush3);
    RECT rect14 = { 94 - 106 + cx, 106 - 124 + cy, 100 - 106 + cx, 142 - 124 + cy };
    FillRect(hdc, &rect14, hBrush3);
    RECT rect15 = { 94 - 106 + cx, 106 - 124 + cy, 118 - 106 + cx, 142 - 124 + cy };
    FillRect(hdc, &rect15, hBrush3);
    RECT rect16 = { 91 - 106 + cx, 112 - 124 + cy, 121 - 106 + cx, 136 - 124 + cy };
    FillRect(hdc, &rect16, hBrush3);

    RECT rect17 = { 109 - 106 + cx, 112 - 124 + cy, 112 - 106 + cx, 136 - 124 + cy }; //середина
    FillRect(hdc, &rect17, hBrush);
    RECT rect18 = { 103 - 106 + cx, 136 - 124 + cy, 109 - 106 + cx, 139 - 124 + cy };
    FillRect(hdc, &rect18, hBrush);

    RECT rect19 = { 100 - 106 + cx, 112 - 124 + cy, 103 - 106 + cx, 136 - 124 + cy }; //ЛЕво
    FillRect(hdc, &rect19, hBrush4);
    RECT rect20 = { 103 - 106 + cx, 109 - 124 + cy, 109 - 106 + cx, 112 - 124 + cy };
    FillRect(hdc, &rect20, hBrush4);
    RECT rect21 = { 94 - 106 + cx, 106 - 124 + cy, 100 - 106 + cx, 109 - 124 + cy };
    FillRect(hdc, &rect21, hBrush4);
    RECT rect22 = { 94 - 106 + cx, 106 - 124 + cy, 97 - 106 + cx, 112 - 124 + cy };
    FillRect(hdc, &rect22, hBrush4);
    RECT rect23 = { 91 - 106 + cx, 112 - 124 + cy, 94 - 106 + cx, 136 - 124 + cy };
    FillRect(hdc, &rect23, hBrush4);
    RECT rect24 = { 94 - 106 + cx, 133 - 124 + cy, 97 - 106 + cx, 142 - 124 + cy };
    FillRect(hdc, &rect24, hBrush4);
    RECT rect25 = { 100 - 106 + cx, 103 - 124 + cy, 112 - 106 + cx, 106 - 124 + cy };
    FillRect(hdc, &rect25, hBrush4);

    RECT rect26 = { 100 - 106 + cx, 142 - 124 + cy, 112 - 106 + cx, 145 - 124 + cy }; //ЧЖ
    FillRect(hdc, &rect26, hBrush5);
    RECT rect27 = { 112 - 106 + cx, 139 - 124 + cy, 118 - 106 + cx, 142 - 124 + cy };
    FillRect(hdc, &rect27, hBrush5);
    RECT rect28 = { 115 - 106 + cx, 136 - 124 + cy, 118 - 106 + cx, 139 - 124 + cy };
    FillRect(hdc, &rect28, hBrush5);

    RECT rect29 = { 118 - 106 + cx, 112 - 124 + cy, 121 - 106 + cx, 136 - 124 + cy };
    FillRect(hdc, &rect29, hBrush5);
    RECT rect30 = { 115 - 106 + cx, 106 - 124 + cy, 118 - 106 + cx, 112 - 124 + cy };
    FillRect(hdc, &rect30, hBrush5);


    DeleteObject(hBrush);
    DeleteObject(hBrush2);
    DeleteObject(hBrush3);
    DeleteObject(hBrush4);
    DeleteObject(hBrush5);

#ifdef DEBUG_GAME
    // Зона захвата 
    HPEN hPenZone = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    SelectObject(hdc, hPenZone);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, cx - 20, cy - 20, cx + 20, cy + 20);

    MoveToEx(hdc, cx - 40, cy, NULL);
    LineTo(hdc, cx + 40, cy);
    MoveToEx(hdc, cx, cy - 40, NULL);
    LineTo(hdc, cx, cy + 40);

    DeleteObject(hPenZone);
#endif


    SelectObject(hdc, hBrush);
} //done

typedef struct Robotd {
    int X;
    int Y;
    int Vision;
}ROBOTD;

ROBOTD Robotd = { 900, 500 , 0 };

typedef struct zaycd {
    int X;
    int Y;
    int Helth;
    int number_of_money; //0
    int Vision;
} ZAYCD;

ZAYCD zaycd = { 1700, 200, 3, 0, 1 };

typedef struct monetka {
    int X;
    int Y;
    int Vision;
}MONETKA;

MONETKA monetka[3] = {
 { 200, 330 , 1 },
 { 660, 100, 1 },
 { 880, 700, 1 },
};

typedef struct volkd {
    int X;
    int Y;

    int Helth;
    int Vision;
} VOLKD;
VOLKD volkd = { 100, 400, 1, 1 };



enum Modes {
    Start,
    Game,
    Win,
    Loss,
    Final
};



enum Modes mode = Start;
int l = 0;

void TryToEatMoney() {
    for (int l = 0; l < 3; l++) {
        if (monetka[l].Vision) {
            if (zaycd.X - 20 < monetka[l].X
                && zaycd.X + 20 > monetka[l].X
                && zaycd.Y - 20 < monetka[l].Y
                && zaycd.Y + 20 > monetka[l].Y
                ) {
                monetka[l].Vision = 0;
                zaycd.number_of_money++;
            }
        }
    }
}
void DrawStatus(HDC hdc) {
    HFONT hFont = CreateFont(16, 0, 0, 0, 0, 0, 0, 0,
        DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");

    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(200, 0, 0));

    char str[180];
    sprintf_s(str, "Number of coins = %d",
        zaycd.number_of_money);

    TCHAR  strT[180];
    OemToCharBuff(str, strT, 180);
    TextOut(hdc, 0, 0, (LPCWSTR)strT, _tcslen(strT));

    DeleteObject(hFont);
}
void BG(HDC hdc) {

    HBRUSH hBrushbackgraund = CreateSolidBrush(RGB(47, 79, 79));
    SelectObject(hdc, hBrushbackgraund);
    Rectangle(hdc, -1, -1, 2000, 1000);
}
void ST(HDC hdc) {
    HFONT hFont = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(128, 0, 128));
    TCHAR strT[180] = L"by: spfDRN";
    TextOut(hdc, 900, 100, (LPCWSTR)strT, _tcslen(strT));
    DeleteObject(hFont);
}
void ST1(HDC hdc) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(128, 0, 128));
    TCHAR strT[180] = L"Ну,погоди!";
    TextOut(hdc, 870, 120, (LPCWSTR)strT, _tcslen(strT));
    DeleteObject(hFont);
}
void WT(HDC hdc) {
    HFONT hFont = CreateFont(60, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(128, 0, 128));
    TCHAR strT[180] = L"Заяц победил!";
    TextOut(hdc, 750, 250, (LPCWSTR)strT, _tcslen(strT));
    DeleteObject(hFont);
}
void LT(HDC hdc) {
    HFONT hFont = CreateFont(60, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(128, 0, 128));
    TCHAR strT[180] = L"Волк победил!";
    TextOut(hdc, 750, 250, (LPCWSTR)strT, _tcslen(strT));
    DeleteObject(hFont);
}
void TT(HDC hdc) {
    HFONT hFont = CreateFont(60, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(128, 0, 128));
    TCHAR strT[180] = L"Спасибо за игру <3";
    TextOut(hdc, 700, 250, (LPCWSTR)strT, _tcslen(strT));
    DeleteObject(hFont);
}
void DrawStart(HDC hdc) {
    ST(hdc);
    ST1(hdc);
    Robot(hdc, 900, 505);
    zayc(hdc, 770, 502);
    money(hdc, 830, 505);
    volk(hdc, 1000, 500);
}
void DrawWin(HDC hdc) {
    WT(hdc);
    money(hdc, 770, 505);
    Robot(hdc, 870, 505);
    zayc(hdc, 970, 505);
    Robot(hdc, 1070, 505);
    money(hdc, 1160, 505);
}
void DrawGame(HDC hdc) {
    if (zaycd.Helth > 0) {
        zayc(hdc, zaycd.X, zaycd.Y);
    }
    for (int l = 0; l < 3; l++) {
        if (monetka[l].Vision > 0) {
            money(hdc, monetka[l].X, monetka[l].Y);
        }
    }
    if (Robotd.Vision > 0) {
        Robot(hdc, Robotd.X, Robotd.Y);
    }
    if ((volkd.Vision > 0) && (volkd.Helth > 0)) {
        volk(hdc, volkd.X, volkd.Y);
    }
    DrawStatus(hdc);

}
void DrawLoss(HDC hdc) {
    LT(hdc);

    money(hdc, 770, 505);
    money(hdc, 870, 505);
    volk(hdc, 970, 505);
    money(hdc, 1070, 505);
    money(hdc, 1160, 505);
}
void DrawFinal(HDC hdc) {
    TT(hdc);
    money(hdc, 770, 505);
    money(hdc, 870, 505);
    money(hdc, 970, 505);
    money(hdc, 1070, 505);
    money(hdc, 1160, 505);
}
void GoD() {
    int dx = 0, dy = 0;
    if (volkd.Vision && !Robotd.Vision) {
        if (zaycd.X > volkd.X)
            dx = 10;
        if (zaycd.X < volkd.X)
            dx = -10;
        if (zaycd.Y > volkd.Y)
            dy = 10;
        if (zaycd.Y < volkd.Y)
            dy = -10;
        volkd.X += dx;
        volkd.Y += dy;
    }
}
void GoD1() {
    int dx = 0, dy = 0;
    if (Robotd.Vision) {
        if (volkd.X > Robotd.X)
            dx = 15;
        if (volkd.X < Robotd.X)
            dx = -15;
        if (volkd.Y > Robotd.Y)
            dy = 15;
        if (volkd.Y < Robotd.Y)
            dy = -15;
        Robotd.X += dx;
        Robotd.Y += dy;
        int dx1 = 0, dy1 = 0;
        if (Robotd.X > volkd.X) {
            if (WinRect.left + 10 <= volkd.X)
                dx1 = -10;
        }
        if (Robotd.X < volkd.X) {
            if (WinRect.right - 10 >= volkd.X)
                dx1 = 10;
        }
        if (Robotd.Y > volkd.Y) {
            if (WinRect.top + 10 <= volkd.Y)
                dy1 = -10;
        }
        if (Robotd.Y < volkd.Y) {
            if (WinRect.bottom - 10 >= volkd.Y)
                dy1 = 10;
        }

        volkd.X += dx1;
        volkd.Y += dy1;
    }

}
void CZaycAndVolk() {
    if ((volkd.Vision) && (volkd.Helth > 0)) {
        if (zaycd.X - 20 < volkd.X
            && zaycd.X + 20 > volkd.X
            && zaycd.Y - 20 < volkd.Y
            && zaycd.Y + 20 > volkd.Y) {
            zaycd.Helth--;
        }
    }
}
void CVolkAndRobot() {
    if (volkd.Vision) {
        if (Robotd.Vision) {
            if (Robotd.X - 20 < volkd.X
                && Robotd.X + 20 > volkd.X
                && Robotd.Y - 20 < volkd.Y
                && Robotd.Y + 20 > volkd.Y) {
                volkd.Vision = 0;
            }
        }
    }
}

void SaveGame() {
    FILE *fout;
    fopen_s(&fout, "Save.txt", "wt");
    if (fout == NULL) {
        return;
    }
    //zayc
    fprintf(fout, "%d %d %d %d %d\n", zaycd.X, zaycd.Y, zaycd.Helth, zaycd.number_of_money, zaycd.Vision);
    //volk
    fprintf(fout, "%d %d %d %d\n", volkd.X, volkd.Y, volkd.Helth, volkd.Vision);
    //money
    for (int l = 0; l < 3; l++) {
        fprintf(fout, "%d %d %d\n", monetka[l].X, monetka[l].Y, monetka[l].Vision);
    }
    //robot
    fprintf(fout, "%d %d %d\n", Robotd.X, Robotd.Y, Robotd.Vision);

    fprintf(fout, "\n\n");

    fclose(fout);


}
void LoadGame() {
    FILE *fin;
    fopen_s(&fin, "Save.txt", "rt");
    if (fin == NULL) {
        return;
    }

    //zayc
    fscanf_s(fin, "%d %d %d %d %d", &zaycd.X, &zaycd.Y, &zaycd.Helth, &zaycd.number_of_money, &zaycd.Vision);
    //volk
    fscanf_s(fin, "%d %d %d %d", &volkd.X, &volkd.Y, &volkd.Helth, &volkd.Vision);
    //mony
    for (int i = 0; i < 3; i++) {
        fscanf_s(fin, "%d %d %d", &monetka[i].X, &monetka[i].Y, &monetka[i].Vision);
    }
    //robot
    fscanf_s(fin, "%d %d %d", &Robotd.X, &Robotd.Y, &Robotd.Vision);

    fscanf_s(fin, "\n\n");


    fclose(fin);
}




LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
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

    case WM_CREATE:
        SetTimer(hWnd, 1, 100, 0);
        break;

    case WM_TIMER:
        if (mode == Game) {
            GoD1();
            GoD();
            CVolkAndRobot();
            CZaycAndVolk();
            if (volkd.Vision == 0) {
                mode = Win;
            }
            if (zaycd.Helth == 0) {
                mode = Loss;
            }
            InvalidateRect(hWnd, NULL, TRUE);
        }

        if ((mode == Win) || (mode == Loss)) {
            step++;
            if (step > 30)
                mode = Final;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;

    case WM_KEYDOWN:
        CZaycAndVolk();
        CVolkAndRobot();
        TryToEatMoney();
        if (mode == Start) {
            mode = Game;
        }
        if (zaycd.Helth == 0) {
            mode = Loss;
        }
        if (volkd.Vision == 0) {
            mode = Win;
        }
        
        switch (wParam) {

        case 0x57:
            if (WinRect.top <= zaycd.Y)
                zaycd.Y -= 10;
            break;

        case 	0x53: // or 's'
            if (zaycd.Y <= WinRect.bottom)
                zaycd.Y += 10;
            break;

        case 0x44: // or 'd'
            if (zaycd.X <= WinRect.right)
                zaycd.X += 10;
            break;

        case 0x41:// or 'a'
            if (WinRect.left <= zaycd.X)
                zaycd.X -= 10;
            break;

        case 0x49: //SaveGame/I
            SaveGame();
            break;

        case  0x4F: //LoadGame/O
            LoadGame();    
            break;

        case VK_SPACE:
            if (zaycd.number_of_money == 3) {
                Robotd = { zaycd.X + 50,zaycd.Y, 1 };
                zaycd.number_of_money -= 3;
            }
        }

    case WM_PAINT:
        {
        GetClientRect(hWnd, &WinRect);
        int i = 0;
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        BG(hdc); // фон

        if (mode == Game)
            DrawGame(hdc);
        if (mode == Start)
            DrawStart(hdc);
        if (mode == Win)
            DrawWin(hdc);
        if (mode == Loss)
            DrawLoss(hdc);
        if (mode == Final)
            DrawFinal(hdc);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
