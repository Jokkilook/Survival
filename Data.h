#pragma once

//플레이어 입력값
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27

//플레이어 구조체
typedef struct Player {
	int HP;
	int SP;
} Player;

//선택지 구조체 : text는 선택지 문구, apply는 선택지 선택 시 실행할 함수 이름
typedef struct Option {
	const char* text;
	void (*apply)(struct Player*); //함수 포인터로 함수를 변수처럼 사용할 수 있게 해 줌. 선택지에 따라 함수를 매칭
} Option;

//상황 구조체 : 보여줄 아스키 아트[screen], 상황 설명[text], 선택지 3가지[options]
typedef struct Scene {
	const char* screen;
	const char* text;
	Option options[3];
} Scene;