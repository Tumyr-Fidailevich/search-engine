#ifndef CONVERTER_JSON_H
#define CONVERTER_JSON_H

#include "pch.h"
#include "document.h"
#include "relative_index.h"
#include "config.h"


namespace ConverterJson
{
    std::vector<Document> getTextDocuments(const std::string& resourcePath = DEFAULT_RESOURCE_PATH) noexcept;

    std::vector<std::string> getRequests(const std::string& requestsPath = DEFAULT_PATH);

    void putAnswers(const std::vector<std::vector<RelativeIndex>>& answers, const std::string& answersPath = DEFAULT_PATH);
};

#endif //CONVERTER_JSON_H
