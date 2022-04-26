#ifndef PARSEERROREXEPTION_H
#define PARSEERROREXEPTION_H

#include <exception>

struct ParseErrorExeption : public std::exception
{
    const char * what() const throw() override { return "Parse error"; };
};

#endif // PARSEERROREXEPTION_H
