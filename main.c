#include <stdio.h>
#include <windows.h>
#include "Draw.h"

void FixConsoleBufferSize(int cols, int rows);

void DisableConsoleResize();

int main() {
    //system("chcp 65001 > nul");
    FixConsoleBufferSize(100, 100);
    DisableConsoleResize();

    draw_menu();

    printf("게임을 종료합니다.\n");

    return 0;
}

void FixConsoleBufferSize(int cols, int rows) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD bufferSize = { cols, rows };
    SetConsoleScreenBufferSize(hConsole, bufferSize);

    SMALL_RECT windowSize = { 0, 0, cols - 1, rows - 1 };
    SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}


void DisableConsoleResize() {
    HWND consoleWindow = GetConsoleWindow();

    // 현재 스타일 가져오기
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

    // 최대화 버튼 제거 + 사이즈 조절 막기
    style &= ~WS_MAXIMIZEBOX;
    style &= ~WS_SIZEBOX;

    // 적용
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}