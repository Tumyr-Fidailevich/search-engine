#include "converter_json.h"


static const std::string resourcePath = "../../resources";
static const std::string requestsPath = "../../config";


std::vector<Document> ConverterJson::getTextDocuments() noexcept
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

std::vector<std::string> ConverterJson::getRequests()
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