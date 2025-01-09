##################################################################################
#                              Author: Alexy Heitz                               #
#                        File Name: CPP-00/ex02/Makefile                         #
#                    Creation Date: January 8, 2025 11:00 PM                     #
#                     Last Updated: January 9, 2025 10:41 PM                     #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more!                  #
##################################################################################

NAME		= "GlobalBanksters United Software™"

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SOURCE		= Account.cpp	\
			tests.cpp

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