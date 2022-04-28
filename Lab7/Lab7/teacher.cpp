#include "teacher.h"

Teacher::Teacher()
	: subject(""),
	  department("")
{

}

Teacher::Teacher
(
		const std::string& _subject,
		const std::string& _department)
	: subject(_subject),
	  department(_department)
{

}

std::string Teacher::toString() const
{
	return UniversityMan::toString() + " "
			+ subject + " "
			+ department;
}
