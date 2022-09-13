#include <gtest/gtest.h>
#include "cleric.hpp"
#include "playercharacter.hpp"

/*TEST(ExampleTest, Guide) {
    EXPECT_TRUE(true); 
    ASSERT_TRUE(true); //Assert stops the tests after a failed test
    EXPECT_EQ(true, true);
}*/

class PlayerTest : public ::testing::Test {
    protected:
        PlayerCharacter player = new Cleric();
};



TEST_F(PlayerTest, creation) {
    ASSERT_TRUE(&player);
    ASSERT_TRUE(player.getClass());
}


TEST_F(PlayerTest, basestats) {
    ASSERT_EQ(player.getMaxHp(), Cleric::BASEHP);
    ASSERT_EQ(player.getClass()->Str, Cleric::BASESTR);
    ASSERT_EQ(player.getClass()->Int, Cleric::BASEINT);
    ASSERT_EQ(player.getClass()->Dex, Cleric::BASEDEX);

}

TEST_F(PlayerTest, leveling) {
    player.gainExp(100);
    EXPECT_EQ(player.getCurrentLevel(), 2);
}
