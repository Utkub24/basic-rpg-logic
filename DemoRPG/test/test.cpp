#include <gtest/gtest.h>
#include "cleric.hpp"
#include "playercharacter.hpp"

/*TEST(ExampleTest, Guide) {
    EXPECT_TRUE(true); 
    ASSERT_TRUE(true); //Assert stops the tests after a failed test
    EXPECT_EQ(true, true);
}*/

TEST(ClericTest, creation) {
    PlayerCharacter p1(new Cleric());
    ASSERT_TRUE(&p1);
    p1.gainExp(100);
    ASSERT_EQ(p1.getCurrentLevel(), 2);
}
