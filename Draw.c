#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Draw.h"
#include "Events.h"
#include "Utils.h"


const char* title[] = {
    " ___  ___  ___  ___  ___  ___   ___  ___  ___  ___  ___  ___ ",
    "| __>| . || . \\| __>/ __>|_ _| | __>/ __>|  _>| . || . \\| __>",
    "| _> | | ||   /| _> \\__ \\ | |  | _> \\__ \\| <__|   ||  _/| _> ",
    "|_|  `___'|_\\_\\|___><___/ |_|  |___><___/`___/|_|_||_|  |___>",
    "                                                              "
};

const char* pauseText[] = {
    " ___  ___  _ _  ___  ___ ",
    "| . \\| . || | |/ __>| __>",
    "|  _/|   || ' |\\__ \\| _> ",
    "|_|  |_|_|`___'<___/|___>",
    "                          "
};

//플레이어 스탯칸 그리는 함수
void draw_state(Player* player) {
    move_cursor(15, 0);
    draw_box(0,15,10,4);
    move_cursor(16, 2);
    printf(" HP %3d\n", player->HP);
    move_cursor(17, 2);
    printf(" SP %3d\n", player->SP);
}

//상황 설명과 선택지가 출력될 네모 그리는 함수
void draw_story() {
    move_cursor(19, 0);
    draw_box(0, 19, 80, 8);
}

//문자 들어갈 네모 그리는 함수
void draw_box(int x, int y, int width, int height) {
    move_cursor(y, x);
    printf("┌");
    for (int i = 0; i < width - 2; ++i) printf("─");
    printf("┐");

    // 중간
    for (int i = 1; i < height - 1; ++i) {
        move_cursor(y + i, x);
        printf("│");
        for (int j = 0; j < width - 2; ++j) printf(" ");
        printf("│");
    }

    // 아랫줄
    move_cursor(y + height - 1, x);
    printf("└");
    for (int i = 0; i < width - 2; ++i) printf("─");
    printf("┘");

}

//아스키 아트 그리는 함수
void draw_asciiart(const char* asciiart) {
    move_cursor(0, 0);
    printf("%s", asciiart);
}

void draw_game_over(Player* player) {
    move_cursor(0, 0);

    //탈출 시 보여줄 화면
    if (player->HP > 0) {
        printf("탈출 성공");
    }

    //죽었을 때 보여줄 화면
    else {
        printf("님 죽음... 저런...\n");
    }

    //플레이어 입력 대기
    while (1) {
        int key = _getch();
        if (key == KEY_ENTER || key == KEY_ESC) break;
    }
}


//메인 메뉴 화면 그려주는 함수
void draw_menu() {

    const char* menus[] = {
        "게임 시작",
        "게임 정보",
        "종료"
    };

    int menu = 1;
    int menu_count = 3;
    int selected = 0;

    while (menu) {
        system("cls");

        //로고 출력
        for (int i = 0; i < sizeof(title) / sizeof(title[0]); ++i) {
            printf("%s\n", title[i]);
        }

        printf(" \n\n\n\n");

        //메뉴 출력
        for (int i = 0; i < 3; ++i) {
            if (i == selected)
                printf(" > %s\n", menus[i]);
            else if (i == menu_count-1)
                printf("   %s", menus[i]);
            else
                printf("   %s\n", menus[i]);
        }

        int key = _getch();

        if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
            case KEY_UP:
                selected = (selected - 1 + menu_count) % menu_count;
                break;
            case KEY_DOWN:
                selected = (selected + 1) % menu_count;
                break;
            }
        }
        else if (key == KEY_ENTER) {
            switch (selected) {
            case 0:
                draw_game();
                break;
            case 1:
                draw_info();
                break;
            case 2:
                menu = 0;
                break;
            }
        }
    }
}

//게임 실행 화면 함수 : 게임 시작 선택 시 실행
void draw_game() {

    int game = 1;
    int selected = 0;
    int count = 20;
    //플레이어 초기화
    Player player = { 100,100 };
    //저장된 여러 상황 중 하나를 골라옴
    Scene scene = pick_scene();

    while (game) {

        //선택지를 뽑힌 상황의 선택지로 채우기
        const char* options[3];
        for (int i = 0; i < 3; i++) {
            options[i] = scene.options[i].text;
        }
        int optionsSize = sizeof(options) / sizeof(options[0]);

        //화면 초기화
        system("cls");

        //아스키 아트 출력
        draw_asciiart(scene.screen);

        //플레이어 스탯 출력
        draw_state(&player);

        //상황 박스 출력
        draw_story();

        //상황 설명 출력
        print_story(scene.text);

        //선택지 출력
        move_cursor(24, 4);
        for (int i = 0; i < 3; i++) {
            if (i == selected)
                printf(" > %-10s", options[i]);
            else
                printf("   %-10s", options[i]);
        }

        //플레이어 입력 받기
        int key = _getch();

        //방향기 좌우 입력 시
        if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
            case KEY_LEFT:
                selected = (selected - 1 + optionsSize) % optionsSize;
                break;
            case KEY_RIGHT:
                selected = (selected + 1) % optionsSize;
                break;
            }
        }
        //엔터 입력 시
        else if (key == KEY_ENTER) {
            switch (selected) {
            case 0:
                scene.options[0].apply(&player);
                break;
            case 1:
                scene.options[1].apply(&player);
                break;
            case 2:
                scene.options[2].apply(&player);
                break;
            }

            count--;

            //게임 오버 여부 판단
            //HP가 0이면 게임 오버 OR 상황 20개를 통과하고도 HP가 남아있으면 탈출 성공
            if (player.HP <= 0 || count <= 0) {
                //플레이어 스탯 업데이트
                draw_state(&player);
                draw_game_over(&player);
                game = 0;
            }

            //선택지를 선택해서 결과가 나오면 다음 scene을 뽑음
            scene = pick_scene();

        }
        //ESC 입력 시
        else if (key == KEY_ESC) {
            draw_pause(&game);
        }


    }
}

//게임 정보 화면 출력
void draw_info() {
    int info = 1;

    while (info) {
        system("cls");

        //로고 출력
        for (int i = 0; i < sizeof(title) / sizeof(title[0]); ++i) {
            printf("%s\n", title[i]);
        }

        //게임 정보 출력
        printf("===== 게임 정보 =====\n\n");
        printf("당신은 깊은 산 속에서 홀로 조난당했습니다.\n");
        printf("탈출을 시도하는 당신의 앞에는 여러 상황이 펼쳐질 것입니다.\n");
        printf("당신의 현명한 판단만이 무사히 탈출할 수 있는 유일한 방법입니다.\n\n\n\n");
        
        //조작법 출력
        printf("===== 조작법 =====\n\n");
        printf("←, → : 고르기 | Enter : 선택\n\n\n\n");
        printf("ESC를 누르면 메인 메뉴로 돌아갑니다.");

        int key = _getch();
        if (key == KEY_ESC) {
            info = 0;
        }
    }
}

//일시정지 화면 출력
void draw_pause(int* game) {
    int pause = 1;
    int menu_count = 2;
    int selected = 0;

    const char* menus[] = { "돌아가기", "종료" };

    while (pause) {
        system("cls");

        //PAUSE 출력
        for (int i = 0; i < sizeof(pauseText) / sizeof(pauseText[0]); ++i) {
            printf("%s\n", pauseText[i]);
        }

        printf("\n\n지금 종료하면 진행 상황이 모두 사라져요!\n\n");

        for (int i = 0; i < 2; ++i) {
            if (i == selected)
                printf(" > %s\n", menus[i]);
            else
                printf("   %s\n", menus[i]);
        }

        int key = _getch();

        if (key == KEY_ESC) {
            pause = 0;
        }

        if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
            case KEY_UP:
                selected = (selected - 1 + menu_count) % menu_count;
                break;
            case KEY_DOWN:
                selected = (selected + 1) % menu_count;
                break;
            }
        }
        else if (key == KEY_ENTER) {
            switch (selected) {
            case 0:
                pause = 0;
                break;
            case 1:
                *game = 0;
                pause = 0;
                break;
            }
        }
    }
}