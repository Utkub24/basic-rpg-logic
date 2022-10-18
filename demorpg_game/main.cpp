#include <iostream>
#include "main.h"
#include "../demorpg_lib/include/cleric.h"
#include "../demorpg_lib/include/random.h"

Player* guy = nullptr;
Enemy* enemi = nullptr;


void EnterFight(Player& fightingPlayer) {
    if(!enemi)
        return;

    while(fightingPlayer.player->isAlive() && enemi->isAlive()) {
        system("clear");
        std::cout << "P          vs          M\n";
        printf("HP:  %d/%d               %d/%d\n",fightingPlayer.player->getCurrentHp(), fightingPlayer.player->getMaxHp(), enemi->monster.HP.getCurrent(), enemi->monster.HP.getMax());
        //if(MP)
        printf("HP:  %d/%d               %d/%d\n",fightingPlayer.player->getCurrentHp(), fightingPlayer.player->getMaxHp(), enemi->monster.HP.getCurrent(), enemi->monster.HP.getMax());

    }

}

void UpdatePlayerPos(Player& player) {
    if(player.xpos == player.prev_xpos && player.ypos == player.prev_ypos)
        return;

    // if not wall
    switch(the_map[player.xpos][player.ypos]) {
        case '#':
            player.xpos = player.prev_xpos;
            player.ypos = player.prev_ypos;
            break;
        case 'M':
            EnterFight(player);
            break;
        default:
            // draw player
            the_map[player.xpos][player.ypos] = '@';
            the_map[player.prev_xpos][player.prev_ypos] = '-';
            // update current location to be previous before next update
            player.prev_xpos = player.xpos;
            player.prev_ypos = player.ypos;
            break;

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
    guy = new Player(new PlayerCharacter(new Cleric()));
    the_map[guy->xpos][guy->ypos] = '@';

    enemi = new Enemy(Random::NTK(4, 6), 2, 4);
    enemi->setPos(5, 10);
    the_map[enemi->xpos][enemi->ypos] = 'M';

    ShowMap();

    while(running) {
        char c = getchar();

        switch(c) {
            case 'w':
                guy->xpos--;
                break;
            case 'a':
                guy->ypos--;
                break;
            case 's':
                guy->xpos++;
                break;
            case 'd':
                guy->ypos++;
                break;

            default:
                break;
        }
        std::cin.clear();
        UpdatePlayerPos(*guy);
        ShowMap();
    }

    return 0;
}