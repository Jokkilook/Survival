#include <conio.h>
#include "Events.h"
#include "Data.h"
#include "stdlib.h"
#include "time.h"
#include "Utils.h"

//상황 데이터베이스
//아스키 아트 사이즈는 세로 18, 가로 80으로.
//아스키 아트는 맘에 드는 거 찾았으면 복사해서 채찍피티한테 주고 
//"이거 그림이 중앙으로 오게 가로 80 세로 18 사이즈로 C언어 const char*에 저장할 수 있게 바꿔줘" 하면 변환해줍니다.
//상황 설명은 37자 이내(한 줄 이내)가 좋을 듯... 그래야 안넘어가서 이쁨..
//선택지 텍스트도 가급적 짧게 길면 어쩔 수 없지만
const Scene scenes[20] = {
    {
    "          \n"
    "          \n"
    "          \n"
    "          \n"
    "          \n"
    "          \n"
    "          \n"
    "                              .--.              .--.          \n"
    "                             : (\\ \". _......_ .\" /) :         \n"
    "                              '.    `        `    .'          \n"
    "                               /'   _        _   `\\           \n"
    "                              /     0}      {0     \\          \n"
    "                             |       /      \\       |         \n"
    "                             |     /'        `\\     |         \n"
    "                              \\   | .  .==.  . |   /          \n"
    "                               '._ \\\'. \\__/ ./\\ _.'           \n"
    "                               /  ``'._-''-_.'``  \\           \n"
    "                                                              \n"
    "                                                              \n"
    "                                                              \n"
    "                                                              \n",
        "산 속에 곰을 마주쳤다... 어쩌지...",
        {
            { "도망간다", run },
            { "숨는다", hide },
            { "죽은 척", pretending_dead }
        }
    },
    {
    "                                                                              \n"
    "                                                                              \n"
    "                                                                              \n"
    "                                                                              \n"
    "                                                                              \n"
    "                                   ___..._                                \n"
    "                              _,--'       \"-.                               \n"
    "                            ,'.  .            \\                             \n"
    "                          ,/:. .     .       .'                             \n"
    "                          |;..  .      _..--'                               \n"
    "                          --:...-,-'\"\"\\                                    \n"
    "                                  |:.  .                                    \n"
    "                                  l;.   l                                   \n"
    "                                  |:.   |                                   \n"
    "                                   |:.   .,                                 \n"
    "                                  .l;.    j, ,                              \n"
    "                               . \\;:.   //,/                                \n"
    "                                .\\\\);,|\\'/\\(                               \n"
    ,
    "먹음직스러운 버섯을 발견했다! 어떻게 할까?",
    {
        { "먹는다", eat_mushroom },
        { "조금만 먹어본다", bite_mushroom },
        { "무시한다", ignore_mushroom }
    }
    },
    {
    "\n"
    "\n"
    "\n"
    "\n"
    "          .                  .-.    .  _   *     _   .                             \n"
    "                 *          /   \\     ((       _/ \\       *    .                   \n"
    "           _    .   .--'\\/\\_ \\     `      /    \\  *    ___                    \n"
    "           *  / \\_    _/ ^      \\/\\'__        /\\/\\  /\\  __/   \\ *               \n"
    "             /    \\  /    .'   _/  /  \\  *' /    \\/  \\/ .`'\\_/\\   .               \n"
    "        .   /\\/\\  /\\/ :' __  ^/  ^/    `--./.'  ^  `-.\\ _    _:\\ _                 \n"
    "           /    \\/  \\  _/  \\-' __/.' ^ _   \\_   .'.\\   _/ \\ .  __/ \\               \n"
    "         /\\  .-   `. \\/     \\ / -.   _/ \\ -. `_/   \\ /    `._/  ^  \\              \n"
    "        /  `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `.              \n"
    "      @/        `.  / /      `-.   /  .-'   / .   .'   \\    \\  \\  .-  \\%            \n"
    "      @&8jgs@@%% @)&@&(88&@.-_=_-=_-=_-=_-=_.8@% &@&&8(8%@%8)(8@%8 8%@)%             \n"
    "      @88:::&(&8&&8:::::%&`.~-_~~-~~_~-~_~-~~=.'@(&%::::%@8&8)::&#@8::::           \n"
    "      `::::::8%@@%:::::@%&8:`.=~~-.~~-.~~=..~'8::::::::&@8:::::&8:::::'             \n"
    "       `::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.'               \n",
    "깨끗해보이는 물 웅덩이를 발견했다!",
    {
        { "마신다", drink_pure_water },
        { "그냥 지나간다", ignore_pure_water },
        { "손만 씻는다", wash_hand }
    }
    },
    {
"                                                                                \n"
"                                                                                \n"
"                    ^^      .-=-=-=-.  ^^                                     \n"
"              ^^         (`-=-=-=-=-`)         ^^                           \n"
"                       (`-=-=-=-=-=-=-`)  ^^         ^^                     \n"
"                 ^^   (`-=-=-=-=-=-=-=-`)   ^^                            ^^     \n"
"                     ( `-=-=-=-(@)-=-=-` )      ^^                             \n"
"                     (`-=-=-=-=-=-=-=-=-`)  ^^                                 \n"
"                     (`-=-=-=-=-=-=-=-=-`)  ^^                                 \n"
"                      (`-=-=-=-=-=-=-=-`)          ^^                          \n"
"                       (`-=-=-=-=-=-=-`)  ^^                 ^^                \n"
"                         (`-=-=-=-=-`)                                          \n"
"                          `-=-=-=-=-`                                           \n"
        ,
        "꿀이 흐르는 꿀벌집이다!!",
    {
        { "위험을 무릅쓰고 꿀을 먹는다", eat_honey },
        { "돌을 던져 본다", throw_pebble },
        { "도망간다", runaway_bee }
    }
    },
    {
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                             .-'~~~-.\                                          \n"
    "                           .'o  oOOOo.                                          \n"
    "                          :~~~-.oOo   o.                                        \n"
    "                           . \\ ~-.  oOOo.                                       \n"
    "                             .; / ~.  OO:                                       \n"
    "                             .'  ;-- .o.'                                       \n"
    "                            ,'  ; ~~--'~                                        \n"
    "                            ;  ;                                               \n"
    "____________________\\|/__\\____;__\\\\;_\\\\//___\\|/_________________________\n"
    ,
    "화려한 버섯을 발견했다!",
    {
        {"따먹는다", eat_pretty_mushroom },
        {"밟는다", step_on_mushroom },
        {"무시한다", ignore_pretty_mushroom }
    }
    }
};

//저장된 scenes 중 하나를 랜덤하게 뽑는 함수
Scene pick_scene()
{   
    int count = 0;
    Scene picked;
    while (scenes[count].screen != NULL) {
        ++count;
    }

    int index = rand() % count;
    picked = scenes[index];

    return picked;
}

//게임 오버 시 플레이어 HP/SP, 진행한 씬 개수에 따라 점수 합산
float calculateScore(Player* player, int sceneCount) {
    float hpScore = player->HP;
    float spScore = player->SP;
    float sceneScore = (20 - sceneCount) * 40;

    return (hpScore + spScore + sceneScore);
}

//HP 증가 함수
void increaseHP(Player* player, int amount)
{
    player->HP += amount;

    if (player->HP > 100) player->HP = 100;
}

//HP 감소 함수
void decreaseHP(Player* player, int amount)
{
    player->HP -= amount;

    if (player->HP < 0) player->HP = 0;
}

//SP 증가 함수
void increaseSP(Player* player, int amount)
{
    player->SP += amount;

    if (player->SP > 100) player->SP = 100;
}

// SP 감소 함수
void decreaseSP(Player* player, int amount)
{
    player->SP -= amount;

    if (player->SP < 0) player->SP = 0;
}

//선택 결과 텍스트 출력 함수 - 출력 후 플레이어 ENTER 입력 대기
void print_result(const char* text) {
    print_story(text);

    while (1) {
        int key = _getch();

        if (key == KEY_ENTER) break;
    };
}

//선택지 실행 함수 구현할 때에는 마지막에 print_result를 써서 선택에 따른 결과를 텍스트로 보여주기

//아래 6가지는 예시
//아래와 같이 if문으로 조건을 주면서 현재 플레이어 상태에 따라 선택의 결과도 다르게 출력할 수 있습니다.
//HP, SP 감소 증가 분은 꼭 10단위로 하지 않아도 됨.

//곰 만났을 때 도망가기 선택 - SP 딸리면 사망
void run(Player* player) {

    //스태미나가 10이하면
    if (player->SP <= 10) {
        decreaseHP(player, 100);
        print_result("도망칠 힘이 없어 당하고 말았다...");
    }
    else {
        decreaseSP(player, 10);
        print_result("힘들게 도망쳤다...");
    }
}

//곰 만났을 때 숨기 선택 - SP 딸리면 사망
void hide(Player* player)
{
    //스태미나가 10이하면
    if (player->SP <= 10) {
        decreaseHP(player, 100);
        print_result("숨을 힘도 없네... 꿱");
    }
    else {
        decreaseSP(player, 10);
        print_result("바위 뒤에 숨었더니 그냥 지나갔다...");
    }
}

//곰 만났을 때 죽은 척 선택 - 무조건 사망
void pretending_dead(Player* player)
{
    decreaseHP(player, 100);
    print_result("찢겨버렸다.");
}

//독버섯을 먹었을 때 - 피 80, 스태미나 50 깎기 (만약 피가 80이하면 바로 죽는 거임)
void eat_mushroom(Player* player) {
    decreaseHP(player, 80);
    decreaseSP(player, 50);
    print_result("치명적인 독버섯이다...");
}

//독버섯을 조금만 먹었을 때 - 피 20, 스태미나 20 깎기 (이것도 피 20이하면 사망)
void bite_mushroom(Player* player) {
    decreaseHP(player, 20);
    decreaseSP(player, 20);
    print_result("몸이 안좋다... 다 안먹길 잘했군.");
}

//독버섯 무시 - 아무일도 일어나지 않는다. 다음턴으로
void ignore_mushroom(Player* player) {
    print_result("이상한 버섯을 먹어서 좋을 게 없지.");
}

//맑은 물 마심
void drink_pure_water(Player* player) {
    increaseHP(player, 20);
    increaseSP(player, 40);
    print_result("맑고 시원한 물이다!");
}

//맑은 물 손만 씻음
void wash_hand(Player* player) {
    increaseHP(player, 1);
    print_result("손이 깨끗하니 좋네.");
}

//맑은 물 무시
void ignore_pure_water(Player* player) {
    print_result("어떤 세균이 있을 지 몰라... 그냥 지나가자.");
}

//벌꿀 먹기
void eat_honey(Player* player) {
    if (player->SP > 40) {
        decreaseHP(player, 4);
        increaseSP(player, 30);
        print_result("히히 맛있당");
    }
    else {
        decreaseHP(player, 20);
        decreaseSP(player, 20);
        print_result("먹고 튀다가 쏘여버렸다...");
    }
}

//벌집에 돌던지기
void throw_pebble(Player* player) {
    decreaseSP(player, 20);
    if (player->SP > 40) {
        print_result("시비걸고 튀었다!!");
    }
    else {
        decreaseHP(player, 14);
        print_result("도망가다 몇 방 쏘였다...");
    }
}

//벌집 도망
void runaway_bee(Player* player) {
    print_result("벌은 무서워~");
}

//화려한 버섯 먹음
void eat_pretty_mushroom(Player* player) {
    increaseHP(player, 60);
    increaseSP(player, 30);
    print_result("오오!! 힘이 난다!!!");
}

//화려한 버섯 밟음
void step_on_mushroom(Player* player) {
    decreaseHP(player, 4);
    print_result("윽! 포자가 코에...!");
}

//화려한 버섯 무시
void ignore_pretty_mushroom(Player* player) {
    print_result("모르는 버섯은 무서워...");
}

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//이 밑에 선택지 결과 함수 구현하면 됩니다.---------------------------------------------------------------------

// 함수 형식은 아래와 같이 ===========================
// void 함수이름(Player* player) {  <--매개변수는 플레이어의 스탯을 조작하기 때문에 필요하고, 반환형은 void 입니다.
//      함수 내용
//      if 조건문을 줘서 현 플레이어 상태에 따라 다른 결과가 나오게 해도 되고
//      여러 방식으로 구현하되, 마지막 결과는 
//      print_result("플레이어한테 보여줄 내용") 함수를 써서 마무리하면 됩니다.
// }
// =================================================

//★★★★★★★★ 함수 위에는 항상 어떤 함수 인지 주석 달기 ★★★★★★★★★★
// 여기 아래 부터 자기 이름 쓰여진 줄 및에 엔터 치면서
// 그 영역 안에서만 코드 써주세요.
//정찬영-------------------------------------------------------------------------=



//송지예-------------------------------------------------------------------------=



//한승우-------------------------------------------------------------------------=


