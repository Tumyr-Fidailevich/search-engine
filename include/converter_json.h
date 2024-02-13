#ifndef CONVERTER_JSON_H
#define CONVERTER_JSON_H


#include <iostream>
#include <vector>
#include "nlohmann/json.hpp"
#include "boost/filesystem.hpp"


class ConverterJson
{
public:
    ConverterJson() = default;

    std::vector<std::string> getTextDocuments();

    int getResponsesLimit();

    std::vector<std::string> getRequests();

    void putAnswers(std::vector<std::vector<std::pair<int, float>>>answers);

private:

};

#endif //CONVERTER_JSON_H
