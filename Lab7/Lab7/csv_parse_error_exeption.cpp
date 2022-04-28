#include "csv_parse_error_exeption.h"

CSVParseErrorExeption::CSVParseErrorExeption(const std::string &msg, const int line_nb)
{
	this->msg = std::string("parse error exception at line ")
			+ std::to_string(line_nb)
			+ std::string(": ")
			+ msg;
}
