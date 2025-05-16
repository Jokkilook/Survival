#pragma once

typedef struct Player Player;

typedef struct Scene Scene;

//Events.c파일에 선언된 scenes배열에서 하나를 랜덤으로 골라오는 함수
Scene pick_scene();

void shuffleScenes();

//게임 오버 후 점수 계산 함수
float calculateScore(Player* player, int sceneCount);

//HP 증가 함수 - 100이상 안올라가게 제한
void increaseHP(Player* player, int amount);

//HP 감소 함수 - 0이하 안떨어지게 제한
void decreaseHP(Player* player, int amount);

//SP 증가 함수 - 100이상 안올라가게 제한
void increaseSP(Player* player, int amount);

//SP 감소 함수 - 0이하 안떨어지게 제한
void decreaseSP(Player* player, int amount);

//선택지 선택 후 플레이어에게 선택의 결과 메시지를 출력하는 함수
void print_result(const char* text);

//곰 도망
void run(Player* player);

//곰 숨기
void hide(Player* player);

//곰 죽은 척
void pretending_dead(Player* player);

//먹음직 버섯 먹기
void eat_mushroom(Player* player);

//먹음직 버섯 한입만
void bite_mushroom(Player* player);

//먹음직 버섯 무시
void ignore_mushroom(Player* player);

//맑은 물 마시기
void drink_pure_water(Player* player);

//맑은 물 손 씻기
void wash_hand(Player* player);

//맑은 물 무시
void ignore_pure_water(Player* player);

//벌꿀 먹기
void eat_honey(Player* player);

//벌집 돌던지기
void throw_pebble(Player* player);

//벌집 도망
void runaway_bee(Player* player);

//화려한 버섯 먹기
void eat_pretty_mushroom(Player* player);

//화려한 버섯 밟기
void step_on_mushroom(Player* player);

//화려한 버섯 무시
void ignore_pretty_mushroom(Player* player);

// 여기 아래 부터 자기 이름 쓰여진 줄 및에 엔터 치면서
// 그 영역 안에서만 코드 써주세요.
//★★★★★★★★ 함수 위에는 항상 어떤 함수 인지 주석 달기 ★★★★★★★★★★
//정찬영-------------------------------------------------------------------------=
//뱀 도망
void run_snake(Player* player);

//뱀 잡아먹기
void eat_snake(Player* player);

//풀피리불기
void plute_snake(Player* player);

//산삼 먹기
void eat_sansam(Player* player);

//산삼 가져가기
void take_sansam(Player* player);

//산삼 무시
void ignore_sansam(Player* player);

//자연인 대화
void talk_nature_human(Player* player);

//자연인 싸움
void fight_nature_human(Player* player);

//자연인 무시
void ignore_nature_human(Player* player);

//호랑이 지켜보기
void see_tiger(Player* player);

//호랑이 도망
void run_tiger(Player* player);

//호랑이 유인
void attract_tiger(Player* player);

//상자 열기
void open_box(Player* player);

//상자 부수기
void close_box(Player* player);

//상자 무시
void ignore_box(Player* player);

//송지예-------------------------------------------------------------------------=

//산신령 빨간물약 
void red_drink(Player* player);

//산신령 파란물약 
void blue_drink(Player* player);

//산신령 선택 
void want_you(Player* player);

//동굴 쉬기 
void rest(Player* player);

//동굴 지나치기 
void pass_away(Player* player);

//동굴 탐험 
void explore(Player* player);

//소나기 나무 밑으로 피하기 
void under_tree(Player* player);

//소나기 그냥 맞기 
void stay_in_rain(Player* player);

//소나기 춤추기 
void dance(Player* player);

//신발끈 꼼꼼히 묶기
void tie_hard(Player* player);

//신발끈 안 묶기 
void not_tie(Player* player);

//신발끈 대충 묶기 
void tie_loose(Player* player);

//벌레 손 휘젓기 
void shake_hand(Player* player);

//벌레 차분히 떼어내기 
void careful_remove(Player* player);

//벌레 몸 세게 털기 
void shakeoff_bug(Player* player);


//한승우-------------------------------------------------------------------------=


