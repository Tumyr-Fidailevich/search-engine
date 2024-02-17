#ifndef CONFIG_H
#define CONFIG_H

#include "pch.h"


extern const std::string DEFAULT_RESOURCE_PATH;
extern const std::string DEFAULT_REQUESTS_PATH;
extern const std::string DEFAULT_ANSWERS_PATH;
extern const std::string DEFAULT_CONFIG_PATH;


class Config
{
public:
    Config(const std::filesystem::path& configPath) noexcept : _configPath(configPath) {}

    void init();

    std::string engineName();

    std::string engineVersion();

    int responseLimit();

private:
    std::filesystem::path _configPath;
    int _responseLimit;
    std::string _engineName;
    std::string _engineVersion;
};

#endif // CONFIG_H