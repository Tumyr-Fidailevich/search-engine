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

TEST(ConverterJsonTest, PutAnswerRegularCase)
{
    std::string testPath = configPath + "/answers.json";

    std::vector<std::vector<RelativeIndex>> answers = {
                                                        {{0, 0.989}, {1, 0.897}, {2, 0.750}, {3, 0.670}, {4, 0.561}}, 
                                                        {{0, 0.769}}, 
                                                        {}};

    nlohmann::json answersJson = ConverterJson::putAnswers(answers, testPath);

    nlohmann::json expected = R"({
                                    "answers": {
                                        "request001": {
                                            "result": true,
                                            "relevance": [
                                                {"doc_id": 0, "rank" : "0.989"},
                                                {"doc_id": 1, "rank" : "0.897"},
                                                {"doc_id": 2, "rank" : "0.750"},
                                                {"doc_id": 3, "rank" : "0.670"},
                                                {"doc_id": 4, "rank" : "0.561"}
                                            ]
                                        },
                                        "request002": {
                                            "result": true,
                                            "relevance": [
                                                {"doc_id": 0, "rank" : "0.769"}
                                            ]
                                        },
                                        "request003": {
                                            "result": false
                                        }
                                    }
                                })"_json;

    ASSERT_EQ(answersJson, expected);
}