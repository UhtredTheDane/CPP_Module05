/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:33:52 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/11 18:55:36 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void create_tests(void)
{
	try
	{
		Form f("Registration", -1, 150);
	}
	catch(std::exception& e)
	{	
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Form f("Registration", 1, 151);
	}
	catch(std::exception& e)
	{	
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

}

int main(void)
{
	create_tests();
	Form f1;
	std::cout << f1 << std::endl;
	Bureaucrat ms;
	ms.signForm(f1);
	std::cout << std::endl;
	
	ms.signForm(f1);
	std::cout << std::endl;

	Form f2("Housing", 149, 149);
	std::cout << f2 << std::endl;
	Bureaucrat ds("Dwight Shrute", 150);
	ds.signForm(f2);
	std::cout << f2 << std::endl << std::endl;

	return (0);
}
