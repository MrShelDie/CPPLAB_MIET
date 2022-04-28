#include "json_parse_error_exception.h"

JSONParseErrorException::JSONParseErrorException(const std::string &msg, int id)
{
	this->msg = std::string("Object id ")
			+ std::to_string(id)
			+ std::string(" parse error: ")
			+ msg;
}
