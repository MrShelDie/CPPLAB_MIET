#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

enum e_sex
{
	MALE,
	FEMALE,
	NONE
};

class UniversityMan
{
private:
	int				id;
	int				birth_year;
	std::string		full_name;
	e_sex			sex;

	bool			is_empty;

public:
	UniversityMan();
	UniversityMan (
		int id,	int birth_year,
		const std::string &_full_name, e_sex sex
	);

	int			getId()			const { return id;			};
	int			getBirthYear()	const { return birth_year;	};
	std::string getFullName()	const { return full_name;	};
	e_sex		getSex()		const { return sex;			};

	bool		isEmpty()		const { return is_empty;	};

	std::string	toString()		const;
};

#endif // EMPLOYEE_H
