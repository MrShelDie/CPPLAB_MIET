#include "research_associate.h"

ResearchAssociate::ResearchAssociate()
{

}

ResearchAssociate::ResearchAssociate
(
		const std::string& _post,
		const std::string& _researchScope
)
	: post(_post),
	  research_scope(_researchScope)
{

}

std::string ResearchAssociate::toString() const
{
	return UniversityMan::toString() + " "
			+ post + " "
			+ research_scope;
}
