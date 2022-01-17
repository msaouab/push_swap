/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:19:03 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/17 11:45:09 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_checker(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->filled_size == 0)
		return ;
	tmp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tmp;
}

void	swap_a(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->filled_size == 0)
		return ;
	tmp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tmp;
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->filled_size == 0)
		return ;
	i = stack_a->filled_size;
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = stack_b->tab[0];
	stack_b->filled_size -= 1;
	stack_a->filled_size += 1;
	i = 0;
	while (i < stack_b->filled_size)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
}

void	rotate_a(t_stack *stack_a)
{
	int	tmp;
	int	i;

	if (stack_a->filled_size == 0)
		return ;
	tmp = stack_a->tab[0];
	i = 0;
	while (i < stack_a->filled_size - 1)
	{
		stack_a->tab[i] = stack_a->tab[i + 1];
		i++;
	}
	stack_a->tab[i] = tmp;
}

void	reverot_a(t_stack *stack_a)
{
	int	tmp;
	int	i;

	if (stack_a->filled_size == 0)
		return ;
	i = stack_a->filled_size - 1;
	tmp = stack_a->tab[i];
	while (i > 0)
	{
		stack_a->tab[i] = stack_a->tab[i - 1];
		i--;
	}
	stack_a->tab[0] = tmp;
}
