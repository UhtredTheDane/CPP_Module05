/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:57:38 by agengemb          #+#    #+#             */
/*   Updated: 2023/12/11 17:20:16 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

int main(void)
{
	PresidentialPardonForm f1;
	Bureaucrat ms;
	ms.signForm(f1);
	f1.execute(ms);
	return (0);
}
