#include <gtest/gtest.h>

class MyClass
{
public:
    MyClass(int base_value) : base_value_(base_value) {}

    void Increment(int increment_by)
    {
        base_value_ += increment_by;
    }

    int getValue() { return base_value_; }

private:
    int base_value_;
};

class MyClassTest : public testing::Test
{
public:
    MyClassTest() { std::cout << "1111" << std::endl; }
    ~MyClassTest() { std::cout << "2222" << std::endl; }
    virtual void SetUp()
    {
        std::cout << "set up " << std::endl;
        mc = new MyClass(100);
    }

    virtual void TearDown()
    {
        std::cout << "tear down " << std::endl;
        delete mc;
    }

    MyClass *mc;
};

TEST_F(MyClassTest, Increment_by_5)
{
    mc->Increment(5);
    EXPECT_EQ(mc->getValue(), 105);
}

TEST_F(MyClassTest, Increment_by_10)
{
    mc->Increment(10);
    EXPECT_EQ(mc->getValue(), 110);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}