#include "gtest/gtest.h"
#include "converter_json.h"


const std::string resourcePath = "../test/test_resources";
const std::string requestsPath = "../test/config/requests.json";


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

