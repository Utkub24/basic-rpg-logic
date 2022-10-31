#include <iostream>
#include "main.h"
#include "../demorpg_lib/include/cleric.h"
#include "../demorpg_lib/include/random.h"
#include "../demorpg_lib/include/item.h"
#include "../demorpg_lib/include/item_manager.h"

Player* guy = nullptr;
Enemy* enemi = nullptr;

Item* DropRandomItem(const Player* base_calc) {
    int drop_seed = Random::NTK(1, 100);
    if(drop_seed < 51) {
        ItemManager::CreatePotion("Healing Potion", new Effect(), 1);
    } else {
        switch(Random::NTK(1,2)) {
            case 1:
                ItemManager::CreateArmor("Iron Helm", StatBlock(2, 0, 0, 3, 2), ARMORSLOT::HELMET);
                break;
            case 2:
                ItemManager::CreateWeapon("Bronze Sword", StatBlock(), 3, 8, WEAPONSLOT::ONEHAND, WEAPONTYPE::MELEE);
                break;
        }
    }

}

void CreateMonster(Enemy* in_out, const Player* base_calc) {
    if(!base_calc) return;
    if(in_out) { delete in_out; in_out == nullptr;}

    int min_hp = base_calc->player->getCurrentLevel() * 2;
    int max_hp = base_calc->player->getCurrentLevel() * 8;

    int min_dmg = base_calc->player->getCurrentLevel();
    int max_dmg = base_calc->player->getCurrentLevel() * 2;

    in_out = new Enemy(Random::NTK(min_hp, max_hp), min_dmg, max_dmg);

    in_out->xpos = Random::NTK(1, 11);
    in_out->ypos = Random::NTK(1, 11);
    while(the_map[in_out->xpos][in_out->ypos] == '@' || the_map[in_out->xpos][in_out->ypos] == '#') {
        in_out->xpos = Random::NTK(1, 11);
        in_out->ypos = Random::NTK(1, 11);
    }
    the_map[in_out->xpos][in_out->ypos] = 'M';
    enemi = in_out;
}




void EnterFight(Player& fightingPlayer) {
    if(!enemi) return;

    while(fightingPlayer.player->isAlive() && enemi->isAlive()) {
        system("clear");
        std::cout << "P          vs          M\n";
        printf("HP:  %d/%d               %d/%d\n",fightingPlayer.player->getCurrentHp(), fightingPlayer.player->getMaxHp(), enemi->monster.HP.getCurrent(), enemi->monster.HP.getMax());
        //if(MP)
        std::cout << "\n\nChoose action (a: attack, h: heal)\n";
        char action = getchar();
        switch(action) {
            case 'a':
                enemi->monster.HP.reduce(fightingPlayer.player->getAttackVal());
                if(enemi->isAlive())
                    fightingPlayer.player->reduceHp(enemi->monster.getAttackVal());
                break;
            
            case 'h':
                if(std::binary_search(fightingPlayer.player->getInventory().begin(), fightingPlayer.player->getInventory().end(), "Healing Potion")) {
                }
                if(enemi->isAlive())
                    fightingPlayer.player->reduceHp(enemi->monster.getAttackVal());
                break;

            default:
                //std::cout << "\nChoose a valid action!\n";
                break;
        }

    }

    if(fightingPlayer.player->isAlive()) {
        Item* drop = DropRandomItem(&fightingPlayer);

        std::cout << "You defeated the monster!\n";
        std::cout << "EXP Gained: " << enemi->xp_worth << "\n";
        fightingPlayer.player->gainExp(enemi->xp_worth);

        if(drop) {
            ItemManager::MoveToInventory(drop, fightingPlayer.player);
            std::cout << "Item recieved: " << drop->getData()->name << std::endl;
        }

        the_map[enemi->xpos][enemi->ypos] = '-';
        CreateMonster(enemi, &fightingPlayer);
    } else {
        std::cout << "You were defeated...\n";
    }
    std::cout << "\nPress Enter to Continue\n";
    std::cin.ignore(10, '\n');
    char a = getchar();

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

    CreateMonster(enemi, guy);
    the_map[enemi->xpos][enemi->ypos] = 'M';

    ShowMap();
    printf("EXP: %d/%d", guy->player->getCurrentExp(), guy->player->getExpForNextLevel());

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
        if(guy->player->isAlive()) {
            ShowMap();
            printf("EXP: %d/%d\n", guy->player->getCurrentExp(), guy->player->getExpForNextLevel());
        } else {
            break;
        }

    }

    return 0;
}