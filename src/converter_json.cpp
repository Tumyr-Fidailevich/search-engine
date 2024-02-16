#include "converter_json.h"


const std::string defaultResourcePath = "../../resources";
const std::string defaultRequestsPath = "../../config";


std::vector<Document> ConverterJson::getTextDocuments(const std::string& resourcePath) noexcept
{
    if(!std::filesystem::exists(resourcePath)) return {};

    std::vector<Document> results;
    for(const auto& file : std::filesystem::directory_iterator(resourcePath))
    {
        std::ifstream fileStream(file.path());
        if(fileStream.is_open())
        {
            std::string documentValue;
            fileStream >> documentValue;
            results.emplace_back(file.path().filename(), std::move(documentValue));
        }
    }
    return std::move(results);
}

std::vector<std::string> ConverterJson::getRequests(const std::string& requestsPath)
{
    if(!std::filesystem::exists(requestsPath)) throw std::runtime_error("Requests file doesn't exists");

    std::ifstream requestsFileStream(requestsPath);

    if(!requestsFileStream.is_open()) throw std::runtime_error("Can't open requests file");

    nlohmann::json requestsJson;

    requestsFileStream >> requestsJson;
    
    if(!requestsJson.contains("requests")) throw std::runtime_error("Requests file is empty");

    return std::move(requestsJson["requests"]);
}

void ConverterJson::putAnswers(const std::vector<std::vector<std::pair<int, float>>>& answers)
{

}