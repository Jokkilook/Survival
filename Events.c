#include "Events.h"
#include "Data.h"
#include "stdlib.h"
#include "time.h"

//상황 데이터베이스
const Scene scenes[20] = {
    {
        "    .--.              .--.\n"
        "   : (\\ \". _......_ .\" /) :\n"
        "    '.    `        `    .'\n"
        "     /'   _        _   `\\\n"
        "    /     0}      {0     \\\n"
        "   |       /      \\       |\n"
        "   |     /'        `\\     |\n"
        "    \\   | .  .==.  . |   /\n"
        "     '._ \\\'. \\__/ ./\\ _.'\n"
        "     /  ``'._-''-_.'``  \\\n",
        "테스트 상황",
        {
            {"도망간다", run},
            {"숨는다", run},
            {"죽은 척", run}
        }
    },
};

//저장된 scenes 중 하나를 랜덤하게 뽑는 함수
Scene pick_scene()
{   
    int count = 0;
    while (scenes[count].screen != NULL) {
        ++count;
    }

    srand(time(NULL));
    int index = rand() % count;

    return scenes[index];
}

void run(Player* player) {
	player->SP -= 10;
}