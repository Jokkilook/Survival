#pragma once

typedef struct Player Player;

typedef struct Scene Scene;

//Events.c파일에 선언된 scenes배열에서 하나를 랜덤으로 골라오는 함수
Scene pick_scene();

float calculateScore(Player* player, int sceneCount);

void increaseHP(Player* player, int amount);

void decreaseHP(Player* player, int amount);

void increaseSP(Player* player, int amount);

void decreaseSP(Player* player, int amount);

void print_result(const char* text);

void run(Player* player);

void hide(Player* player);

void pretending_dead(Player* player);

void eat_mushroom(Player* player);

void bite_mushroom(Player* player);

void ignore_mushroom(Player* player);

void drink_pure_water(Player* player);

void wash_hand(Player* player);

void ignore_pure_water(Player* player);

void eat_honey(Player* player);

void throw_pebble(Player* player);

void runaway_bee(Player* player);

void eat_pretty_mushroom(Player* player);

void step_on_mushroom(Player* player);

void ignore_pretty_mushroom(Player* player);

// 여기 아래 부터 자기 이름 쓰여진 줄 및에 엔터 치면서
// 그 영역 안에서만 코드 써주세요.
//정찬영-------------------------------------------------------------------------=



//송지예-------------------------------------------------------------------------=



//한승우-------------------------------------------------------------------------=


