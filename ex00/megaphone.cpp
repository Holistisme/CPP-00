/*********************************************************************************
*                              Author: Alexy Heitz                               *
*                     File Name: /CPP-00/ex00/megaphone.cpp                      *
*                   Creation Date: December 19, 2024 01:02 PM                    *
*                    Last Updated: January 15, 2025 02:11 AM                     *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                   Just to make sure that everybody is awake!                   *
*********************************************************************************/

#include <cctype>
#include <iostream>

/********************************************************************************/

typedef int	index;

/********************************************************************************/

#define	TO_UPPER(c)	static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
#define MAKE_NOISE	"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
#define SPACE		' '

/********************************************************************************/

/**
 * @brief Converts arguments to uppercase and concatenates them into a single string.
 * 
 * @param argc The number of program parameters, including the executable.
 * @param argv The array of arguments.
 * @return int: Should always return "0".
 */
int main(int argc, char *argv[]) {
	try {
		std::string	result = "";

		if (argc > 1) {
			for (index word = 1 ; word < argc ; word++) {
				for (index letter = 0 ; argv[word][letter] ; letter++)
					result += TO_UPPER(argv[word][letter]);
				if (word < argc - 1)
					result += SPACE;
			}
		}
		else
			result = MAKE_NOISE;

		std::cout << result << std::endl;
		return (0);
	}
	catch (...) {
		std::cout << "Error: an allocation for the string failed!" << std::endl;
		return (-1);
	}
}