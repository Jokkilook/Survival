#include "Draw.h"
#include "Events.h"

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


        for (int i = 0; i < 3; ++i) {
            if (i == selected)
                printf(" > %s\n", menus[i]);
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
    //플레이어 초기화
    Player player = { 100,100 };

    while (game) {

        //저장된 여러 상황 중 하나를 골라옴
        Scene scene = pick_scene();

        //선택지를 뽑힌 상황의 선택지로 채우기
        const char* options[3];
        for (int i = 0; i < 3; i++) {
           options[i] = scene.options[i].text;
        }
        int optionsSize = sizeof(options) / sizeof(options[0]);

        //화면 초기화
        system("cls");

        //아스키 아트 출력
        printf("%s\n", scene.screen);

        //플레이어 스탯 출력
        printf("+--------+\n");
        printf("| HP %3d |\n", player.HP);
        printf("| SP %3d |\n", player.SP);
        printf("+--------+\n");

        printf("+-------------------------------------------+\n");
        //상황 설명 출력
        printf("%s\n\n",scene.text);

        //선택지 출력
        for (int i = 0; i < 3; i++) {
            if (i == selected)
                printf(" > %-10s", options[i]);
            else
                printf("   %-10s", options[i]);
        }
        printf("\n+-------------------------------------------+\n");
        
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
            selected = 0;
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
        printf("===== 게임 정보 =====\n\n");
        printf("당신은 깊은 산 속에서 홀로 조난당했습니다.\n");
        printf("탈출을 시도하는 당신의 앞에는 여러 상황이 펼쳐질 것입니다.\n");
        printf("당신의 현명한 판단만이 무사히 탈출할 수 있는 유일한 방법입니다.\n\n");
        printf("===== 조작법 =====\n");
        printf("←, → : 고르기 | Enter : 선택\n\n");
        printf("ESC를 누르면 메인 메뉴로 돌아갑니다.\n");

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

    const char* menus[] = {
    "돌아가기",
    "종료",
    };

    while (pause) {
        system("cls");
        printf("지금 종료하면 진행 상황이 모두 사라져요!\n");

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