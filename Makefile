# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 15:03:13 by ademenet          #+#    #+#              #
#    Updated: 2016/04/11 10:35:04 by ademenet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fdf

SOURCES =	main.c\
			parsing.c\
			struct.c\
			tracing.c

HEADERS = fdf.h

OBJECT = $(SOURCES:.c=.o)

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

$(NAME):
	@make --directory libft/
	@$(CC) $(FLAGS) -o mlx $(SOURCES) $(FRAMEWORK)

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
