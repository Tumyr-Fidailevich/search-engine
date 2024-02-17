#include "gtest/gtest.h"
#include "converter_json.h"


const std::string resourcePath = "../test/test_resources";
const std::string configPath = "../test/config";


TEST(ConverterJsonTest, getTextDocumentsRegularCase)
{
    auto documents = ConverterJson::getTextDocuments(resourcePath);

    std::vector<Document> expected{{"file001.txt", "milk sugar salt"}, 
                                    {"file002.txt", "milk a milk b milk c milk d"}};

    ASSERT_EQ(documents, expected);
}

TEST(ConverterJsonTest, getTextDocumentsEmptyResourcesCase)
{
    std::string testPath = resourcePath + "/empty";
    auto documents = ConverterJson::getTextDocuments(testPath);

    std::vector<Document> expected{};

    ASSERT_EQ(documents, expected);
}

TEST(ConverterJsonTest, getTextDocumentsNonExistentDirectoryCase)
{
    std::string testPath = resourcePath + "/test";
    auto documents = ConverterJson::getTextDocuments(testPath);

    std::vector<Document> expected{};

    ASSERT_EQ(documents, expected);
}

TEST(ConverterJsonTest, getRequestsRegularCase)
{
    std::string testPath = configPath + "/requests.json";
    auto requests = ConverterJson::getRequests(testPath);

    std::vector<std::string> expected{"some words", "some other words"};

    ASSERT_EQ(requests, expected);
}

TEST(ConverterJsonTest, getRequestsEmptyRequestsCase)
{
    std::string testPath = configPath + "/empty_requests.json";

    ASSERT_THROW(ConverterJson::getRequests(testPath), std::runtime_error);
}

TEST(ConverterJsonTest, getRequestsNonExistentDirectoryCase)
{
    std::string testPath = configPath + "/non_existent.json";

    ASSERT_THROW(ConverterJson::getRequests(testPath), std::runtime_error);
}