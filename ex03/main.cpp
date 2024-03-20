#include "Intern.hpp"

int main() {
	Intern		intern;
	Bureaucrat	john("John", 1);
	AForm		*sc(intern.makeForm("shrubbery creation", "sc"));
	AForm		*rr(intern.makeForm("robotomy request", "rr"));
	AForm		*pp(intern.makeForm("presidential pardon", "pp"));

	intern.makeForm("Nothing", "Nothing");

	john.signForm(*sc);
	john.signForm(*rr);
	john.signForm(*pp);

	john.executeForm(*sc);
	john.executeForm(*rr);
	john.executeForm(*pp);

	delete sc;
	delete rr;
	delete pp;
}
