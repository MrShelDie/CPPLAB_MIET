#ifndef INVALIDDATAEXCEPTION_H
#define INVALIDDATAEXCEPTION_H

#include <nlohmann/json.hpp>
#include <string>

class JSONParseErrorException : public nlohmann::json::parse_error
{
private:
    std::string msg;

public:
    JSONParseErrorException(const std::string &_msg) : msg(_msg) {};

    const char* what() const throw() override;
};

#endif // INVALIDDATAEXCEPTION_H
