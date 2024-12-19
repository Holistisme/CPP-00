/*********************************************************************************
*                              Author: Alexy Heitz                               *
*               File Name: /home/aheitz/CPP-00/ex00/megaphone.cpp                *
*                   Creation Date: December 19, 2024 12:35 PM                    *
*                    Last Updated: December 19, 2024 03:38 PM                    *
*                              Source Language: cpp                              *
*                                                                                *
*                            --- Code Description ---                            *
*                   Just to make sure that everybody is awake!                   *
*********************************************************************************/

/********************************************************************************/

#include <cctype>
#include <iostream>

typedef int				index;
typedef char			*string;

#define	TO_UPPER(c)		static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
#define WRITE_SPACE		std::cout << " ";
#define WRITE_NEWLINE	std::cout << std::endl;
#define MAKE_NOISE		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;

/********************************************************************************/

/**
 * @brief Referring the arguments as a sentence in capital letters.
 * 
 * @param argc The number of program parameters, in addition to the executable.
 * @param argv The table of character strings, with the executable and the arguments.
 * @return Will always return "EXIT_SUCCESS"
 */
int main(int argc, char *argv[]) {
	index word = 1;

	if (argc > 1) {
		while (argv[word]) {
			index letter = 0;

			while (argv[word][letter])
				std::cout << TO_UPPER(argv[word][letter++]);
			if (argv[++word])
				WRITE_SPACE;
		}
		WRITE_NEWLINE;
	}
	else
		MAKE_NOISE;

	return (0);
}
