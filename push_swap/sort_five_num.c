/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:25:04 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/17 12:27:04 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compliting_equal_five(t_stack *stack_a, t_stack *stack_b)
{
	equal_three(stack_a);
	if (stack_b->tab[0] < stack_b->tab[1])
	{
		swap_b(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	push_to_a(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
	push_to_a(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}

int	*sort_for_five(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	*sorted;

	sorted = (int *)malloc(sizeof(int) * 5);
	i = -1;
	while (++i < size)
		sorted[i] = tab[i];
	i = -1;
	while (++i + 1 < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (sorted[j] < sorted[i])
			{
				tmp = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = tmp;
			}
			j++;
		}
	}
	return (sorted);
}

void	equal_five(t_stack *stack_a, t_stack *stack_b)
{
	int	*tab;

	tab = sort_for_five(stack_a->tab, stack_a->filled_size);
	while (stack_a->filled_size != 3)
	{
		if (stack_a->tab[0] < tab[2])
		{
			push_to_b(stack_a, stack_b);
			ft_putstr_fd("pb\n", 1);
		}
		if (stack_a->tab[0] < tab[2])
		{
			push_to_b(stack_a, stack_b);
			ft_putstr_fd("pb\n", 1);
		}
		reverot_a(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	compliting_equal_five(stack_a, stack_b);
	free (tab);
}
