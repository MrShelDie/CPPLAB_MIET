#ifndef INVALIDDATAEXCEPTION_H
#define INVALIDDATAEXCEPTION_H

#include <exception>
#include <string>

class JSONParseErrorException : public std::exception
{
private:
    std::string msg;

public:
	JSONParseErrorException(const std::string &msg, int id);

	const char* what() const throw() override { return this->msg.c_str(); };
};

#endif // INVALIDDATAEXCEPTION_H
