# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 21:38:28 by msaouab           #+#    #+#              #
#    Updated: 2022/01/15 01:05:27 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

SRC =	check_args.c\
		best_move.c\
		utils.c\
		push_swap.c\
		stack_b.c\
		stack_a.c\
		stack_ab.c\
		move_stacks.c\

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