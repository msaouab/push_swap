/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:19:14 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/02 10:26:04 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->filled_size == 0)
		return ;
	tmp = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = tmp;
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_a->filled_size == 0)
		return ;
	if (stack_b->filled_size != 0)
	{
		i = stack_b->filled_size;
		while (i >= 0)
		{
			stack_b->tab[i + 1] = stack_b->tab[i];
			i--;
		}
	}
	stack_b->tab[0] = stack_a->tab[0];
	i = 0;
	while (i <= stack_a->filled_size - 1)
	{
		stack_a->tab[i - 1] = stack_a->tab[i];
		i++;
	}
	stack_a->filled_size -= 1;
	stack_b->filled_size += 1;
}

void	rotate_b(t_stack *stack_b)
{
	int	tmp;
	int	i;

	if (stack_b->filled_size == 0)
		return ;
	tmp = stack_b->tab[0];
	i = 0;
	while (i < stack_b->filled_size - 1)
	{
		stack_b->tab[i] = stack_b->tab[i + 1];
		i++;
	}
	stack_b->tab[i] = tmp;
}

void	reverot_b(t_stack *stack_b)
{
	int	tmp;
	int	i;

	if (stack_b->filled_size == 0)
		return ;
	i = stack_b->filled_size - 1;
	tmp = stack_b->tab[i];
	while (i >= 0)
	{
		stack_b->tab[i + 1] = stack_b->tab[i];
		i--;
	}
	stack_b->tab[0] = tmp;
}
