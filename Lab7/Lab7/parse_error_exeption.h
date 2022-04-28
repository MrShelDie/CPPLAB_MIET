#ifndef PARSEERROREXEPTION_H
#define PARSEERROREXEPTION_H

#include <string>
#include <exception>

class ParseErrorExeption : public std::exception
{
private:
    std::string msg;
    int         line_nb;

public:
    ParseErrorExeption(const std::string &_msg, const int _line_nb)
        : msg(_msg),
          line_nb(_line_nb) {};

    const char* what() const throw() override;
};

#endif // PARSEERROREXEPTION_H
