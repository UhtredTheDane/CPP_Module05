/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agengemb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 18:56:57 by agengemb          #+#    #+#             */
/*   Updated: 2023/11/21 18:02:51 by agengemb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string& target);
		PresidentialPardonForm(PresidentialPardonForm const& toCopy);
		~PresidentialPardonForm(void);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& toAffect);
		virtual void execute(BureauCrat const& executor) const;	
	
	private:
		std::string target;
};
#endif
