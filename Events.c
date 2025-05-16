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
Scene scenes[20] = {
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
    //정찬영
    {
        {"따먹는다", eat_pretty_mushroom },
        {"밟는다", step_on_mushroom },
        {"무시한다", ignore_pretty_mushroom }
    }
    },
    {
    "                                                                                \n"
"                                ---_ ......._-_--.                              \n"
"                             (|\\ /      / /| \\  \\                             \n"
"                             /  /     .'  -=-'   `.                             \n"
"                            /  /    .'             )                            \n"
"                          _/  /   .'        _.)   /                             \n"
"                         / o   o        _.-' /  .'                              \n"
"                         \\          _.-'    / .'*|                              \n"
"                          \\______.-'//    .'.' \\*|                              \n"
"                           \\|  \\ | //   .'.' _ |*|                              \n"
"                            `   \\|//  .'.'_ _ _|*|                              \n"
"                             .  .// .'.' | _ _ \\*|                              \n"
"                             \\`-|\\_/ /    \\ _ _ \\*\\                            \n"
"                              `/'\\__/      \\ _ _ \\*\\                           \n"
"                             /^|            \\ _ _ \\*                            \n"
"                            '  `             \\ _ _ \\                            \n"
"                                               \\_                              \n"
"                                                                                \n"
    ,
    "사나운 뱀을 마주쳤다!",
    {
        {"도망가자", run_snake},
        {"잡아먹자", eat_snake},
        {"풀피리를 불어보자", plute_snake}
    }
    },
    {
    "                                                                                \n"
    "                                       ●                                       \n"
    "                                      /|\\                                      \n"
    "                                       |                                       \n"
    "                                      / \\                                      \n"
    "                                      | |                                       \n"
    "                                     /   \\                                      \n"
    "                                    /     \\                                     \n"
    "                                   /       \\                                    \n"
    "                                  /         \\                                   \n"
    "                                 /           \\                                  \n"
    "                                /             \\                                 \n"
    "                               /               \\                                \n"
    "                              /                 \\                               \n"
    "                             /                   \\                              \n"
    "                            /                     \\                             \n"
    "                                                                              \n"
    ,
    "산삼..인가? 그런거 같다!",
    {
        {"바로 먹어보자", eat_sansam} ,
        {"가져가자", take_sansam} ,
        {"독일지도 모른다. 무시하자", ignore_sansam}
    }
    },
    {
"                 ,#####,                                                       \n"
"                 #_   _#                                                      \n"
"                 |a` `a|                                                      \n"
"                 |  u  |                                                      \n"
"                 \\  =  /                                                      \n"
"                 |\\___/|                                                      \n"
"        ___ ____/:     :\\____ ___                                            \n"
"      .'   `.-===-\\   /-===-.`   '.                                          \n"
"     /      .-\"\"\"\"\"-.-\"\"\"\"\"-.      \\                                        \n"
"    /'             =:=             '\\                                       \n"
"  .'  ' .:    o   -=:=-   o    :. '  `.                                     \n"
" (.'   /'. '-.....-'-.....-' .\\   '.)                                     \n"
" /' ._/   \".     --:--     .\"   \\_. '\\                                    \n"
"|  .'|      \".  ---:---  .\"      |'.  |                                     \n"
"|  : |       |  ---:---  |       | :  |                                     \n"
" \\ : |       |_____._____|       | : /                                     \n"
" /   (       |----|------|       )   \\                                     \n"
"/... .|      |    |      |      |. ...\\                                    \n"
    ,
    "산속의 자연인을 만났다..위험해보이는데..",
    {
        {"말을 걸어보자", talk_nature_human},
        {"선빵을 쳐보자", fight_nature_human},
        {"무시하자", ignore_nature_human}
    }
    },
    {
    "                                __,,,,_                                         \n"
    "                 _ __..-;''`--/'/ /.',-`-.                                      \n"
    "             (`/' ` |  \\ \\ \\\\ / / / / .-'/`,_                               \n"
    "            /'`\\ \\   |  \\ | \\| // // / -.,/_,'-,                            \n"
    "           /<7' ;  \\ \\  | ; ||/ /| | \\/    |`-/,/-.,_,/')                    \n"
    "          /  _.-, `,-\\,__|  _-| / \\ \\/|_/  |    '-/.;.\\'                    \n"
    "          `-`  f/ ;      / __/ \\__ `/ |__/ |                                   \n"
    "               `-'      |  -| =|\\_  \\  |-' |                                  \n"
    "                     __/   /_..-' `  ),'  //                                    \n"
    "                    ((__.-'((___..-'' \\__.'                                    \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    "                                                                                \n"
    ,
    "헉 귀여워서 다가가보니 호랑이였어! 어떻게하지..",
    {
        {"나무위에서 지켜보자", see_tiger},
        {"도망가자",run_tiger},
        {"떡으로 유인하자", attract_tiger}
    }
    },
    {
"                   +-------------------------------+                       \n"
"                  /|                              /|                      \n"
"                 / |                             / |                      \n"
"                *--+----------------------------*  |                      \n"
"                |  |                            |  |                      \n"
"                |  |                            |  |                      \n"
"                |  |                            |  |                      \n"
"                |  |                            |  |                      \n"
"                |  |                            |  |                      \n"
"                |  +----------------------------+--+                      \n"
"                | /                             | /                       \n"
"                |/                              |/                        \n"
"                *-------------------------------*                         \n"
"                                                                            \n"
"                                                                            \n"
"                                                                            \n"
"                                                                            \n"
"                                                                            \n"
    ,
    "오! 무언가 들어있을거같은 상자를 발견했어!",
    {
        {"열어보자", open_box},
        {"부숴보자", close_box},
        {"무시하자", ignore_box}
    }
    },
    //송지예
    {
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                               .--.     .---.    .--.                           \n"
   "                            .-(    ).-(     )--.(    ).                        \n"
   "                           (___.__(__)___(___(__.___)                          \n"
   "                               '   '  '  '   '  '  '                            \n"
   "                                |  |   ||   ||   |                             \n"
   "                               '  '  '   '  '  '   '                            \n"
   "                                |   |  ||  ||  |   |                           \n"
   "                               '  '   '   '   '  '  '                          \n"
   "                                |  |  |   ||   |  |                            \n"
   "                               '   '  '   '  '   '   '                         \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n",
   "갑자기 비가 내린다! 어쩌지...",
   {
      {"나무 밑으로 피한다", under_tree },
      {"그냥 맞는다", stay_in_rain},
      {"춤춘다", dance}
   }
    },
   {
   "                                                                                \n"
   "                                    ________                                    \n"
   "                                  __(_____  <|                                  \n"
   "                                 (____ / <| <|                                  \n"
   "                             (___ /  <| L`-------.                              \n"
   "                             (__ /   L`--------.  \\                             \n"
   "                            /  `.    ^^^^^ |   \\  |                             \n"
   "                            |     \\---------'    |/                             \n"
   "                             |______|____________/]                             \n"
   "                             [_____|`-.__________]                              \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n",
   "앗, 신발끈이 풀렸다! 어떻게 하지?",
   {
      {"꼼꼼히 묶는다", tie_hard },
      {"묶지 않는다.", not_tie},
      {"대충 묶는다.", tie_loose}
   }
   },
   {
   "                                                                                \n"
   "                                     _   _                                     \n"
   "                                    /(   )\\                                     \n"
   "                                    \\(   )/                                     \n"
   "                                  |/ \\\\_//  \\|                                  \n"
   "                                 /  (#) (#)  \\                                  \n"
   "                                 \\  /     \\  /                                  \n"
   "                                  \\ \\_____/ /                                   \n"
   "                                   \\/  |  \\/                                    \n"
   "                                 _ | o | o | _                                  \n"
   "                                | \\|o  |  o|/ |                                 \n"
   "                                |  |  o|o  |  |                                 \n"
   "                               /|\\ |o  |  o| /|\\                                \n"
   "                                   \\  o|o  /                                    \n"
   "                                   /\\__|__/\\                                    \n"
   "                                  /         \\                                   \n"
   "                                  \\         /                                   \n"
   "                                  |\\       /|                                   \n",
    "벌레가 붙었다!! 어떻게 하지?",
    {
       {"손을 막 휘젓는다.",shake_hand},
      {"차분히 떼어낸다.",careful_remove},
      {"몸을 세게 턴다.", shakeoff_bug}
   }
   },
   {
   "................................................................................\n"
   "................................................................................\n"
   "............................o\\..................................................\n"
   "........._______/\\_______/__\\__________.........................................\n"
   "........|....................- (  |..............................................\n"
   ".......','-.................. . `-|..............................................\n"
   "......(____\".       ,-.    '   ||................................................\n"
   ".......|.........../\\,-\\   ,-.  |................................................\n"
   ".......|......,-./     \\ /'.-\\ |................................................\n"
   ".......|...../-.,\\      /     \\|................................................\n"
   ".......|....../     \\    ,-.     \\..............................................\n"
   ".......|_____/_______\\__/___\\_____/.............................................\n"
   "................................................................................\n"
   "................................................................................\n"
   "................................................................................\n"
   "................................................................................\n"
   "................................................................................\n"
   "................................................................................\n",
   "동굴을 발견했다!",
   {
      {"쉰다.", rest},
      {"그냥 지나친다", pass_away},
      {"탐험한다", explore}
   }
   },
   {
   "                                    .------.                                    \n"
   "                                    /  ____  \\                                   \n"
   "                                   / __|__|__ \\                                  \n"
   "                                  _||/  \\/  \\||_                                 \n"
   "                                 / )/   00   \\( \\                                \n"
   "                                 | (   /  \\   ) |                                \n"
   "                                 \\__\\_(    )_/__/                                \n"
   "                                 / /   \\__/   \\ \\                               \n"
   "                                 |(  (\\____/)  )|                                \n"
   "                                 |/\\   ----   / |                                \n"
   "                                 /\\\\\\        /_/                                \n"
   "                                //|\\|\\______/|                                   \n"
   "                                //|\\\\________/|                                   \n"
   "                               ///|\\\\\\--------/                                   \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n"
   "                                                                                \n",

   "산신령이 나타났다! 양손에 빨간 물약과 파란 물약이 있는데...",
   {
      {"빨간 물약", red_drink },
      {"파란 물약", blue_drink},
      {"난 널 원해!", want_you }
   }
   }
};
int i = 0;

//저장된 scenes 중 하나를 랜덤하게 뽑는 함수
Scene pick_scene()
{   
    Scene picked = scenes[i];
    i++;

    return picked;
}

void shuffleScenes() {

    int n = 0;
    while (n < 20 && scenes[n].text != NULL) {
        n++;
    }

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Scene temp = scenes[i];
        scenes[i] = scenes[j];
        scenes[j] = temp;
    }
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
//뱀 도망
void run_snake(Player* player) {
    if (player->SP < 3) {
        print_result("내가 아니라 뱀이 도망가버렸다.");
    }
    else {
        decreaseSP(player, 3);
        print_result("휴, 독사였을지도 몰라.");
    }
}
//뱀 잡아먹기
void eat_snake(Player* player) {
    increaseSP(player, 70);
    print_result("뱀탕 오이시~!");
}
//풀피리 불기
void plute_snake(Player* player) {
    increaseHP(player, 1);
    increaseSP(player, 1);
    print_result("휘리휘리휘리, 뱀도 같이 춤을 춘다! 마음이 차분해지는걸~");
}
//산삼먹기
void eat_sansam(Player* player) {
    increaseHP(player, 50);
    print_result("오옷! 힘이 솟는다!");
}
//산삼 가져가기
void take_sansam(Player* player) {
    increaseSP(player, 5);
    print_result("탈출하면 팔아야징 ㅎㅎ 기분 좋당~");
}
//산삼 무시
void ignore_sansam(Player* player) {
    decreaseHP(player, 15);
    print_result("무시하고 가는데 산삼 줄기에 걸려 넘어졌다..");
}
//자연인 대화
void talk_nature_human(Player* player) {
    increaseSP(player, 20);
    print_result("대화를 하다보니 숲에서 살아남을 비법을 얻었다!");
}
//자연인 싸움
void fight_nature_human(Player* player) {
    decreaseHP(player, 10);
    if (player->SP < 20) {
        decreaseHP(player, 30);
        print_result("헉,,,헉,,저건 곰에 필적할지도 몰라,,");
    }
    else {
        decreaseSP(player, 20);
        print_result("후..별것도 아닌게..풍근쒜뀌");
    }
}
//자연인 무시
void ignore_nature_human(Player* player) {
    print_result("이상하게 생긴건 피하는게 좋갰지");
}
//호랑이 지켜보기
void see_tiger(Player* player) {
    print_result("후...그래도 안들킨거같다.");
}
//호랑이 도망
void run_tiger(Player* player) {
    if (player->SP < 30) {
        decreaseHP(player, 10);
    }
    else {
        decreaseSP(player, 30);
    }
}
//호랑이 유인
void attract_tiger(Player* player) {
    decreaseHP(player, 100);
}
//상자 열기
void open_box(Player* player) {
    increaseHP(player, 20);
    increaseSP(player, 30);
}
//상자 부수기
void close_box(Player* player) {
    if (player->SP < 30) {
        print_result("앗..안에 식량이있었다니...");
    }
    else {
        decreaseSP(player, 30);
        print_result("안돼!!!!!! X발 내 일용할 양식들이..");
    }
}
//상자 무시
void ignore_box(Player* player) {
    print_result("엄마가 남이 주는거나 바닥에있는건 주워먹지 말랬지!");
}

//송지예-------------------------------------------------------------------------=

//산신령 빨간물약 
void red_drink(Player* player) {
    increaseHP(player, 20);
    print_result("힘이 충전되는 기분이다!");
}

//산신령 파란물약 
void blue_drink(Player* player) {
    increaseSP(player, 20);
    print_result("정신이 맑아지는 기분이다!");
}

//산신령 선택 
void want_you(Player* player) {
    increaseHP(player, 20);
    increaseSP(player, 20);
    print_result("수줍어 하는 산신령이 물약 2개를 모두 줬다.");
}

//동굴 쉬기 
void rest(Player* player) {
    increaseHP(player, 17);
    print_result("조금 쉬었더니 체력 충전 완료!");
}

//동굴 지나치기 
void pass_away(Player* player) {
    print_result("엄마가 모르는 곳은 함부로 들어가면 안된다 했다.");
}

//동굴 탐험 
void under_tree(Player* player) {
    increaseSP(player, 19);
    print_result("동굴 속에서 자연의 신비를 느꼈다.");
}

//소나기 나무 밑으로 피하기 
void explore(Player* player) {
    increaseSP(player, 5);
    print_result("빗소리만이 울려퍼진다. 운치를 즐겨보자.");
}

//소나기 그냥 맞기 
void stay_in_rain(Player* player) {
    decreaseHP(player, 10);
    print_result("몽땅 젖어버렸다!");
}

//소나기 춤추기 
void dance(Player* player) {
    decreaseHP(player, 15);
    increaseSP(player, 20);
    print_result("다 젖었지만, 낭만은 챙겼다.");
}

//신발끈 꼼꼼히 묶기
void tie_hard(Player* player) {
    print_result("아주 단단히 묶었다. 이제 안풀리겠지?");
}

//신발끈 안 묶기 
void not_tie(Player* player) {
    decreaseHP(player, 12);
    print_result("걷다 신발끈을 밟아 넘어졌다! 아프다!");
}

//신발끈 대충 묶기 
void tie_loose(Player* player) {
    decreaseSP(player, 9);
    print_result("신발끈이 또 풀렸다! 묶은지 얼마나 되었다고..");
}

//벌레 손 휘젓기 
void shake_hand(Player* player) {
    decreaseHP(player, 4);
    decreaseSP(player, 8);
    print_result("으악! 뭐야 이거! 나한테 붙었어!!");
}

//벌레 차분히 떼어내기 
void careful_remove(Player* player) {
    decreaseSP(player, 10);
    print_result("후.. 어차피 별거 없는 벌레다...");
}

//벌레 몸 세게 털기 
void shakeoff_bug(Player* player) {
    decreaseHP(player, 10);
    decreaseSP(player, 8);
    print_result("몸을 털다 넘어졌다! 아이고야!");
}


//한승우-------------------------------------------------------------------------=


