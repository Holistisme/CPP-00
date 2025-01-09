/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-00/ex01/phonebook/PhoneBook.cpp                 *
*                    Creation Date: January 7, 2025 09:56 PM                     *
*                     Last Updated: January 9, 2025 11:28 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                         Phonebook management functions                         *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

static inline void	displayErrorAndErase(const std::string &error, const size_t &linesToEraze);
static inline bool	isValidID(const std::string &input, const int &contactCount);

/********************************************************************************/

/**
 * @brief Add a contact if there is room in the repertoire or replace the oldest one.
 */
void	PhoneBook::addContact(void) {
	std::cout << getTheme() << "🖀 - Adding a new contact" << RESET << std::endl;

	if (_contactCount < MAX_CONTACTS)
		PhoneBook::_contact[_contactCount++].addContact();
	else {
		std::cout << "The repertoire is " RED "full" RESET "! We will have to separate from the oldest contact, "
			<< BLUE << _oldestSave + 1 << RESET <<"! Are you sure? " << std::endl;
		if (!confirmAction())
			return (erasePreviousLines(2));

		erasePreviousLines(1);
		_contact[_oldestSave].addContact();
		_oldestSave = (_oldestSave + 1) % MAX_CONTACTS;
	}
	erasePreviousLines(11);
}

/**
 * @brief Displays all the contacts to find one in particular.
 * 
 * @return true: if the user has been able to find their contact.
 * @return false: if the directory has no contact or the user has abandoned.
 */
bool	PhoneBook::searchContact(void) const {
	if (!_contactCount) {
		displayErrorAndErase("You don't have (or maybe no more) friends yet!", 5);
		return (false);
	}

	erasePreviousLines(5);
	displayTable();

	while (forever) {
		std::string	input;
		std::cout << "✉ - Select a " BLUE "ID" RESET " you want to see:" << std::endl;
		input = getInputLine();
		trimSpaces(input, false);
		if (isValidID(input, _contactCount)) {
			erasePreviousLines(6 + _contactCount);
			PhoneBook::_contact[input[0] - '1'].displayContact(input[0] - '0');
			std::cout << std::endl;
			return (true);
		}
		displayErrorAndErase("This friend does not yet exist!", 2);
	}
}

/**
 * @brief Check if an input is a valid ID.
 * 
 * @param input user input.
 * @param contactCount The number of contacts currently recorded.
 * @return true: if the ID is in the existing beach.
 * @return false: if the ID is wrong.
 */
static inline bool	isValidID(const std::string &input, const int &contactCount) {
	return (input.length() == 1
		and (std::isdigit(input[0]) and input[0] != '0')
		and input[0] - '1' < contactCount);
}

/**
 * @brief Displays an error and erases the specified lines.
 * 
 * @param error The error message to display.
 * @param linesToEraze The number of lines to be erased.
 */
static inline void	displayErrorAndErase(const std::string &error, const size_t &linesToEraze) {
	erasePreviousLines(1);
	std::cout << ERROR << error << std::endl;
	sleep(1);
	erasePreviousLines(linesToEraze);
}

/**
 * @brief Displays the table of all contacts.
 * 
 */
void	PhoneBook::displayTable(void) const {
	std::cout << getTheme() <<	TABLE_BORDER << std::endl;
	std::cout <<				TABLE_HEADER << std::endl;
	std::cout <<				TABLE_LINE << std::endl;
	for (size_t index = 0; index < _contactCount; index++)
		_contact[index].displaySummary(index);
	std::cout <<				TABLE_BORDER << RESET << std::endl;
}