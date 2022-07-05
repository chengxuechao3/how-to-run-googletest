#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <string>

// API
class DataBaseConnect
{
public:
    virtual bool Login(std::string username, std::string password)
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
        if (dbConnect_.Login(uname, passwd) != true)
        {
            std::cout << "Failed to connect >>>>> " << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Successful Connection >>>>>" << std::endl;
            return 1;
        }
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
};

TEST(MyDBTest, LoginSuccess)
{
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb, Login("who_u_are", "i_do_not_care"))
        .WillOnce(testing::Return(true));

    // Act
    int retValue = db.Init("who_u_are", "i_do_not_care");

    // Assert
    EXPECT_EQ(retValue, 1);
}

TEST(MyDBTest, LoginFailure)
{
    // Arrange
    MockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb, Login("who_u_are", "i_do_not_care"))
        // .Times(testing::AtLeast(2))
        .WillRepeatedly(testing::Return(false));

    // Act
    int retValue = db.Init("who_u_are", "i_do_not_care");

    // Assert
    EXPECT_EQ(retValue, -1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}