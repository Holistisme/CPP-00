/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                File Name: /CPP-00/ex01/contact/addContact.cpp                  *
*                    Creation Date: January 6, 2025 11:46 AM                     *
*                     Last Updated: January 9, 2025 10:49 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                           Data collection management                           *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

static inline void			addInformation(field_mutable &field);
static inline std::string	getMessage(const std::string &field);

/********************************************************************************/

/**
 * @brief Adds contact, field after field.
 * 
 * This function iterates through the predefined fields of the contact and 
 * uses addInformation() to request user input for each field.
 */
void	Contact::addContact(void) {
	field_mutable field[CONTACT_FIELDS] = {
		{"first name",		&_firstName},
		{"last name",		&_lastName},
		{"nick name",		&_nickName},
		{"phone number",	&_phoneNumber},
		{"darkest secret",	&_darkestSecret}};

	for (index i = 0 ; i < CONTACT_FIELDS ; ++i)
		addInformation(field[i]);
}

/**
 * @brief User requests to add information to a contact.
 * 
 * Refuses invalid inputs such as safety characters (e.g., arrow keys) 
 * and empty fields for security purposes. Stops the program in case of CTRL-D.
 * If spaces before and/or after the field are detected, proposes to remove them.
 * 
 * @param field The field to add.
 */
static inline void	addInformation(field_mutable &field) {
	do {
		std::cout << "➣ Please enter the " << CYAN << field.prompt << RESET << ":" << std::endl;
		*field.data = getInputLine();
		if (field.data->find(SIGNAL) != std::string::npos) {
			std::cout << getMessage("signal") << std::endl;
			field.data->clear();
			sleep(1);
			erasePreviousLines(3);
		}
		else if (field.data->empty()) {
			std::cout << getMessage(field.prompt) << std::endl;
			sleep(1);
			erasePreviousLines(3);
		}
	}	while (field.data->empty());
	trimSpaces(*field.data, true);
}

/**
 * @brief Generates an error message, and bind it to the field in question.
 * 
 * If the field is replaced by or "signal", the message returned will follow
 * a more protocol-like structure. For other fields, it generates a personalized 
 * error message linked to the provided field name.
 * 
 * @param field The field (or instruction) to be linked.
 * @return std::string A personalized error message for the terminal.
 */
static inline std::string	getMessage(const std::string &field) {
	erasePreviousLines(1);
	if (field == "signal")
		return (ERROR "My awesome Phonebook does not yet capture Linux signals, only the 3G!\n"
			RED "Invalid input detected (arrow keys not allowed)!" RESET);
	else
		return (ERROR "If you get Alzheimer's, how could you remember the "
			YELLOW + field + RESET " of this contact?\n"
			RED "The field must be complete!" RESET);
}