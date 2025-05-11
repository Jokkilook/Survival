#include <stdio.h>
#include "Utils.h"

//출력 커서 옮기는 함수
void move_cursor(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

//네모칸 안에 텍스트(상황 설명 etc.) 출력하는 함수
void print_story(const char* text) {
    move_cursor(24, 3);
    printf("                                                                          ");
    move_cursor(21, 4);
    printf("                                                                          ");
    move_cursor(21, 4);
    printf("%s", text);
}