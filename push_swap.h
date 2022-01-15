/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:07:04 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/15 04:16:41 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define FALSE 0
# define TRUE 1

typedef struct s_stacks
{
	int	*tab;
	int	filled_size;
}	t_stack;

/* ************************************************************************** */

void	swap_a(t_stack *stack_a);
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a);
void	reverot_a(t_stack *stack_a);
void	swap_ss(t_stack *stack_a, t_stack *stack_b);
void	rotate_ab(t_stack *stack_a, t_stack *stack_b);
void	reverot_ab(t_stack *stack_a, t_stack *stack_b);
void	swap_b(t_stack *stack_b);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_b(t_stack *stack_b);
void	reverot_b(t_stack *stack_b);
int		best_move(t_stack *stack_a, t_stack *stack_b);
int		min_num_indx(int *tab, int size);
int		*set_index(int *tab, int size);
int		*total_move(t_stack *stack_a, t_stack *stack_b);
void	push_element_to_a(t_stack *stack_a, t_stack *stack_b, int min_num);
void	recuvery_data_from_b(t_stack *stack_a, t_stack *stack_b);
void	ft_free(int *tab1, int *tab2);
int		*bes_move_b(t_stack *stack_b);
int		*bes_move_a(t_stack *stack_a, t_stack *stack_b);
int		abs_move(int t);
void	initialize_stack(t_stack *given_stack, int stack_size);

/* ************************************************************************** */

int		ft_atoi(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(char *s);
void	ft_error(int ac);
int		*ft_check_dup(int *arr, int size);
void	ft_putstr_fd(char *s, int fd);

#endif