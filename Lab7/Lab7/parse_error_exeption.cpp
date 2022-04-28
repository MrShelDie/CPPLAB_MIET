#include "parse_error_exeption.h"

const char* ParseErrorExeption::what() const throw()
{
    std::string text =
            std::string("Line ")
            + std::to_string(line_nb)
            + std::string(": ")
            + std::string(msg);
    return (text.c_str());
}
