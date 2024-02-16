#ifndef CONVERTER_JSON_H
#define CONVERTER_JSON_H

#include "pch.h"
#include "document.h"


extern const std::string defaultResourcePath;
extern const std::string defaultRequestsPath;


namespace ConverterJson
{
    std::vector<Document> getTextDocuments(const std::string& resourcePath = defaultResourcePath) noexcept;

    std::vector<std::string> getRequests(const std::string& requestsPath = defaultRequestsPath);

    void putAnswers(const std::vector<std::vector<std::pair<int, float>>>& answers);
};

#endif //CONVERTER_JSON_H
