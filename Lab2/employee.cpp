#include "employee.h"

Employee::Employee()
{
	id = 0;
	birth_year = 0;
	full_name = "default name";
	sex = NONE;
	is_empty = true;
}

Employee::Employee
(
	unsigned int _id,
	unsigned int _birth_year,
	std::string _full_name,
	e_sex _sex
) :
	id(_id),
	birth_year(_birth_year),
	full_name(_full_name),
	sex(_sex)
{
	is_empty = false;
}
