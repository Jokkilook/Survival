#pragma once
#include "Data.h"

//입력된 위치로 커서를 옮겨주는 함수 
void move_cursor(int row, int col);

//입력된 위치의 입력된 크기의 박스를 그려주는 함수
void print_story(const char* text);