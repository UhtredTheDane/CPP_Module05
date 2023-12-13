/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:57:12 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/11 17:19:05 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("Shrubbery", 145, 137),
	target("Unknow")
{
	std::cout << "ShrubberyCreationForm's default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: AForm("Shrubbery", 145, 137),
	target(target)
{
	std::cout << "ShrubberyCreationForm's constructor called" << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& toCopy)
	: AForm(toCopy)
{
	std::cout << "ShrubberyCreationForm's copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm's destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& toAffect)
{
	std::cout << "ShrubberyCreationForm's copy assignement operator called" << std::endl;
	(void) toAffect;
	return (*this);
}

void ShrubberyCreationForm::makeExecute(void) const
{
	std::string file_name;

	file_name = this->target;
	file_name.append("_shrubbery");
	std::cout << "File " << file_name << " created" << std::endl;
	std::ofstream stream(file_name.c_str());
	stream	<< "      /\\\n"
			<< "     /\\*\\\n"    
			<< "    /\\O\\*\\\n"    
			<< "   /*/\\/\\/\\\n" 
			<< "  /\\O\\/\\*\\/\\\n" 
			<< " /\\*\\/\\*\\/\\/\\\n"
			<< "/\\O\\/\\/*/\\/O/\\\n"
			<< "      ||\n"
			<< "      ||\n"
			<< "      ||\n";	    
}
