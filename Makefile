# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbester <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/28 12:09:30 by jbester           #+#    #+#              #
#    Updated: 2016/07/28 12:59:16 by jbester          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

NAME2 = libft/libft.a

SRCS = main.c env.c function.c

DIR = "libft"

FLAGS = -Wall -Werror -Wextra

$(NAME):
		@echo "Compiling 21sh..."
		@make -C $(DIR)
		@gcc -o $(NAME) $(SRCS) $(NAME2) $(FLAGS)
		@echo "21sh compiled."

all: $(NAME)

clean:
		@make clean -C $(DIR)

fclean:
		@make fclean -C $(DIR)
		@rm -f 21sh
		@echo "21sh cleaned."

re: fclean all
