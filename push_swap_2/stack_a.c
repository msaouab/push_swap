/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:19:03 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/30 00:27:45 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->filled_size == 0)
		return ;
	tmp = stack_a->tab[0];
	stack_a->tab[0] = stack_a->tab[1];
	stack_a->tab[1] = tmp;
	ft_putstr("sa\n");
}

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_b->filled_size == 0)
		return ;
	if (stack_a->filled_size != 0)
	{
		i = stack_a->filled_size;
		while (i >= 0)
		{
			stack_a->tab[i + 1] = stack_a->tab[i];
			i--;
		}
	}
	stack_a->tab[0] = stack_b->tab[0];
	i = 0;
	while (i <= stack_b->filled_size - 1)
	{
		stack_b->tab[i - 1] = stack_b->tab[i];
		i++;
	}
	stack_b->filled_size -= 1;
	stack_a->filled_size += 1;
	//ft_putstr("pa\n");
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
	// ft_putstr("ra\n");
}

void	reverot_a(t_stack *stack_a)
{
	int	tmp;
	int	i;

	if (stack_a->filled_size == 0)
		return ;
	i = stack_a->filled_size - 1;
	tmp = stack_a->tab[i];
	while (i >= 0)
	{
		stack_a->tab[i + 1] = stack_a->tab[i];
		i--;
	}
	stack_a->tab[0] = tmp;
	// ft_putstr("rra\n");
}
