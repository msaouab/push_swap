/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:07:04 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/17 04:10:35 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ***************************** Includes & struct ************************** */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <stdio.h>

# define FALSE 0
# define TRUE 1

typedef struct s_stacks
{
	int	*tab;
	int	filled_size;
}	t_stack;

/* ***************************** push_swap ********************************** */

size_t	ft_strlen(char *s);
void	ft_free(int *tab1, int *tab2);
void	initialize_stack(t_stack *given_stack, int stack_size);
void	ft_putstr_fd(char *s, int fd);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	sorting_stack_a(t_stack *stack_a);
void	first_move(t_stack *stack_a, t_stack *stack_b, int *head);
void	rotate_in_first_move(t_stack *stack_a, int *head, int counter);
void	ft_error(int ac);
void	swap_a(t_stack *stack_a);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a);
void	reverot_a(t_stack *stack_a);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	reverot_ab(t_stack *stack_a, t_stack *stack_b);
void	swap_b(t_stack *stack_b);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_b(t_stack *stack_b);
void	reverot_b(t_stack *stack_b);
void	recuvery_data_from_b(t_stack *stack_a, t_stack *stack_b);
void	push_element_to_a(t_stack *stack_a, t_stack *stack_b, int best_indx);
void	infer_move(t_stack *stack_a, t_stack *stack_b, int a_move, int b_move);
void	super_move(t_stack *stack_a, t_stack *stack_b, int a_move, int b_move);
int		max_num_indx(int *tab, int size);
int		min_num_indx(int *tab, int size);
int		abs_move(int t);
int		*bes_move_a(t_stack *stack_a, t_stack *stack_b);
int		*bes_move_b(t_stack *stack_b);
int		*total_movement(t_stack *stack_a, t_stack *stack_b);
int		best_move(t_stack *stack_a, t_stack *stack_b);
long	ft_atoi(char *str);
int		*ft_check_dup(int *arr, int size);
void	less_than_six(t_stack *stack_a, t_stack *stack_b);

/* **************************** checker ************************************* */

void	checker(char **str, int size);
char	*get_next_line(int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	swap_a_checker(t_stack *stack_a);

/* ************************************************************************** */

#endif