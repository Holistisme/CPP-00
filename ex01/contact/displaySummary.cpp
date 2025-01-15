/*********************************************************************************
*                              Author: Alexy Heitz                               *
*              File Name: /CPP-00/ex01/contact/displaySummary.cpp                *
*                    Creation Date: January 7, 2025 12:14 AM                     *
*                    Last Updated: January 15, 2025 02:22 PM                     *
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

	std::cout << COLUMN << cutField(oss.str()) << COLUMN
		<< cutField(_firstName) << COLUMN
		<< cutField(_lastName) << COLUMN
		<< cutField(_nickName) << COLUMN << std::endl;
}

/**
 * @brief Cuts the field at the tenth character, adding a dot if it exceeds the limit.
 * 
 * @param field The field to process.
 * @return std::string: the processed field, cut at 10 characters if necessary.
 */
static inline std::string	cutField(const std::string &field) {
	std::string	cuttedField = "";
	size_t		length = 0;

	for (size_t index = 0 ; field[index] ; index++) {
		if (length == 9 and field[index + 1]) {
			cuttedField += '.';
			break;
		}
		if (field[index] == '\t') {
			if (length < 6) {
				cuttedField += "    ";
				length += 4;
			}
			else {
				while (length++ < 9)
					cuttedField += SPACE;
				cuttedField += '.';
				break;
			}
		}
		else {
			++length;
			cuttedField += field[index];
		}
	}
	if (length < 10) {
		std::string	result(10 - cuttedField.length(), SPACE);
		result += cuttedField;
		return (result);
	}
	return (cuttedField);
}