#include "invalid_data_exception.h"

const char* InvalidDataException::what() const throw()
{
    return (msg.c_str());
}
