#pragma once

typedef struct Player Player;

typedef struct Scene Scene;

//.c파일에 선언된 scenes배열에서 하나를 랜덤으로 골라오는 함수
Scene pick_scene();

void run(Player* player);


