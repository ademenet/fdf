# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 15:03:13 by ademenet          #+#    #+#              #
#    Updated: 2016/04/13 10:15:09 by ademenet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fdf

SOURCES =	main.c\
			parsing.c\
			tracing.c\
			iso_projection.c\
			events.c

HEADERS = fdf.h

OBJECT = $(SOURCES:.c=.o)

FRAMEWORK = -lmlx -framework OpenGL -framework AppKit

$(NAME):
	@make --directory libft/
	@$(CC) $(FLAGS) -o fdf libft/libft.a $(SOURCES) $(FRAMEWORK)

all: $(NAME)

clean:
	@rm -rf $(OBJECT)
	@make clean --directory libft/
	@echo "\033[1;34mFDF\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make fclean --directory libft/
	@echo "\033[1;34mFDF\t\033[1;33mCleaning\t\033[0;32m[OK]\033[0m"

re: fclean all

run:
	./$(NAME)

.PHONY: clean fclean
