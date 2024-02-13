#include <iostream>
#include "gtest/gtest.h"

TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}


int main(int argc, char* argv[])
{
    testing::InitGoogleTest();
    RUN_ALL_TESTS();
    return 0;
}