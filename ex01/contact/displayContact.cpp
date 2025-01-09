/*********************************************************************************
*                              Author: Alexy Heitz                               *
*              File Name: /CPP-00/ex01/contact/displayContact.cpp                *
*                   Creation Date: December 19, 2024 05:47 PM                    *
*                     Last Updated: January 9, 2025 10:50 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        Contact data display management                         *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

static inline void			displayField(const field_const &field, const size_t &longestLine);
static inline std::string	getRandomLine(const index &i, const size_t &longestLine);

/********************************************************************************/

/**
 * @brief Displays a contact in detail, including its fields and styling.
 * 
 * This function manages the detailed display of a contact, ensuring
 * proper alignment, formatting, and styling. Keep an eye out for
 * unexpected behavior from Rick—just saying!
 * 
 * @param i The contact index to display (0-based).
 */
void	Contact::displayContact(const index &i) const {
	const size_t	longestLine = getLongestField();
	field_const		field[]= {
		{ getTheme() + "|",						getRandomLine(i, longestLine),	"" },
		{ BG_RED		"|   First name   :" RESET,	_firstName,						RED },
		{ BG_BLUE		"|   Last name    :" RESET,	_lastName,						BLUE },
		{ BG_GREEN		"|   Nick name    :" RESET,	_nickName,						GREEN },
		{ BG_YELLOW		"|  Phone number  :" RESET,	_phoneNumber,					YELLOW },
		{ BG_MAGENTA	"| Darkest secret :" RESET,	_darkestSecret,					MAGENTA },
		{ getTheme() + "|",						getRandomLine(0, longestLine),	"" },
	};

	for (index i = 0; i < LINES_TO_DISPLAY; i++)
		displayField(field[i], IS_BORDER_LINE(i) ? PROMPT_SIZE + longestLine : longestLine);
	if (_darkestSecret == "Never Gonna Give You Up") {
		#ifdef __linux__
			system("xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ > /dev/null 2>&1");
		#elif _WIN32
			system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ > nul 2>&1");
		#elif __APPLE__
			system("open https://www.youtube.com/watch?v=dQw4w9WgXcQ > /dev/null 2>&1");
		#endif
	}
}

/**
 * @brief Returns the size of the longest field of contact.
 * 
 * This function iterates through all the contact's fields and calculates 
 * the length of the longest string.
 * 
 * @return size_t: the length of the longest string in the contact's fields.
 */
size_t	Contact::getLongestField(void) const {
	size_t		currentLongest = 0;
	std::string	data[] = { _firstName, _lastName, _nickName, _phoneNumber, _darkestSecret };

	for (index i = 0 ; i < CONTACT_FIELDS ; i++) {
		const size_t	currentLength = data[i].length();
		if (currentLength > currentLongest)
			currentLongest = currentLength;
	}
	return (currentLongest);
}

/**
 * @brief Displays the field centered within the longest line.
 * 
 * This function calculates the necessary spaces before and after the data 
 * to center it relative to the longest line.
 * 
 * @param field The field to display.
 * @param longestLine The length of the longest line for alignment.
 */
static inline void	displayField(const field_const &field, const size_t &longestLine) {
	const size_t	dataLength = field.data.length();
	const size_t	effectiveLongestLine = (dataLength > longestLine) ? dataLength : longestLine;

	const size_t	spaceCountBefore = ((effectiveLongestLine - field.data.length()) / 2) + 1;
	const size_t	spaceCountAfter = effectiveLongestLine - field.data.length() - spaceCountBefore + 2;

	std::string		spaceBefore(spaceCountBefore, SPACE);
	std::string		spaceAfter(spaceCountAfter, SPACE);

	if (!field.color.empty())
		std::cout << field.prompt << field.color << spaceBefore << field.data << spaceAfter << COLUMN << RESET << std::endl;
	else
		std::cout << field.prompt << spaceBefore << field.data << spaceAfter << COLUMN << RESET << std::endl;
}

/**
 * @brief Chooses a random sentence for the first or the last line.
 * 
 * @param i The index of the contact concerned, put to 0 to obtain the last line.
 * @param longestLine The longest line, useful to check that the sentence does not exceed.
 * @return std::string: the line offered.
 */
static inline std::string	getRandomLine(const index &i, const size_t &longestLine) {
	index			randomI = std::rand() % 10;
	const size_t	maximumLineLength = MINIMUM_FIELD_LENGTH + longestLine;
	std::string firstLine[] = { "Here's your star: ", "Ready to shine: ", "Say hello to ",
		"Spotlight on ", "Your VIP: ", ", the chosen one.", "Lights on for ", "Drumroll for ",
		", at your fingertips.", ", just for you."
	};
    const std::string lastLine[] = { "All wrapped up.", "Show's over.", "That's a wrap!",
		"Curtain call.", "That's the scoop.", "Mystery solved.", "Done and dusted.", "File closed.",
		"No secrets left.", "Case closed.",
    };
	
	if (i) {
		std::ostringstream		oss; oss << i;
		std::string indexString	= oss.str();

		while (firstLine[randomI].length() + INDEX_COLUMNS_AND_SPACES >= maximumLineLength)
			randomI = std::rand() % 10;
		if (randomI == 5 or randomI == 8 or randomI == 9)
			return (indexString + firstLine[randomI]);
		return (firstLine[randomI] + indexString);
	}
	while (lastLine[randomI].length() + COLUMNS_AND_SPACES >= maximumLineLength)
		randomI = std::rand() % 10;
	return (lastLine[randomI]);
}