#include <stdio.h>
#include <windows.h>
#include "Draw.h"

void disable_console_resize() {
    HWND hwnd = GetConsoleWindow();

    // 창 크기 조절 방지 (타이틀 바, 최소화/최대화 버튼 설정)
    LONG style = GetWindowLong(hwnd, GWL_STYLE);
    style &= ~WS_MAXIMIZEBOX; // 최대화 버튼 제거
    style &= ~WS_SIZEBOX;     // 창 크기 조절 막기
    SetWindowLong(hwnd, GWL_STYLE, style);

    // 변경된 스타일 적용
    SetWindowPos(hwnd, NULL, 0, 0, 0, 0,
        SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);
}

int main() {
    disable_console_resize();
    draw_menu();

    printf("게임을 종료합니다.\n");
    return 0;
}
