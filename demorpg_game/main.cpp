#include <iostream>
#include "../demorpg_lib/include/playercharacter.h"

char the_map[12][13] = {
    "############",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "#----------#",
    "############",
};

struct Player {
    Player() = delete;
    //Player(PlayerCharacter* player)
    //    : player(player) {}
        
    PlayerCharacter player;
    int xpos = 3;
    int ypos = 3;
    int prev_xpos = 3;
    int prev_ypos = 3;
} mister;

void UpdatePlayerPos() {
    if(((mister.xpos == mister.prev_xpos) && (mister.ypos = mister.prev_ypos)))
        return;

    // if not wall
    if(the_map[mister.xpos][mister.ypos] != '#') {
        // draw player
        the_map[mister.xpos][mister.ypos] = '@';
        the_map[mister.prev_xpos][mister.prev_ypos] = '-';

        // update current location to be previous before next update
        mister.prev_xpos = mister.xpos;
        mister.prev_ypos = mister.ypos;
    } else {
        mister.xpos = mister.prev_xpos;
        mister.ypos = mister.prev_ypos;
    }
}


void ShowMap() {
    system("clear");
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 13; j++) {
            std::cout << the_map[i][j];
       }
       std::cout << "\n";
    }
}


int main(int argc, char** argv) {
    bool running = true;

    std::cout << "\n press enter\n";
    while(running) {
        char c = getchar();

        switch(c) {
            case 'w':
                mister.xpos--;
                break;
            case 'a':
                mister.ypos--;
                break;
            case 's':
                mister.xpos++;
                break;
            case 'd':
                mister.ypos++;
                break;

            default:
                break;
        }
        
        UpdatePlayerPos();
        ShowMap();
    
    }

    return 0;
}