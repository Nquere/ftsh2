# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nquere <nquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/17 14:12:52 by nquere            #+#    #+#              #
#    Updated: 2014/05/17 16:16:41 by nquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_minishell2

FLAGS = -Wall -Werror -Wextra

CC = gcc -g -O2 $(FLAGS)

SRC = ft_minishell2.c ft_builtin.c ft_tools.c ft_cd.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@(make -C libft)
	@($(CC) -o $(NAME) $(OBJ) -L libft/ -lft)
	@echo "\033[35m$(NAME) created ! ^.^\033[0m"

%.o : %.c
	@($(CC) -c $(SRC) -L libft/ -lft)

clean:
	@(make clean -C libft)
	@(rm -f $(OBJ))
	@echo "\033[31mObject files deleted !\033[0m"

fclean: clean
	@(make fclean -C libft)
	@(rm -f $(NAME))
	@echo "\033[31m$(NAME) deleted !\033[0m"

re: fclean all

.PHONY: clean all re fclean
