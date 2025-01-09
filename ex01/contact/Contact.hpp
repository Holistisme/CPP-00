/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                  File Name: /CPP-00/ex01/contact/Contact.hpp                   *
*                   Creation Date: December 19, 2024 05:40 PM                    *
*                     Last Updated: January 9, 2025 11:26 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                       Definition of the “Contact” class                        *
*********************************************************************************/

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "./../main.hpp"

/**
 * @brief Set of contact data recorded in the Phonebook.
 * 
 */
class	Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
	public:
		void 	addContact(void);
		void 	displayContact(const index &i) const;
		void 	displaySummary(const index &i) const;
		size_t	getLongestField(void) const;
};

#endif