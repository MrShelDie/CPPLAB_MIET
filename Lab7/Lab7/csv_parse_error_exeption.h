#ifndef PARSEERROREXEPTION_H
#define PARSEERROREXEPTION_H

#include <string>
#include <exception>

class CSVParseErrorExeption : public std::exception
{
private:
    std::string msg;

public:
	CSVParseErrorExeption(const std::string &msg, const int line_nb);

	const char* what() const throw() override { return msg.c_str(); };
};

#endif // PARSEERROREXEPTION_H
