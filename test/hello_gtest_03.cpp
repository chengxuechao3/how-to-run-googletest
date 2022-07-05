#include <gtest/gtest.h>

// 1. Arrange : Arranage all the preconditions needed to run the tests
// 2. Act : Run the test
// 3. Assert : Verify the Test result (expected or otherwise)

TEST(EasyTest, SubTest_1)
{
    // Arrange
    int value = 100;
    int increment = 5;

    // Act
    value = value + increment;

    // Assert
    ASSERT_EQ(value, 105);
}

class MyClass
{
public:
    MyClass(std::string id) : id_(id) {}
    std::string id() { return id_; }

private:
    std::string id_;
};

TEST(ClassTest, SubTest_1)
{
    // Arrange
    MyClass jordan("23");

    // Act
    std::string id = jordan.id();

    // Assert
    ASSERT_EQ(id, "23"); // depend on the compile we use, this test can be successful or failure
    ASSERT_STREQ(id.c_str(), "23");
}

// list string assertions
// ASSERT_STR* / EXPECT_STR*
//
// EQ - Equal
// NE - Not Equal
// CASEEQ - Ignore case Equal
// CASENE - Ignore case Not Equal

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}