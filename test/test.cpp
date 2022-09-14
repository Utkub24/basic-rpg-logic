#include <gtest/gtest.h>
#include "../include/cleric.h"
#include "../include/playercharacter.h"
#include "../include/item_manager.h"

/*TEST(ExampleTest, Guide) {
    EXPECT_TRUE(true); 
    ASSERT_TRUE(true); //Assert stops the tests after a failed test
    EXPECT_EQ(true, true);
}*/

class PlayerTest : public ::testing::Test {
    protected:
        PlayerCharacter player = PlayerCharacter(new Cleric()); // gets rebuilt in each test
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