#pragma once
#include "../demorpg_lib/include/playercharacter.h"
#include "../demorpg_lib/include/monster.h"

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


struct Entity {
    int xpos, ypos;
    int prev_xpos, prev_ypos;
    bool exists = true;
    void setPos(int x, int y) {
        xpos = x;
        ypos = y;
    }
};


struct Player : public Entity {
    Player() = delete;
    Player(PlayerCharacter* p) 
        : player(p) {
            this->setPos(3, 3);
            prev_xpos = xpos;
            prev_ypos = ypos;
        }
        
    PlayerCharacter* player;
};

struct Enemy : public Entity {
    Enemy() = delete;
    Enemy(int hp, int minDmg, int maxDmg)
        : monster(hp, minDmg, maxDmg), xp_worth((hp + minDmg + maxDmg)*2) {}
    int xp_worth;

    Monster monster;
    bool isAlive() { return (monster.HP.getCurrent() > 0); }

};