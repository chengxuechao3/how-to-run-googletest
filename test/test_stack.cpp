#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "stack.h"

class MockArrayStack : public ArrayStack
{
public:
    //012 represents the number of parameters a method will take
    MOCK_METHOD1(Push, bool(int data));
    MOCK_METHOD0(capacity, std::size_t());
};

class ArrayStackTest : public testing::Test
{
public:
    virtual void SetUp()
    {
        std::cout << "Tearing Up..." << std::endl;
    }

    virtual void TearDown()
    {
        std::cout << "Tearing Down..." << std::endl;
    }
};

TEST_F(ArrayStackTest, DefaultConstructorTest)
{
    ArrayStack array_stack;
    ASSERT_EQ(array_stack.top_next(), 0);
    ASSERT_EQ(array_stack.capacity(), 0);
}

TEST_F(ArrayStackTest, CustomConstructorTest)
{
    ArrayStack array_stack(10);
    ASSERT_EQ(array_stack.top_next(), 0);
    ASSERT_EQ(array_stack.capacity(), 10);
}

TEST_F(ArrayStackTest, PushSuccessTest)
{
    MockArrayStack mac;
    EXPECT_CALL(mac, Push(testing::_))
        .WillRepeatedly(testing::Return(false));

    ArrayStack array_stack(10);

    for (int i = 0; i < 10; ++i)
    {
        array_stack.Push(i);
    }

    std::cout << "----" << mac.Push(1) << std::endl;

    ASSERT_EQ(array_stack.capacity(), 10);
    ASSERT_EQ(array_stack.top_next(), 10);
}

TEST_F(ArrayStackTest, PopSuccessTest)
{
    ArrayStack array_stack(10);

    for (int i = 0; i < 10; ++i)
    {
        array_stack.Push(i);
    }

    for (int value = 10; value > 0; --value)
    {
        ASSERT_EQ(array_stack.Pop(), value - 1);
    }
}

TEST_F(ArrayStackTest, PushFailureTest)
{
    ArrayStack array_stack(10);

    for (int i = 0; i < 10; ++i)
    {
        array_stack.Push(i);
    }

    ASSERT_ANY_THROW(array_stack.Push(10));
}

TEST_F(ArrayStackTest, PopFailureTest)
{
    ArrayStack array_stack(10);

    for (int i = 0; i < 10; ++i)
    {
        array_stack.Push(i);
    }

    for (int value = 10; value > 0; --value)
    {
        array_stack.Pop();
    }

    ASSERT_ANY_THROW(array_stack.Pop());
}
