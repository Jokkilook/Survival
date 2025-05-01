#pragma once

typedef struct Player Player;

typedef struct Scene Scene;

//.c파일에 선언된 scenes배열에서 하나를 랜덤으로 골라오는 함수
Scene pick_scene();

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