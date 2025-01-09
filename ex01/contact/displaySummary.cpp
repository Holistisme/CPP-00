/*********************************************************************************
*                              Author: Alexy Heitz                               *
*              File Name: /CPP-00/ex01/contact/displaySummary.cpp                *
*                    Creation Date: January 7, 2025 12:14 AM                     *
*                     Last Updated: January 9, 2025 11:20 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                       Quick customer display management                        *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

static inline std::string	cutField(const std::string &field);

/********************************************************************************/

/**
 * @brief Displays a quick summary of all contacts.
 * 
 * @param i Contact index (0-based).
 */
void	Contact::displaySummary(const index &i) const {
	std::ostringstream	oss;	oss << i + 1;

	std::cout << COLUMN << std::setw(10) << cutField(oss.str()) << COLUMN
		<< std::setw(10) << cutField(_firstName) << COLUMN
		<< std::setw(10) << cutField(_lastName) << COLUMN
		<< std::setw(10) << cutField(_nickName) << COLUMN << std::endl;
}

/**
 * @brief Cuts the field at the tenth character, adding a dot if it exceeds the limit.
 * 
 * @param field The field to process.
 * @return std::string: the processed field, cut at 10 characters if necessary.
 */
static inline std::string	cutField(const std::string &field) {
	std::string	cuttedField = field;

	if (field.length() > 10)
		return (field.substr(0,9) + ".");
	return (field);
}