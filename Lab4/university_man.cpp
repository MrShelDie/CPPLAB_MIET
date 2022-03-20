#include "university_man.h"

UniversityMan::UniversityMan()
	: id(-1),
	  birth_year(-1),
	  full_name(""),
	  sex(NONE),
	  is_empty(true)
{

}

UniversityMan::UniversityMan
(
		int _id,
		int _birth_year,
		const std::string& _full_name,
		e_sex _sex
)
	: id(_id),
	  birth_year(_birth_year),
	  full_name(_full_name),
	  sex(_sex),
	  is_empty(false)
{

}

std::string	UniversityMan::toString() const
{
	return std::to_string(id) + " "
			+ full_name + " "
			+ std::to_string(birth_year)+ " "
			+ std::to_string(sex);
};
