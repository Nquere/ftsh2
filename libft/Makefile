# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nquere <nquere@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/17 14:15:59 by nquere            #+#    #+#              #
#    Updated: 2014/05/17 15:35:51 by nquere           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c ft_bzero.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c\
		ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnstr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_isprint.c \
		ft_isalnum.c ft_strrchr.c ft_memalloc.c ft_memdel.c ft_strnew.c \
		ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
		ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c \
		ft_putendl.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
		ft_lstiter.c ft_lstmap.c get_next_line.c \
		ft_getnbr.c  ft_strdup2D.c

CC = gcc -g -O2 $(FLAGS) -I includes
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@(ar rc $(NAME) $(OBJ))
	@echo "\033[35m$(NAME) created ! ^.^\033[0m"

%.o: %.c
	@($(CC) -c $(SRC))

clean:
	@($(RM) $(OBJ))
	@echo "\033[31mObject files deleted !\033[0m"

fclean: clean
	@($(RM) $(NAME))
	@echo "\033[31m$(NAME) deleted !\033[0m"

re: fclean all

.PHONY: re all fclean clean
