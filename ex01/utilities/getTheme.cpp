/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                 File Name: /CPP-00/ex01/utilities/getTheme.cpp                 *
*                    Creation Date: January 8, 2025 05:28 PM                     *
*                     Last Updated: January 9, 2025 11:40 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                            Theme feature management                            *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

/**
 * @brief Manage the current theme of the PhoneBook.
 * 
 * If a new theme is provided, it validates and applies it.
 * Returns the current theme.
 * 
 * @param newTheme If specified, changes the theme if valid.
 * @return std::string: ANSI code of the current theme.
 */
std::string	getTheme(const std::string &newTheme) {
	static std::string	theme = BG_BLACK;
	
	if (!newTheme.empty())
		theme = newTheme;
	return (theme);
}