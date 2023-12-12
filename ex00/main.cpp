/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:33:52 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/12 16:24:13 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void create_tests(void)
{
	std::cout << "Trying to create bureaucrat with 151 grade..."<< std::endl; 
	try
	{
		Bureaucrat ds("DwightShrute", 151);
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "Trying to create bureaucrat with 0 grade..."<< std::endl; 
	try
	{
		Bureaucrat ds("Dwight Shrute", 0);
		std::cout << ds;
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
}


void update_grade_tests(void)
{
	std::cout << "Trying to increment a bureaucrat grade to 0..."<< std::endl; 
	try
	{
		Bureaucrat ms;
		std::cout << ms;
		ms.increment();
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << "Trying to decrement a bureaucrat grade to 151..."<< std::endl; 
	try
	{
		Bureaucrat ds("Dwight Shrute", 150);
		std::cout << ds;
		ds.decrement();
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
}

void bureaucrat_tests(void)
{
	Bureaucrat ms;
	Bureaucrat ds("Dwight Shrute", 150);
	Bureaucrat test(ds);
	ms = ds;
	std::cout << ms;
	std::cout << test << std::endl;
}

int main(void)
{
	bureaucrat_tests();
	create_tests();	
	update_grade_tests();
	return (0);
}
