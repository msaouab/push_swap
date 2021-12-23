/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 22:33:15 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/23 03:11:29 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack *stack_b)
{
	int	tmp = stack_b->tab[0];
	stack_b->tab[0] = stack_b->tab[1];
	stack_b->tab[1] = tmp;
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	// int top_a = stack_a->tab[0];
	// int top_b = stack_b->tab[0];
	// int *new_stack_a = (int*)malloc(stack_a->size + 1);
	// new_stack_a[0] = top_b; // = stack_b->tab[0]
	// memcpy(new_stack_a + 1, stack_a->tab , stack_a->size);
	// stack_a->tab = new_stack_a;
	i = 0;
	if (stack_a != NULL)
	{
		while (stack_b->tab[i])
			i++;
		i++;
		while (stack_b->tab[i] != 0)
		{
			stack_b->tab[i] = stack_b->tab[i - 1];
			i--;
		}
		stack_b->tab[0] = stack_a->tab[0];
	}
}

void	rotate_b(t_stack *stack_b)
{
	int	tmp;
	int	i;

	i = 0;
	while(stack_b->tab[i])
	{
		tmp = stack_b->tab[i];
		stack_b->tab[i] = stack_b->tab[i + 1];
		stack_b->tab[i + 1] = tmp;
	}
}

void	reverot_b(t_stack *stack_b)
{
	int	tmp;
	int	i;

	i = 0;
	while (stack_b->tab[i])
		i++;
	tmp = stack_b->tab[i];
	while (stack_b->tab[i])
	{
		stack_b->tab[i] = stack_b->tab[i - 1];
		i--;
	}
	stack_b->tab[0] = tmp;
}