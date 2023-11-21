/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:56:20 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/21 18:03:04 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string& target);
		RobotomyRequestForm(RobotomyRequestForm const& toCopy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& toAffect);
		void execute(BureauCrat const& executor) const;
	private:
		std::string target;
		
};
#endif
