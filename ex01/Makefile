##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-00/ex01/Makefile                         #
#                   Creation Date: December 20, 2024 09:28 AM                    #
#                    Last Updated: January 15, 2025 02:20 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= "My Awesome Phonebook™"

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

CONTACT		= ./contact/
PHONEBOOK	= ./phonebook/
UTILITIES	= ./utilities/

SOURCE		= main.cpp							\
			$(CONTACT)/addContact.cpp			\
			$(CONTACT)/displayContact.cpp		\
			$(CONTACT)/displaySummary.cpp		\
			$(PHONEBOOK)/PhoneBook.cpp			\
			$(UTILITIES)/confirmAction.cpp		\
			$(UTILITIES)/equivalentString.cpp	\
			$(UTILITIES)/getTheme.cpp			\
			$(UTILITIES)/line.cpp				\
			$(UTILITIES)/trim.cpp				\

OBJECTS		= $(SOURCE:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re