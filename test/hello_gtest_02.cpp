#include <gtest/gtest.h>

// success assertions
TEST(TestName, TestUseSuccessAssertion)
{
    EXPECT_TRUE(1 == 1);
    EXPECT_FALSE(1 == 2);

    ASSERT_TRUE(1 == 1);
    ASSERT_FALSE(1 == 2);
}

// no-fatal assertions
TEST(TestName, TestUseNoFatalAssertion)
{
    std::cout << "hello I' here at line " << __LINE__ << std::endl;
    EXPECT_TRUE(1 == 2);
    std::cout << "hello I' here at line " << __LINE__ << std::endl;
    EXPECT_FALSE(1 == 2);
    std::cout << "hello I' here at line " << __LINE__ << std::endl;
}

// fatal_assertions
TEST(TestName, TestUseFatalAssertion)
{
    std::cout << "hello I' here at line " << __LINE__ << std::endl;
    ASSERT_TRUE(1 == 2);
    std::cout << "hello I' here at line " << __LINE__ << std::endl;
    ASSERT_FALSE(1 == 2);
    std::cout << "hello I' here at line " << __LINE__ << std::endl;
}

// list of comparision assertions
// ASSERT_* / EXPERT_*
//
// EQ - Equal
// NE - Not Equal
// LT - Less Than
// GT - Greater Than
// LE - Less Than Equal
// GE - Greater Than Equal

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}