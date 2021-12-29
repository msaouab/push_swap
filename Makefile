# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 21:38:28 by msaouab           #+#    #+#              #
#    Updated: 2021/12/28 21:32:54 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

SRC = push_swap.c\
		ft_atoi.c\
		stack_a.c\
		stack_b.c\
		stack_ab.c\
		ft_strlen.c\
		ft_memcpy.c\
		set_tab_index.c\

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)


$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean : 
	@rm -f $(OBJ)

fclean : clean 
	@rm -rf $(NAME)

re : fclean all