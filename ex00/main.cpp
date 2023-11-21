/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:33:52 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/20 15:38:49 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		BureauCrat ms;
		std::cout << ms;
		ms.increment();
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		BureauCrat ds("Dwight Shrute", 150);
		std::cout << ds;
		ds.decrement();	
	}
	catch (std::exception const& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	BureauCrat ms;
	BureauCrat ds("Dwight Shrute", 150);
	ms = ds;
	std::cout << ms << std::endl;
	return (0);
}
