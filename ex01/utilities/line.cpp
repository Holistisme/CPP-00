/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                   File Name: /CPP-00/ex01/utilities/line.cpp                   *
*                    Creation Date: January 7, 2025 11:29 PM                     *
*                     Last Updated: January 9, 2025 11:41 PM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                        Functions for manipulating lines                        *
*********************************************************************************/

#include "./../main.hpp"

/********************************************************************************/

/**
 * @brief Recover a line from standard input and handle EOF or errors gracefully.
 * 
 * This function ensures proper handling of EOF (CTRL-D) and returns a clean string input.
 * 
 * @return std::string: The line read.
 */
std::string	getInputLine(void) {
	std::string	input;

	std::getline(std::cin, input);

	if (std::cin.eof()) {
		std::cout << BG_RED "Confirmed CTRL-D:" RESET RED " exit: " RESET
			"Thank you for using " + getTheme() + "My Awesome PhoneBook™" RESET "!" << std::endl;
		exit(EXIT_SUCCESS);
	}
	else if (std::cin.fail()) {
		std::cerr << ERROR "An error occurred while reading input." << std::endl;
		sleep(1);
		erasePreviousLines(1);
		std::cin.clear();
        input = "";
	}

	return (input);
}

/**
 * @brief Erase the previous `count` lines from the terminal.
 * 
 * This function uses the ANSI escape sequence defined in `ERASE_LINE` 
 * to clear the specified number of lines from the terminal output.
 * 
 * @param count The number of lines to erase.
 */
void	erasePreviousLines(const size_t &count) {
	std::string	eraseInstructions = "";

	for (size_t index = 0 ; index < count ; index++)
		eraseInstructions += ERASE_LINE;

	std::cout << eraseInstructions << std::flush << MOVE_CURSOR_UP << std::endl;
}