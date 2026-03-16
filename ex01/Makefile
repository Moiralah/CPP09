# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/08 21:52:29 by huidris           #+#    #+#              #
#    Updated: 2026/03/08 21:53:02 by huidris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= RPN

FLAGS	= -Wall -Wextra -Werror -std=c++98

CC		= c++

SRC		= RPN.cpp main.cpp

$(NAME): $(SRC)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)

clean:
	clear

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
