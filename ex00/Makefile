##################################################################################
#                              Author: Alexy Heitz                               #
#                  File Name: /home/alexy/CPP-00/ex00/Makefile                   #
#                   Creation Date: December 19, 2024 01:02 PM                    #
#                    Last Updated: December 19, 2024 01:06 PM                    #
#                           Source Language: makefile                            #
#                                                                                #
#                            --- Code Description ---                            #
#               Instructions for compiling, cleaning, and more...                #
##################################################################################

NAME		= megaphone

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SOURCE		= megaphone.cpp
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