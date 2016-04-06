# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademenet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 15:03:13 by ademenet          #+#    #+#              #
#    Updated: 2016/04/06 15:22:29 by ademenet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fdf

SOURCES = 

HEADERS = libft.h

OBJECT = $(SOURCES:.c=.o)

$(NAME):
	@$(CC) $(FLAGS) -c $(SOURCES)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@echo "\033[1;33mCleaning obj \t \033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;33mCleaning lib \t \033[0;32m[OK]\033[0m"

re: fclean all

run:
	./$(NAME)

.PHONY: clean fclean
