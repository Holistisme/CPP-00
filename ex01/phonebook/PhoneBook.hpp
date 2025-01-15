/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-00/ex01/phonebook/PhoneBook.hpp                 *
*                   Creation Date: December 20, 2024 11:48 AM                    *
*                     Last Updated: January 9, 2025 03:39 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                      Definition of the “PhoneBook” class                       *
*********************************************************************************/

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "./../main.hpp"
#include "./../contact/Contact.hpp"

/**
 * @brief The class containing up to eight contacts!
 * 
 */
class	PhoneBook {
	private:
		Contact	_contact[8];
		size_t	_contactCount;
		index	_oldestSave;
	public:
		PhoneBook(void);
		bool		searchContact(void) const;
		void		addContact(void);
		void		displayTable(void) const;
};

#endif