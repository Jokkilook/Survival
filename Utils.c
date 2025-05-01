#include <stdio.h>
#include "Utils.h"

//출력 커서 옮기는 함수
void move_cursor(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

//UTF-8 문자열의 한 문자(글자)의 바이트 길이를 반환하는 함수
int get_utf8_char_length(const char* str) {
    unsigned char c = (unsigned char)str[0];
    if ((c & 0x80) == 0x00) return 1;
    if ((c & 0xE0) == 0xC0) return 2;
    if ((c & 0xF0) == 0xE0) return 3;
    if ((c & 0xF8) == 0xF0) return 4;
    return 1; // 기본적으로 1바이트로 반환
}

//텍스트가 특정 너비 넘어가면 자동 줄바꿈 해주는 함수
void print_wrapped_text(const char* text, int maxWidth, int startRow, int startCol) {
    int col = startCol;
    int row = startRow;
    const char* p = text;

    while (*p) {
        int charLen = get_utf8_char_length(p);

        // 줄바꿈 처리: 너비를 넘기면 줄바꿈
        if (col - startCol >= maxWidth) {
            row++;
            col = startCol;
        }

        move_cursor(row, col);

        // 해당 문자를 출력
        for (int i = 0; i < charLen; ++i)
            putchar((unsigned char)p[i]);

        p += charLen;
        col++;

        // 공백 처리: 공백도 자동 줄바꿈에 포함
        if (*p == ' ') {
            if (col - startCol >= maxWidth) {
                row++;
                col = startCol;
            }
            else {
                move_cursor(row, col);
                putchar(' ');
                p++;
                col++;
            }
        }
    }
}

//네모칸 안에 텍스트(상황 설명 etc.) 출력하는 함수
void print_story(const char* text) {
    move_cursor(21, 4);
    printf("%s", text);
}