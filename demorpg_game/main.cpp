#include <iostream>
#include "main.h"
#include "../demorpg_lib/include/cleric.h"
#include "../demorpg_lib/include/random.h"
#include "../demorpg_lib/include/item.h"
#include "../demorpg_lib/include/item_manager.h"

Player* guy = nullptr;
Enemy* enemi = nullptr;

Item* DropRandomItem() {
    int drop_seed = Random::NTK(1, 100);
    Item* dropped_item = nullptr;
    if(drop_seed < 51) {
        dropped_item = HPPOT; 
    } else {
        switch(Random::NTK(1,2)) {
            case 1:
                dropped_item = ItemManager::CreateArmor("Iron Helm", StatBlock(2, 0, 0, 3, 2), ARMORSLOT::HELMET);
                break;
            case 2:
                dropped_item = ItemManager::CreateWeapon("Bronze Sword", StatBlock(), 3, 8, WEAPONSLOT::ONEHAND, WEAPONTYPE::MELEE);
                break;
        }
    }
    
    return dropped_item;
}

void CreateMonster(Enemy* in_out, const Player* base_calc) {
    if(!base_calc) return;
    if(in_out) { delete in_out; in_out = nullptr;}

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

void UseAbilityInFight(Player& fightingPlayer) {
    std::vector<Ability> playerAbilities = fightingPlayer.player->getClass()->Abilities;
    int l = 0;
    std::cout << "----Abilites----\n";
    for(auto a : playerAbilities) std::cout << l++ << ": " << a.name << std::endl;
    std::cout << "Choose ability: ";
    std::cin.clear();
    std::cin.ignore(100, '\n');
    int i;
    std::cin >> i;
    if(i < playerAbilities.size()) {
        const Ability* chosen_ability = &playerAbilities.at(i);
        switch(chosen_ability->target) {
            case ABILITYTARGET::SELF:
                // Assume a healing ability for now
                fightingPlayer.player->increaseHp(chosen_ability->effectVal);
                break;
            case ABILITYTARGET::ENEMY:
                if(enemi->isAlive()) enemi->monster.HP.reduce(chosen_ability->effectVal);
                break;
            default:
                break;
        }
    } else return;
}

void ViewInventory(Player& fightingPlayer) {
    std::cout << "----Inventory Contents----" << std::endl;
    int l = 0;
    for(auto i : fightingPlayer.player->getInventory()) std::cout << l++ << ") " << i->getData()->name << std::endl;
    std::cout << "(x to  exit)\n";
    while (getchar() != 'x') {}
   
}



void EnterFight(Player& fightingPlayer) {
    int turn = 1;
    if(!enemi) return;
    std::vector<Item*> playerInv = fightingPlayer.player->getInventory();
    std::vector<Ability> playerAbilites = fightingPlayer.player->getClass()->Abilities;
    std::vector<Item*>::iterator hp_pot_it = std::find(playerInv.begin(), playerInv.end(), HPPOT);

    while(fightingPlayer.player->isAlive() && enemi->isAlive()) {
        system("clear");
        std::cout << "P          vs          M\n";
        printf("HP:  %d/%d               %d/%d\n",fightingPlayer.player->getCurrentHp(), fightingPlayer.player->getMaxHp(), enemi->monster.HP.getCurrent(), enemi->monster.HP.getMax());
        std::cout << "Turn: "<< turn << std::endl;
        //if(MP)
        std::cout << "\n\nChoose action (a: Attack, h: Heal, A: Ability, i:  Inventory)\n";
        std::cin.clear();
        std::cin.ignore(100, '\n');
        char action = getchar();
        switch(action) {
            case 'a':
                enemi->monster.HP.reduce(fightingPlayer.player->getAttackVal());
                if(enemi->isAlive()) fightingPlayer.player->reduceHp(enemi->monster.getAttackVal());
                turn++;
                break;
            
            case 'h':
                if(hp_pot_it != playerInv.end()) {
                    //use item from inventory and heal player
                    ItemManager::Use(*hp_pot_it, fightingPlayer.player);
                    fightingPlayer.player->increaseHp(6);
                    if(enemi->isAlive()) fightingPlayer.player->reduceHp(enemi->monster.getAttackVal());
                }
                turn++;
                break;
            case 'A':
                UseAbilityInFight(fightingPlayer);
                turn++;
                break;
            case 'i':
                ViewInventory(fightingPlayer);
                break;    

            default:
                //std::cout << "\nChoose a valid action!\n";
                break;
        }
    }

    if(fightingPlayer.player->isAlive()) {
        Item* dropped_item = DropRandomItem();

        std::cout << "You defeated the monster!\n";
        std::cout << "EXP Gained: " << enemi->xp_worth << "\n";
        fightingPlayer.player->gainExp(enemi->xp_worth);

        if(dropped_item) {
            ItemManager::MoveToInventory(dropped_item, fightingPlayer.player);
            std::cout << "Item recieved: " << dropped_item->getData()->name << std::endl;
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
