#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

enum e_sex
{
	MALE,
	FEMALE,
	NONE
};

class Employee
{
private:
	unsigned int	id;
	unsigned int	birth_year;
	std::string		full_name;
	e_sex			sex;
	bool			is_empty;

public:
	Employee();
	Employee
	(
		unsigned int id,
		unsigned int birth_year,
		std::string full_name,
		e_sex sex
	);

	unsigned int getId() const { return id; };
	unsigned int getBirthYear() const { return birth_year; };
	std::string getFullName() const { return full_name; };
	e_sex getSex() const { return sex; };

	bool isEmpty() const { return is_empty; };
};

#endif // EMPLOYEE_H
