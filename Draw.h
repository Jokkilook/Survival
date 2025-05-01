#pragma once
#include "Data.h"

void move_cursor(int row, int col);

void print_wrapped_text(const char* text, int maxWidth, int startRow, int startCol);

void draw_box(int x, int y, int width, int height);

void draw_asciiart(const char* asciiart);

void draw_state(Player* player);

void draw_story();

void print_story(const char* text);

//메인 메뉴를 그려주는 함수
void draw_menu();

//게임 화면을 그려주는 함수
void draw_game();

//게임 정보 화면을 그려주는 함수
void draw_info();

//게임 중 일시 정시 화면을 그려주는 함수
void draw_pause(int* game);