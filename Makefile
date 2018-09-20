# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbxaba <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/24 12:02:16 by sbxaba            #+#    #+#              #
#    Updated: 2018/08/31 09:04:07 by sbxaba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

OBJ = ls_lib.a

MAIN = main.c\

FLAGS = -Wall -Wextra -Werror -I.

SRC =   ft_do.c\
        ft_itoa.c\
        ft_list.c\
        ft_ls.c\
        ft_memcpy.c\
        ft_putchar.c\
        ft_putchar_fd.c\
        ft_putendl.c\
        ft_putnbr.c\
        ft_putnbr_fd.c\
        ft_putstr.c\
        ft_strcmp.c\
        ft_strjoin.c\
        ft_strlen.c\
        ft_strnew.c\
        print.c\
        main.c

OSRC =  ft_do.o\
        ft_itoa.o\
        ft_list.o\
        ft_ls.o\
        ft_memcpy.o\
        ft_putchar.o\
        ft_putchar_fd.o\
        ft_putendl.o\
        ft_putnbr.o\
        ft_putnbr_fd.o\
        ft_putstr.o\
        ft_strcmp.o\
        ft_strjoin.o\
        ft_strlen.o\
        ft_strnew.o\
        print.o\
        main.o\

CC = gcc

HEADER = ft_ls.h

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLGS) -o ft_ls $(MAIN) $(OBJ)

$(OBJ):$(OSRC)
	ar rc $(OBJ) $(OSRC)

$(OSRC):
	$(CC) $(FLAGS) -c $(SRC)
clean:
	rm $(OSRC)
fclean:
	rm -f $(NAME) $(OSRC) $(OBJ)
re: fclean all
