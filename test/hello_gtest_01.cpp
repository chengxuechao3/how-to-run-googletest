#include <gtest/gtest.h>

TEST(TestName, SubTest_1)
{
    ASSERT_TRUE(1 == 1);
}

TEST(TestName, SubTest_2)
{
    ASSERT_FALSE(1 == 2);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}