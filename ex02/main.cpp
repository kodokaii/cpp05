#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat				steve("Steve", 3);
	Bureaucrat				john("John", 148);
	RobotomyRequestForm		rr("rr");
	PresidentialPardonForm	pp("pp");
	ShrubberyCreationForm	sc("sc");

	steve.executeForm(rr);
	steve.executeForm(pp);
	steve.executeForm(sc);

	john.signForm(rr);
	john.signForm(pp);
	john.signForm(sc);

	steve.signForm(rr);
	steve.signForm(pp);
	steve.signForm(sc);

	john.executeForm(rr);
	john.executeForm(pp);
	john.executeForm(sc);

	steve.executeForm(rr);
	steve.executeForm(pp);
	steve.executeForm(sc);
}
