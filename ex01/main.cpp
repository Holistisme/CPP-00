/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                       File Name: /CPP-00/ex01/main.cpp                         *
*                   Creation Date: December 20, 2024 09:24 AM                    *
*                     Last Updated: January 9, 2025 11:59 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*         Program that behaves like a crappy awesome phonebook software          *
*********************************************************************************/

#include "./main.hpp"

/********************************************************************************/

/**
 * @brief Initializes a theme if the user indicates their will.
 * 
 * @param argc The number of program arguments.
 * @param argv Program arguments.
 */
void	setTheme(int argc, char *argv[]) {
	const std::string	availableTheme[] = { "cobalt", "iron", "electric",
		"aquamarine", "spring", "heliotrope", "incarnat", "snow", "gold",
		"duke", "leek", "lilac", "blood", "silver", "copper" };
	const std::string	ANSI_Theme[] = { BG_BLUE, BG_BRIGHT_BLACK, BG_BRIGHT_BLUE,
		BG_BRIGHT_CYAN, BG_BRIGHT_GREEN, BG_BRIGHT_MAGENTA, BG_BRIGHT_RED, READABLE_BG_BRIGHT_WHITE,
		BG_BRIGHT_YELLOW, BG_CYAN, BG_GREEN, BG_MAGENTA, BG_RED, BG_WHITE, BG_YELLOW };

	if (argc > 1) {
		std::string	argument(argv[1]);
		trimSpaces(argument, false);

		if (equivalentString(argument, "--setThemeOn")) {
			index	randomI = std::rand() % 15;

			if (argc > 2) {
				std::string	theme(argv[2]);
				trimSpaces(theme, false);

				for (index i = 0 ; i < THEME_COUNT ; i++) {
					if (equivalentString(theme, availableTheme[i])) {
						getTheme(ANSI_Theme[i]);
						return;
					}
				}
				std::cout << "> " << YELLOW << theme << RESET << " is not yet an available theme." << std::endl;
			}
			else
				std::cout << "> " << "Specify a theme for your visual pleasure!" << std::endl;
			std::cout << "> " << "Try something like " << ANSI_Theme[randomI] << availableTheme[randomI] << RESET << "!" << std::endl;
			sleep(3);
			erasePreviousLines(2);
		}
		else if (argc > 1 and !argument.empty()) {
			std::cout << "> " << YELLOW << argv[1] << RESET << " is not yet an available feature." << std::endl;
			std::cout << "> " << "Try something like " << YELLOW << "\"--setThemeOn\"" << RESET << '!' << std::endl;
			sleep(3);
			erasePreviousLines(2);
		}
	}
}

/**
 * @brief Program to have your own telephone agenda!
 * 
 * @param argc Useful for activating additional features.
 * @param argv Features and settings of these.
 * @return int: Normally, success.
 */
int main(int argc, char *argv[]) {
	PhoneBook	phonebook;
	bool		displayed = false;

	std::srand(std::time(0));
	setTheme(argc, argv);

	while (forever) {
		std::string	input;

		std::cout << getTheme()	<< "Choose the action to be performed:" << RESET << std::endl;
		std::cout << "🕼  - "	<< GREEN	<< "ADD"	<< RESET << std::endl;
		std::cout << "👁  - "	<< BLUE		<< "SEARCH"	<< RESET << std::endl;
		std::cout << "🗴  - "	<< RED		<< "EXIT"	<< RESET << std::endl;

		input = getInputLine();
		trimSpaces(input, false);

		if (equivalentString(input, "ADD")) {
			if (displayed) {
				erasePreviousLines(8);
				displayed = false;
			}
			erasePreviousLines(5);
			phonebook.addContact();
		}
		else if (equivalentString(input, "SEARCH")) {
			if (displayed) {
				erasePreviousLines(8);
				displayed = false;
			}
			displayed = phonebook.searchContact();
		}
		else if (equivalentString(input, "EXIT")) {
			if (displayed) {
				erasePreviousLines(8);
				displayed = false;
			}
			erasePreviousLines(5);
			std::cout << "✆ Thank you for using " + getTheme() + "My Awesome PhoneBook™" RESET "! ✆" << std::endl;
			return (EXIT_SUCCESS);
		}
		else {
			erasePreviousLines(1);
			std::cout << ERROR << "Unknown instruction, if you are drunk, avoid the phone while driving!" << std::endl;
			sleep(1);
			erasePreviousLines(5);
			if (displayed) {
				erasePreviousLines(8);
				displayed = false;
			}
		}
	}
}