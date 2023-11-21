/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:57:38 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/21 18:11:32 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

int main(void)
{
	PresidentialPardonForm f1;
	BureauCrat ms;
	ms.signForm(f1);
	f1.execute(ms);
	return (0);
}
