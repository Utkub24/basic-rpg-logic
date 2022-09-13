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


// Don't bother with this shit rn

TEST_F(PlayerTest, creation) {
    ASSERT_TRUE(&player);
    ASSERT_TRUE(player.getClass());
}

TEST_F(PlayerTest, leveling) {
    player.gainExp(100);
    EXPECT_EQ(player.getCurrentLevel(), 2);
}
