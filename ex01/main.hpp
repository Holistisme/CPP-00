/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-00/ex01/main.hpp                         *
*                   Creation Date: December 20, 2024 11:52 AM                    *
*                    Last Updated: January 10, 2025 12:00 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                          The source of all Phonebook                           *
*********************************************************************************/

#ifndef MAIN_HPP
#define MAIN_HPP

/********************************************************************************/

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <unistd.h>

/********************************************************************************/

typedef int	index;

typedef struct field_mutable {
	std::string	prompt;
	std::string	*data;
} field_mutable;

typedef struct field_const {
	std::string			prompt;
	const std::string	data;
	const std::string	color;
} field_const;

/********************************************************************************/

#include "./output.hpp"
#include "./contact/Contact.hpp"
#include "./phonebook/PhoneBook.hpp"

/********************************************************************************/

bool		confirmAction(void);
void		erasePreviousLines(const size_t &count);
bool		equivalentString(const std::string &first, const std::string &second);
std::string	getInputLine(void);
std::string	getTheme(const std::string &newTheme = "");
void		trimSpaces(std::string &string, const bool &addingAction);

/********************************************************************************/

#define IS_BORDER_LINE(i)			(!(i) or (i) == LINES_TO_DISPLAY - 1)

#define TABLE_BORDER				"|===========================================|"
#define TABLE_HEADER				"|        ID|First Name| Last Name|  Nickname|"
#define TABLE_LINE  				"|----------|----------|----------|----------|"

#define SPACE						' '
#define COLUMN						'|'

#define PROMPT_SIZE					17
#define MINIMUM_FIELD_LENGTH		21

#define MAX_CONTACTS				8
#define CONTACT_FIELDS				5

#define THEME_COUNT					15

#define forever						true

#define LINES_TO_DISPLAY			7
#define	INDEX_COLUMNS_AND_SPACES	5
#define COLUMNS_AND_SPACES			4

#define SIGNAL						'\033'
#define ERROR						BG_RED UNDERLINE "ERROR:" RESET " "

#endif