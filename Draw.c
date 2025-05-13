#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Draw.h"
#include "Events.h"
#include "Utils.h"

//플레이어 스탯칸 그리는 함수
void draw_state(Player* player) {
    move_cursor(15, 0);
    draw_box(0,15,10,4);
    move_cursor(16, 2);
    printf(" \033[1;31mHP\033[0m %3d\n", player->HP);
    move_cursor(17, 2);
    printf(" \033[1;36mSP\033[0m %3d\n", player->SP);
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
    //위치 상관 없이 0,0위치부터 아스키아트 출력
    move_cursor(0, 0);
    printf("%s", asciiart);
}

//배열로 저장된 아스키 아트 특정 위치 출력 함수
void print_asciiart_at_location(int row, int col, const char* str) {
    //row, col 위치에 str 출력
    printf("\033[%d;%dH%s", row, col, str);
}

//게임 오버 화면을 그려주는 함수
void draw_game_over(Player* player, int count) {
    

    //남은 체력과 스태미나, 통과한 스테이지 기반으로 점수 계산
    float score = calculateScore(player, count);

    //탈출 성공 시 아웃트로 먼저 출력
    if (player->HP > 0) {
        //화면 초기화
        system("cls");
        draw_box(0, 25, 80, 6);
        //플레이어 스탯 출력
        draw_state(player);
        //상황 박스 출력
        draw_box(0, 19, 80, 8);
        //아웃트로 시작
        for (int i = 0; i < sizeof(outro) / sizeof(outro[0]); i++) {
            //인트로 스토리 출력
            print_story(outro[i]);
            //안내 메시지 출력
            move_cursor(28, 4);
            printf("\033[1;32mEnter키를 눌러 진행...\033[0m");
            //플레이어 입력 대기
            while (1) {
                //플레이어 입력 받기
                int key = _getch();
                //엔터 입력 시 넘어가기
                if (key == KEY_ENTER) break;
            }
        }
    }

    //아웃트로 끝나면 화면 초기화 후 게임 오버 화면 그리기
    system("cls");
    draw_box(0, 1, 80, 30);

    move_cursor(0, 0);

    //GAME OVER 출력
    for (int i = 0; i < sizeof(overTitle) / sizeof(overTitle[0]); ++i) {
        print_asciiart_at_location(4 + i, 2, overTitle[i]);
    }

    //결과(HP, SP, 점수)박스 그리기
    draw_box(34, 15, 16, 9);
    move_cursor(17, 37);
    printf("\033[1;31mHP\033[0m:  %5d", player->HP);
    move_cursor(19, 37);
    printf("\033[1;36mSP\033[0m:  %5d", player->SP);
    move_cursor(21, 37);
    printf("\033[1;32m점수\033[0m:%5.0f", score);

    //탈출 시 보여줄 문구
    if (player->HP > 0) {
        move_cursor(12, 26);
        printf("\033[1;34m★ 숲에서 무사히 탈출했습니다! ★ \033[0m");
    }

    //죽었을 때 보여줄 문구
    else {
        move_cursor(12, 29);
        printf("\033[1;31m숲에서 살아남지 못했습니다.\033[0m");
    }

    //키 입력 안내 문구
    move_cursor(26, 26);
    printf("\033[1;33mEnter 키를 눌러 메인화면으로...\033[0m");

    //플레이어 입력 대기 - ENTER 입력 시 루프 깨고 메인으로
    while (1) {
        int key = _getch();
        if (key == KEY_ENTER || key == KEY_ESC) break;
    }
};

//메인 메뉴 화면 그려주는 함수
void draw_menu() {

    //메뉴 글
    const char* menus[] = {
        "게임 시작",
        "게임 정보",
        "종료"
    };

    //메인 메뉴 상태 변수 1 : 출력 / 0 : 종료
    int menu = 1;
    //메뉴 개수
    int menu_count = 3;
    //선택지 인덱스
    int selected = 0;
    //선택지 새로고침 상태 변수
    int select = 1;

    while (menu) {
        system("cls");

        draw_box(0, 1, 80, 30);

        //로고 출력
        for (int i = 0; i < sizeof(title) / sizeof(title[0]); ++i) {
            print_asciiart_at_location(6 + i, 10, title[i]);
        }

        //메뉴 박스 출력
        draw_box(33, 20, 15, 7);

        select = 1;

        while (select) {

            //메뉴 출력
            for (int i = 0; i < 3; ++i) {
                move_cursor(22 + i, 34);
                if (i == selected)
                    printf("\033[01;33m > %s\033[0m\n", menus[i]);
                else if (i == menu_count - 1)
                    printf("   %s", menus[i]);
                else
                    printf("   %s\n", menus[i]);
            }

            //커서 이쁘게 이동
            move_cursor(24, 41);

            //메뉴 선택 입력 받기
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
                    exit(0);
                    break;
                }
                select = 0;
            }
        }
    }
}

//게임 실행 화면 함수 : 게임 시작 선택 시 실행
void draw_game() {

    //게임 상태 변수 1 : 게임 중 / 0 : 게임 종류
    int game = 1;
    //선택지 인덱스
    int selected = 0;
    //남은 Scene 변수 - Scene 하나 지날 때마다 --
    int count = 20;
    //Scene 중복 방지를 위한 Scene 기록 배열
    Scene sceneRecord[30];
    //선택지 새로고침 상태 변수
    int select = 1;

    //플레이어 초기화
    Player player = { 79, 80 };
    //저장된 여러 상황 중 하나를 골라옴
    Scene scene = pick_scene();
    //상황 기록에 삽입
    sceneRecord[20] = scene;

    //화면 초기화
    system("cls");
    draw_box(0, 25, 80, 6);
    //상황 박스 출력
    draw_box(0, 19, 80, 8);

    //인트로 시작
    for (int i = 0; i < sizeof(intro) / sizeof(intro[0]); i++) {
        //인트로 스토리 출력
        print_story(intro[i]);
        //안내 메시지 출력
        move_cursor(28, 4);
        printf("\033[1;32mEnter키를 눌러 진행...\033[0m");
        //플레이어 입력 대기
        while (1) {
            //플레이어 입력 받기
            int key = _getch();
            //엔터 입력 시 넘어가기
            if (key == KEY_ENTER) break;
        }
    }

    //메인 게임 시작
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

        //하단 박스 출력
        draw_box(0, 25, 80, 6);
        //상황 박스 출력
        draw_box(0, 19, 80, 8);

        //상황 설명 출력
        print_story(scene.text);
        
        select = 1;

        while (select) {

            //선택지 출력
            move_cursor(24, 3);
            for (int i = 0; i < 3; i++) {
                if (i == selected)
                    printf("\033[01;33m > %-10s\033[0m", options[i]);
                else
                    printf("   %-10s", options[i]);
            }

            //안내 메시지 출력
            move_cursor(28, 4);
            printf("\033[1;32mEnter키를 눌러 진행...\033[0m");

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
                    //게임 오버 화면 출력
                    draw_game_over(&player, count);
                    game = 0;
                }

                //선택지를 선택해서 결과가 나오면 다음 scene을 뽑음
                scene = pick_scene();
                //상황 기록에 나왔던 상황인지 체크
                int i = 19;
                for (i = 19; i >= 0; i--) {
                    if (sceneRecord[i].text == scene.text) {
                        scene = pick_scene();
                        i = 19;
                    }
                    else {
                        sceneRecord[i] = scene;
                        break;
                    }
                }

                select = 0;
            }
            //ESC 입력 시
            else if (key == KEY_ESC) {
                draw_pause(&game);
                break;
            }
        }
    }
}

//게임 정보 화면 출력
void draw_info() {
    int info = 1;

    system("cls");

    draw_box(0, 1, 80, 30);

    //로고 출력
    for (int i = 0; i < sizeof(title) / sizeof(title[0]); ++i) {
        print_asciiart_at_location(6 + i, 10, title[i]);
    }

    //게임 정보 출력
    move_cursor(14, 2);
    printf("================================= \033[01;34m게임 정보\033[0m ==================================");
    move_cursor(17, 20);
    printf("당신은 깊은 산 속에서 홀로 조난당했습니다.");
    move_cursor(19, 12);
    printf("탈출을 시도하는 당신의 앞에는 여러 상황이 펼쳐질 것입니다.");
    move_cursor(21, 10);
    printf("당신의 \033[01;31m현명한 판단\033[0m만이 무사히 탈출할 수 있는 유일한 방법입니다.");
        
    //조작법 출력
    move_cursor(24, 2);
    printf("================================= \033[01;34m조작 방법\033[0m ==================================");
    move_cursor(27, 26);
    printf("\033[1;32m←, → : 고르기 | Enter : 선택\033[0m");
    move_cursor(30, 22);
    printf("\033[1m ESC를 누르면 메인 메뉴로 돌아갑니다. \033[0m");

    while (info) {
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


    system("cls");

    draw_box(0, 1, 80, 30);

    //PAUSE 출력
    for (int i = 0; i < sizeof(pauseText) / sizeof(pauseText[0]); ++i) {
        print_asciiart_at_location(6 + i, 28, pauseText[i]);
    }

    move_cursor(15, 21);
    printf("\033[1;31m지금 종료하면 진행 상황이 모두 사라져요!\033[0m");

    //메뉴 박스 출력
    draw_box(33, 20, 15, 6);

    while (pause) {

        for (int i = 0; i < 2; ++i) {
            move_cursor(22+i, 34);
            if (i == selected)
                printf("\033[01;33m > %s\033[0m\n", menus[i]);
            else
                printf("   %s\n", menus[i]);
        }

        move_cursor(23, 41);

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