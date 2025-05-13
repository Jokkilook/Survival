#include <stdio.h>
#include <windows.h>
#include "Draw.h"

int main() {

    //콘솔 인코딩 변경
    //SetConsoleOutputCP(65001);
    //SetConsoleCP(65001);

    //랜덤 설정
    srand(time(NULL));

    //메인 메뉴 그려서 시작
    draw_menu();

    return 0;
}