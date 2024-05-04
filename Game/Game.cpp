// Game.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "Game.h"
#include "windows.h"
#include <Windows.h>
#include <stdio.h>
#include "DrawModels.cpp"
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
short step = 0;
short raz = 1;
short max = 500, min = 10;
short maxy = 1400, miny = -10;
short SizeX = 384 / 2, SizeY = 216;
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
}OBJECT;

OBJECT monetka[3] = {
    { 900 + SizeX ,200 + 216,1},
    { 200 + SizeX, 700 + 216,1},
    { 1100 + SizeX, 500 + 216,1}
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
    TextOut(hdc, 900, 450, (LPCWSTR)strT, _tcslen(strT));
    DeleteObject(hFont);
}
void ST1(HDC hdc) {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HFONT hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, L"Courier New");
    SelectObject(hdc, hFont);
    SetTextColor(hdc, RGB(128, 0, 128));
    TCHAR strT[180] = L"Ну,погоди!";
    TextOut(hdc, 870, 470, (LPCWSTR)strT, _tcslen(strT));
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
    TextOut(hdc, 680, 250, (LPCWSTR)strT, _tcslen(strT));
    DeleteObject(hFont);
}

//start
struct Image { int cx; int cy; int vx; int vy; };
struct Image imZayc = { -10 ,800,10,0 };
struct Image imVolk = { -60 ,800,10,0 };
struct Image imRobot = { 1500,1220,0,0 };
//Win
struct Image imZaycW = { 970 ,505, 0, -5 };
struct Image imMonetkaW = { -100 ,505, 10, 0 };
struct Image imMonetkaW2 = { 2045 ,505, -10, 0 };
struct Image imRobotW = { -30, 505, 10, 0 };
struct Image imRobotW2 = { 1975, 505, -10, 0 };
//Loss
struct Image imZaycL = { 970, 600, 0, 0 };
struct Image imVolkL = { 970, 750, 10, 0 };
//final
struct Image imMonetkaF = { -50, 505, 10, 0 }; //770 
struct Image imMonetkaF2 = { 0, 505, 10, 0 }; //870
struct Image imMonetkaF3 = { 970, 1125, 0, -10 }; //970
struct Image imMonetkaF4 = { 1950, 505, -10, 0 }; //1070
struct Image imMonetkaF5 = { 2000, 505, -10, 0 }; //1160

void DrawStart(HDC hdc) {
    ST(hdc);
    ST1(hdc);
    Robot(hdc, imRobot.cx, imRobot.cy);
    zayc(hdc, imZayc.cx, imZayc.cy);
    volk(hdc, imVolk.cx, imVolk.cy);
}
void DrawWin(HDC hdc) {
    WT(hdc);
    money(hdc, imMonetkaW.cx, imMonetkaW.cy);
    Robot(hdc, imRobotW.cx, imRobotW.cy);
    zayc(hdc, imZaycW.cx, imZaycW.cy);
    Robot(hdc, imRobotW2.cx, imRobotW2.cy);
    money(hdc, imMonetkaW2.cx, imMonetkaW2.cy);
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

    volk(hdc, imVolkL.cx, imVolkL.cy);
    zayc(hdc, imZaycL.cx, imZaycL.cy);
}
void DrawFinal(HDC hdc) {
    TT(hdc);
    money(hdc, imMonetkaF.cx, imMonetkaF.cy);
    money(hdc, imMonetkaF2.cx, imMonetkaF2.cy);
    money(hdc, imMonetkaF3.cx, imMonetkaF3.cy);
    money(hdc, imMonetkaF4.cx, imMonetkaF4.cy);
    money(hdc, imMonetkaF5.cx, imMonetkaF5.cy);
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
void RandomSpawnMoney() {
    srand(time(NULL));
    if (raz == 1) {
        monetka[0].X = rand() % (max - min + 1) + min;
        monetka[1].X = rand() % (max - min + 1) + min;
        monetka[2].X = rand() % (max - min + 1  ) + min;

    }
        raz = 0;
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
            RandomSpawnMoney();
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
            if (step > 130)
                mode = Final;
        }
        InvalidateRect(hWnd, NULL, TRUE);

        if (mode == Start) {

            imZayc.cx += imZayc.vx;
            imZayc.cy += imZayc.vy;
            imVolk.cx += imVolk.vx;
            imVolk.cy += imVolk.vy;
            imRobot.cx += imRobot.vx;
            imRobot.cy += imRobot.vy;
            if ((imVolk.cx == 2000) && (imVolk.cy == 800)) {
                imVolk.vx = 0;
                imVolk.vy = -10;
                imVolk.cx = 1500;
                imVolk.cy = 1080;

                imRobot.vx = 0;
                imRobot.vy = -10;
                imRobot.cx = 1500;
                imRobot.cy = 1220;

            }
            if ((imVolk.cy == -150) && (imVolk.cx == 1500)) {
                imVolk.vx = 0;
                imVolk.vy = 10;
                imVolk.cx = 180;
                imVolk.cy = -160;
                imZayc.vx = 0;
                imZayc.vy = 10;
                imZayc.cx = 180;
                imZayc.cy = -10;
            }
            if ((imVolk.cx == 180) && (imVolk.cy == 1100)) {
                imVolk.vx = -10;
                imVolk.vy = 0;
                imVolk.cx = 1850;
                imVolk.cy = 100;
                imRobot.vx = -10;
                imRobot.vy = 0;
                imRobot.cx = 1930;
                imRobot.cy = 100;
            }
            if ((imVolk.cx == -60) && (imVolk.cy == 100)) {  
                imVolk.vx = 10;
                imVolk.vy = 0;
                imVolk.cx = -60;
                imVolk.cy = 800;
                imZayc.vx = 10;
                imZayc.vy = 0;
                imZayc.cx = -10;
                imZayc.cy = 800;
            }
            }
            InvalidateRect(hWnd, NULL, TRUE);
            if (mode == Win) {

                imZaycW.cx += imZaycW.vx;
                imZaycW.cy += imZaycW.vy;
                imMonetkaW.cx += imMonetkaW.vx;
                imMonetkaW.cy += imMonetkaW.vy;
                imMonetkaW2.cx += imMonetkaW2.vx;
                imMonetkaW2.cy += imMonetkaW2.vy;
                imRobotW.cx += imRobotW.vx;
                imRobotW.cy += imRobotW.vy;
                imRobotW2.cx += imRobotW2.vx;
                imRobotW2.cy += imRobotW2.vy;
                if ((imRobotW.cx == 890) && (imRobotW.cy == 505)) {
                    imRobotW.vx = 0;
                    imRobotW.vy = 0;

                    imMonetkaW.vx = 0;
                    imMonetkaW.vy = 0;

                    imRobotW2.vx = 0;
                    imRobotW2.vy = 0;

                    imMonetkaW2.vx = 0;
                    imMonetkaW2.vy = 0;
                }
                if ((imZaycW.cx == 970) && (imZaycW.cy == 495)) { 
                    imZaycW.cx = 970;
                    imZaycW.cy = 505;
                }
            }
            InvalidateRect(hWnd, NULL, TRUE);
            if (mode == Loss) {
                imVolkL.cx += imVolkL.vx;
                imVolkL.cy += imVolkL.vy;
                if ((imVolkL.cx == 1100) && (imVolkL.cy == 750)) {
                    imVolkL.vx = 0;
                    imVolkL.vy = -10;
                }
                if ((imVolkL.cx == 1100) && (imVolkL.cy == 450)) {
                    imVolkL.vx = -10;
                    imVolkL.vy = 0;
                }
                if ((imVolkL.cx == 880) && (imVolkL.cy == 450)) {
                    imVolkL.vx = 0;
                    imVolkL.vy = 10;
                }
                if ((imVolkL.cx == 880) && (imVolkL.cy == 750)) {
                    imVolkL.vx = 10;
                    imVolkL.vy = 0;
                }
            }
            InvalidateRect(hWnd, NULL, TRUE);
            if (mode == Final) {
                imMonetkaF.cx += imMonetkaF.vx;
                imMonetkaF.cy += imMonetkaF.vy;
                imMonetkaF2.cx += imMonetkaF2.vx;
                imMonetkaF2.cy += imMonetkaF2.vy;
                imMonetkaF3.cx += imMonetkaF3.vx;
                imMonetkaF3.cy += imMonetkaF3.vy;
                imMonetkaF4.cx += imMonetkaF4.vx;
                imMonetkaF4.cy += imMonetkaF4.vy;
                imMonetkaF5.cx += imMonetkaF5.vx;
                imMonetkaF5.cy += imMonetkaF5.vy;
                if ((imMonetkaF.cx == 770) && (imMonetkaF.cy == 505)) { //d
                    imMonetkaF.vx = 0;
                    imMonetkaF.vy = 0;
                }
                if ((imMonetkaF2.cx == 870) && (imMonetkaF2.cy == 505)) { //d
                    imMonetkaF2.vx = 0;
                    imMonetkaF2.vy = 0;
                }
                if ((imMonetkaF3.cx == 970) && (imMonetkaF3.cy == 505)) { //Sred
                    imMonetkaF3.vx = 0;
                    imMonetkaF3.vy = 0;
                }
                if ((imMonetkaF4.cx == 1070) && (imMonetkaF4.cy == 505)) {
                    imMonetkaF4.vx = 0;
                    imMonetkaF4.vy = 0;
                }
                if ((imMonetkaF5.cx == 1160) && (imMonetkaF5.cy == 505)) { 
                    imMonetkaF5.vx = 0;
                    imMonetkaF5.vy = 0;
                }
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
