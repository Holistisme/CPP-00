##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-00/ex01/Makefile                         #
#                   Creation Date: December 20, 2024 09:28 AM                    #
#                     Last Updated: January 9, 2025 10:45 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= "My Awesome Phonebook™"

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

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
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re