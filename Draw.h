#pragma once
#include "Data.h"

//아스키 아트 그려주는 함수
void draw_asciiart(const char* asciiart);

//게임 오버 화면을 그려주는 함수
void draw_game_over(Player* player, int count);

//플레이어 스탯 그려주는 함수
void draw_state(Player* player);

//문자 들어갈 네모 그리는 함수
void draw_box(int x, int y, int width, int height);

//메인 메뉴를 그려주는 함수
void draw_menu();

//게임 화면을 그려주는 함수
void draw_game();

//게임 정보 화면을 그려주는 함수
void draw_info();

//게임 중 일시 정시 화면을 그려주는 함수
void draw_pause(int* game);