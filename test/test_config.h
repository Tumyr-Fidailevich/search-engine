#include "gtest/gtest.h"
#include "config.h"

namespace{
    static const std::string testConfigPath = "../test/config";
}


TEST(ConfigTest, InitRegularCase)
{
    auto config = Config(testConfigPath + "/config.json");

    config.init();

    ASSERT_EQ(config.engineName(), "SearchEngine");
    ASSERT_EQ(config.engineVersion(), "0.1");
    ASSERT_EQ(config.responseLimit(), 5);
}

TEST(ConfigTest, InitEmptyConfigTest)
{
    auto config = Config(testConfigPath + "/empty_config.json");

    ASSERT_THROW(config.init(), std::runtime_error);
}

TEST(ConfigTest, InitNonExistentFileCase)
{
    auto config = Config(testConfigPath + "/non_existent_config.json");

    ASSERT_THROW(config.init(), std::runtime_error);
}