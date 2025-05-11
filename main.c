#include <stdio.h>
#include <windows.h>
#include "Draw.h"

int main() {

    //콘솔 인코딩 변경
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    srand(time(NULL));

    draw_menu();

    return 0;
}