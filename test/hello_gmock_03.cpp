#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <string>
#include <random>
#include <ctime>

// API
class DataBaseConnect
{
public:
    virtual bool Login(std::string username, std::string password)
    {
        return true;
    }
    virtual bool Login2(std::string username, std::string password)
    {
        return true;
    }
    virtual bool Logout(std::string username)
    {
        return true;
    }
    virtual int FetchRecord()
    {
        return -1;
    }
};

// MyOwn class need to use API
class MyDatabase
{
public:
    MyDatabase(DataBaseConnect &dbc) : dbConnect_(dbc) {}

    int Init(std::string uname, std::string passwd)
    {
        // std::default_random_engine generator(time(NULL));
        // std::uniform_int_distribution<> distribution(0, 1);

        // if (distribution(generator) == 1)
        {
            if (dbConnect_.Login(uname, passwd) != true)
            {
                std::cout << "Failed to connect >>>>> " << std::endl;
                // u need do sth to make login success.
                if (dbConnect_.Login(uname, passwd) != true)
                {
                    std::cout << "Failed to connect twice >>>>> " << std::endl;
                    return -1;
                }
                else
                {
                    std::cout << "Successful Connection Use Login >>>>>" << std::endl;
                    return 1;
                }
            }
            else
            {
                std::cout << "Successful Connection Use Login >>>>>" << std::endl;
                return 1;
            }
        }
        // else
        // {
        //     std::cout << "Successful Connection Use Login2 >>>>>" << std::endl;
        //     return (dbConnect_.Login2(uname, passwd) == true);
        // }
    }

private:
    DataBaseConnect &dbConnect_;
};

class MockDB : public DataBaseConnect
{
public:
    //012 represents the number of parameters a method will take
    MOCK_METHOD0(FetchRecord, int());
    MOCK_METHOD1(Logout, bool(std::string uname));
    MOCK_METHOD2(Login, bool(std::string uname, std::string passwd));
    MOCK_METHOD2(Login2, bool(std::string uname, std::string passwd));
};

class MyDBTest : public testing::Test
{
};

TEST_F(MyDBTest, LoginTestLoginSuccess)
{
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);

    // EXPECT_CALL(mdb, Login("who_u_are", "i_do_not_care"))
    //     .Times(1)
    //     .WillOnce(testing::Return(true));

    // _ means u don't bother what is the parameter
    EXPECT_CALL(mdb, Login(testing::_, testing::_))
        // .Times(2)
        .WillOnce(testing::Return(false))
        .WillOnce(testing::Return(true));

    // use WillRepeatedly
    // EXPECT_CALL(mdb, Login(testing::_, testing::_))
    //     .WillRepeatedly(testing::Return(true));

    // Act
    // int retValue = db.Init("who_u_are", "i_do_not_care");

    // when u input wrong username and password
    int retValue = db.Init("who_u_are", "i_do_not_careblalba");

    // Assert
    EXPECT_EQ(retValue, 1);
}

TEST_F(MyDBTest, LoginTestLoginFailure)
{
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);

    // use Times(testing::AtLeast(2))
    EXPECT_CALL(mdb, Login(testing::_, testing::_))
        .WillRepeatedly(testing::Return(false));

    // Act
    int retValue = db.Init("who_u_are", "i_do_care");

    // Assert
    EXPECT_EQ(retValue, -1);
}

// TEST(MyDBTest, LoginTestUseOnCall)
// {
//     // Arrange
//     MockDB mdb;
//     MyDatabase db(mdb);

//     // Similar to EXPECT_CALL, ON_CALL can also be used to set the
//     // expectation, but there is a difference, ON_CALL tells the
//     // test, what to do when the function is called, but doesn't
//     // enforce that the function must be called for the test to pass.
//     ON_CALL(mdb, Login(testing::_, testing::_))
//         .WillByDefault(testing::Return(true));

//     ON_CALL(mdb, Login2(testing::_, testing::_))
//         .WillByDefault(testing::Return(true));

//     // Act
//     int retValue = db.Init("who_u_are", "i_do_care");

//     // Assert
//     EXPECT_EQ(retValue, 1);
// }

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}