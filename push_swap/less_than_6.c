/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:07:50 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/17 11:41:38 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	equal_two(t_stack *stack_a)
{
	if (stack_a->tab[0] > stack_a->tab[1])
	{
		swap_a(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	exit(0);
}

void	equal_three(t_stack *stack_a)
{
	if (stack_a->tab[0] < stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2])
	{
		reverot_a(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[1] > stack_a->tab[2])
	{
		rotate_a(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[0] < stack_a->tab[2])
	{
		swap_a(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	if (stack_a->tab[0] > stack_a->tab[1] && stack_a->tab[0] > stack_a->tab[2])
	{
		rotate_a(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	if (stack_a->tab[1] > stack_a->tab[0] && stack_a->tab[1] > stack_a->tab[2])
	{
		reverot_a(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	// exit(0);
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
	i = 0;
	while (i + 1 < size)
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
		i++;
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
	
	
	
	// int i;
	// i = 0;
	// while (i < stack_a->filled_size)
	// {
	// 	printf("here stack_a = %d\t size = %d\n", stack_a->tab[i], stack_a->filled_size);
	// 	i++;
	// }


	
}
void	less_than_six(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	(void)stack_b;
	if (stack_a->filled_size == 1)
		exit(0);
	if (stack_a->filled_size == 2)
		equal_two(stack_a);
	if (stack_a->filled_size == 3)
		equal_three(stack_a);
	if (stack_a->filled_size == 5)
	{
		while (i < stack_a->filled_size && stack_a->tab[i] < stack_a->tab[i + 1])
			i++;
		if (i != stack_a->filled_size)
			equal_five(stack_a, stack_b);
	}
	exit(0);
}
