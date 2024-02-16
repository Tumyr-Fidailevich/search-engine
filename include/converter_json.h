#ifndef CONVERTER_JSON_H
#define CONVERTER_JSON_H

#include "pch.h"
#include "document.h"


namespace ConverterJson
{
    std::vector<Document> getTextDocuments() noexcept;

    std::vector<std::string> getRequests();

    void putAnswers(const std::vector<std::vector<std::pair<int, float>>>& answers);
};

#endif //CONVERTER_JSON_H
