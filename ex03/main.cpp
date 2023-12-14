/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:57:38 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/14 13:23:00 by agengemb         ###   ########.fr       */
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
		delete rrf;
	}
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat jh("Jim Halpert", 45);
		jh.signForm(*rrf);
		jh.executeForm(*rrf);
		std::cout << std::endl;
		delete rrf;
	}
	{
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Dwight Shrut");
		Bureaucrat ms;
		ms.signForm(*rrf);
		ms.executeForm(*rrf);
		std::cout << std::endl;
		delete rrf;
	}
	{
		AForm* rrf;
		try
		{
			rrf = someRandomIntern.makeForm("presidential", "Dwight Shrut");
			Bureaucrat ms;
			ms.signForm(*rrf);
			ms.executeForm(*rrf);
			std::cout << std::endl;
			delete rrf;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	return (0);
}
