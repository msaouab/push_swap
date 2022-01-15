/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:39:10 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/15 04:14:53 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_stack(t_stack *stack_a, t_stack *stack_b, int *a_move, int *b_move)
{
	while ((*a_move) > 0 && (*b_move) > 0)
	{
		rotate_ab(stack_a, stack_b);
		(*a_move)--;
		(*b_move)--;
	}
	while ((*a_move) < 0 && (*b_move) < 0)
	{
		reverot_ab(stack_a, stack_b);
		(*a_move)++;
		(*b_move)++;
	}
}

void	super_move(t_stack *stack_a, t_stack *stack_b, int a_move, int b_move)
{
	while (a_move > 0)
	{
		rotate_a(stack_a);
		ft_putstr_fd("ra\n", 1);
		a_move--;
	}
	while (b_move > 0)
	{
		rotate_b(stack_b);
		ft_putstr_fd("rb\n", 1);
		b_move--;
	}
}

void	infer_move(t_stack *stack_a, t_stack *stack_b, int a_move, int b_move)
{
	while (a_move < 0)
	{
		reverot_a(stack_a);
		ft_putstr_fd("rra\n", 1);
		a_move++;
	}
	while (b_move < 0)
	{
		reverot_b(stack_b);
		ft_putstr_fd("rrb\n", 1);
		b_move++;
	}
}

void	push_element_to_a(t_stack *stack_a, t_stack *stack_b, int best_indx)
{
	int	*tab_move_a;
	int	*tab_move_b;
	int	a_best_move;
	int	b_best_move;

	tab_move_a = bes_move_a(stack_a, stack_b);
	tab_move_b = bes_move_b(stack_b);
	a_best_move = tab_move_a[best_indx];
	b_best_move = tab_move_b[best_indx];
	both_stack(stack_a, stack_b, &a_best_move, &b_best_move);
	super_move(stack_a, stack_b, a_best_move, b_best_move);
	infer_move(stack_a, stack_b, a_best_move, b_best_move);
	push_to_a(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
	ft_free(tab_move_a, tab_move_b);
}

void	recuvery_data_from_b(t_stack *stack_a, t_stack *stack_b)
{
	int	indx;

	while (stack_b->filled_size != 0)
	{
		indx = best_move(stack_a, stack_b);
		push_element_to_a(stack_a, stack_b, indx);
	}
}
