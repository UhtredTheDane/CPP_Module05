/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:57:38 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/13 16:00:54 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Christmas");
		Bureaucrat pb("Pam Beesly", 137);
		pb.signForm(*rrf);
		pb.executeForm(*rrf);
		std::cout << std::endl;
	}

	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat jh("Jim Halpert", 45);
		jh.signForm(*rrf);
		jh.executeForm(*rrf);
		std::cout << std::endl;
	}

	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Dwight Shrut");
		Bureaucrat ms;
		ms.signForm(*rrf);
		ms.executeForm(*rrf);
		std::cout << std::endl;
	}

	return (0);
}
