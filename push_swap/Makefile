# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 21:38:28 by msaouab           #+#    #+#              #
#    Updated: 2022/01/17 11:51:42 by msaouab          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_CHECKER = checker

HEADER = push_swap.h

SRC =	check_args.c\
		best_move.c\
		in_stack_a.c\
		utils.c\
		push_swap.c\
		stack_b.c\
		stack_a.c\
		stack_ab.c\
		move_stacks.c\
		less_than_6.c\

SRC_CHECKER =	my_checker.c\
				get_next_line.c\
				check_args.c\
				utils.c\
				stack_b.c\
				stack_a.c\
				stack_ab.c\

OBJ = ${SRC:.c=.o}

OBJ_CHECKER = ${SRC_CHECKER:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

bonus : $(NAME_CHECKER) $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_CHECKER) : $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) $(OBJ_CHECKER) -o $(NAME_CHECKER)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean : 
	@rm -f $(OBJ) $(OBJ_CHECKER)

fclean : clean 
	@rm -rf $(NAME) $(NAME_CHECKER)

re : fclean all