#include "config.h"

const int DEFAULT_RESPONSE_LIMIT = 5;
const std::string DEFAULT_RESOURCE_PATH = "../resources";
const std::string DEFAULT_REQUESTS_PATH = "../config/requests.json";
const std::string DEFAULT_ANSWERS_PATH = "../config/answers.json";
const std::string DEFAULT_CONFIG_PATH = "../config/config.json";


void Config::init()
{
    if(!std::filesystem::exists(_configPath)) throw std::runtime_error("Config file is missing");
    std::ifstream configFileStream(_configPath);

    if(!configFileStream.is_open()) throw std::runtime_error("Cannot open config file");

    nlohmann::json configJson;

    configFileStream >> configJson;

    configFileStream.close();
    
    if(!configJson.contains("config")) throw std::runtime_error("Config file is empty");

    if(!configJson["config"].contains("name")) std::cerr << "Can't find engine name, set to undefined" << std::endl;
    if(!configJson["config"].contains("version")) std::cerr << "Can't find engine version, set to undefined" << std::endl;
    if(!configJson["config"].contains("name")) std::cerr << "Can't find max reponse limit, set to default" << std::endl;

    _engineName = configJson["config"].value("name", "undefined");
    _engineVersion = configJson["config"].value("version", "undefined");
    _responseLimit = configJson["config"].value("max_responses", DEFAULT_RESPONSE_LIMIT);
}

std::string Config::engineName()
{
    return _engineName;
}

std::string Config::engineVersion()
{
    return _engineVersion;
}

int Config::responseLimit()
{
    return _responseLimit;
}