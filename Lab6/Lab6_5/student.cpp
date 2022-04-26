#include "student.h"

Student::Student()
	: course(-1),
	  specialization("")
{

}

Student::Student
(
		int _course,
		const std::string& _specialization
)
	: course(_course),
	  specialization(_specialization)
{

}

std::string Student::toString() const
{
	return UniversityMan::toString() + " "
			+ std::to_string(course) + " "
			+ specialization;
}
