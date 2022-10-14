#include <gtest/gtest.h>
#include "../demorpg_lib/include/cleric.h"
#include "../demorpg_lib/include/playercharacter.h"
#include "../demorpg_lib/include/item_manager.h"
#include "../demorpg_lib/include/monster.h"

/*TEST(ExampleTest, Guide) {
    EXPECT_TRUE(true); 
    ASSERT_TRUE(true); //Assert stops the tests after a failed test
    EXPECT_EQ(true, true);
}*/

class PlayerTest : public ::testing::Test {
    protected:
        PlayerCharacter player{new Cleric()}; // gets rebuilt in each test
        virtual void SetUp() override {}
        virtual void TearDown() override {}
};


class EffectTest : public ::testing::Test {
    protected:
        Effect* bumba = new Effect("Bumba", 2, 5, -5, -1, 0, 10);
};

class ItemTest : public ::testing::Test {
    protected:
        Item* IronHelm = ItemManager::CreateArmor("Iron Helmet", StatBlock(0, 0, 0, 6, 0), ARMORSLOT::HELMET);
        Item* BronzeSword = ItemManager::CreateWeapon("Bronze Sword", StatBlock(), 5, 8, WEAPONSLOT::ONEHAND, WEAPONTYPE::MELEE);
        Item* BumbaPot = ItemManager::CreatePotion("Bumba Potion", new Effect("Bumba", 2, 5, -5, -1, 0, 10), 1);
        virtual void SetUp() override {}
        virtual void TearDown() override {}
        friend class PlayerTest;
};

class MonsterTest : public ::testing::Test {
    protected:
        Monster* monki = new Monster(10, 2, 4);

};

class SimpleBattleTest : public ::testing::Test {
    protected:
        PlayerCharacter p1{new Cleric()};
        Monster mon1{10, 2, 4};
        
};

// Don't bother with this shit rn

TEST_F(PlayerTest, creation) {
    ASSERT_TRUE(&player);
    ASSERT_TRUE(player.getClass());
    ASSERT_EQ(player.getClass()->Abilities.size(), 2);
    ASSERT_TRUE(player.getEffects().empty());
    ASSERT_TRUE(player.getInventory().empty()); // vector.empty() returns true if size is 0


    ASSERT_EQ(player.getClass()->Str, Cleric::BASESTR);
    ASSERT_EQ(player.getClass()->Int, Cleric::BASEINT);
    ASSERT_EQ(player.getClass()->Dex, Cleric::BASEDEX);
    ASSERT_EQ(player.getClass()->PhysArmor, 0);
    ASSERT_EQ(player.getClass()->MagicArmor, 0);
    ASSERT_EQ(player.getClass()->HP.getCurrent() , Cleric::BASEHP);
    ASSERT_EQ(player.getClass()->HP.getMax() , Cleric::BASEHP);
    ASSERT_EQ(((Cleric*)player.getClass())->MP.getCurrent() , Cleric::BASEMP);
    ASSERT_EQ(((Cleric*)player.getClass())->MP.getMax() , Cleric::BASEMP);


}

TEST_F(PlayerTest, leveling) {
    player.gainExp(567);
    EXPECT_EQ(player.getCurrentLevel(), 4);
    EXPECT_EQ(player.getCurrentExp(), 567);
    ASSERT_EQ(player.getClass()->Abilities.size(), 3); 

    ASSERT_EQ(player.getClass()->Str, 15);
    ASSERT_EQ(player.getClass()->Int, 14);
    ASSERT_EQ(player.getClass()->Dex, 5);
    ASSERT_EQ(player.getClass()->PhysArmor, 0);
    ASSERT_EQ(player.getClass()->MagicArmor, 0);
    ASSERT_EQ(player.getClass()->HP.getCurrent(), 40);
    ASSERT_EQ(player.getClass()->HP.getMax(), 40);
    ASSERT_EQ(((Cleric*)player.getClass())->MP.getCurrent(), 40);
    ASSERT_EQ(((Cleric*)player.getClass())->MP.getMax(), 40);

}

TEST_F(PlayerTest, items) {

}

TEST_F(MonsterTest, creation) {
    ASSERT_EQ(10, monki->HP.getMax());
    ASSERT_EQ(10, monki->HP.getCurrent());
    ASSERT_EQ(2, monki->getMinDamage());
    ASSERT_EQ(4, monki->getMaxDamage());

}

TEST_F(MonsterTest, RANDOMNESS) {
    int damage_val = 0;
    for(int i = 0; i++; i < 100) {
        damage_val = monki->getAttackVal();
        ASSERT_TRUE((damage_val <= monki->getMaxDamage()) && (damage_val >= monki->getMinDamage()));

    }
}

TEST_F(MonsterTest, HP_MANIPULATION) {
    monki->HP.reduce(5);
    ASSERT_EQ(monki->HP.getMax() - 5, monki->HP.getCurrent());

    monki->HP.increase(5);
    ASSERT_EQ(monki->HP.getMax(), monki->HP.getCurrent());

    monki->HP.reduce(monki->HP.getMax() + 1);
    ASSERT_EQ(0, monki->HP.getCurrent());
    
    monki->HP.increase(monki->HP.getMax() + 1);
    ASSERT_EQ(monki->HP.getMax(), monki->HP.getCurrent());
}

TEST_F(SimpleBattleTest, DUMB_FIGHT) {
    ItemManager::Equip(ItemManager::CreateWeapon("Bronze Mace", StatBlock(), 3, 6, WEAPONSLOT::ONEHAND, WEAPONTYPE::MELEE), &p1);

    while((mon1.HP.getCurrent() > 0) && (p1.getCurrentHp() > 0)) {
        mon1.HP.reduce(p1.getAttackVal());
        p1.reduceHp(mon1.getAttackVal());
    }

    ASSERT_EQ(mon1.HP.getCurrent(), 0);
}