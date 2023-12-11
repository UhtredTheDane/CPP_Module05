/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:53:45 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/11 19:02:38 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: name("Certificate"),
	is_signed(false),
	grade_to_sign(1),
	grade_to_exec(1)
{
	std::cout << "Form's default constructor called" << std::endl;
}


Form::Form(Form const& toCopy)
	: name(toCopy.name),
	is_signed(toCopy.is_signed),
	grade_to_sign(toCopy.grade_to_sign),
	grade_to_exec(toCopy.grade_to_exec)
{
	std::cout << "Form's copy constructor called" << std::endl;
}

Form::Form(std::string const& name, int const grade_to_sign, int const grade_to_exec)
	: name(name),
	grade_to_sign(grade_to_sign),
	grade_to_exec(grade_to_exec)
{
	this->is_signed = false;
	std::cout << "Form's constructor called" << std::endl;
	if (grade_to_sign < 1 || grade_to_exec < 1)
		throw (Form::GradeTooHighException());
	else if (grade_to_sign > 150 || grade_to_exec > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form(void)
{
	std::cout << "Form's destructor called" << std::endl;
}

Form& Form::operator=(Form const& toAffect)
{
	std::cout << "Form's copy assignement operator called" << std::endl;
	if (this != &toAffect)
		this->is_signed = toAffect.is_signed;
	return (*this);
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > grade_to_sign)
		throw (Form::GradeTooLowException());
	else if (this->is_signed)
		throw (Form::IsAlreadySigned());
	else
		this->is_signed = true;
		
}

int Form::getGradeToSign(void) const
{
	return (grade_to_sign);
}

int Form::getGradeToExec(void) const
{
	return (grade_to_exec);
}

bool Form::getIsSigned(void) const
{
	return (is_signed);	
}

std::string const& Form::getName(void) const
{
	return (name);
}

std::ostream& operator<<(std::ostream &flux, Form const& b)
{
	flux << b.getName() << " needs grade " << b.getGradeToSign() << " for sign and grade "
		<< b.getGradeToExec() << " for execute, it is ";
	if (b.getIsSigned())
		std::cout << "signed";
	else
		std::cout << "not signed";
	return (flux);
}

const char* Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high for this form");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low for this form");
}

const char* Form::IsAlreadySigned::what(void) const throw()
{
	return ("it's already signed");
}
