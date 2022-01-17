/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:07:50 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/17 12:25:26 by msaouab          ###   ########.fr       */
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
}

void	less_than_six(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;

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
		j = stack_a->filled_size;
		while (i < j && stack_a->tab[i] < stack_a->tab[i + 1])
			i++;
		if (i != stack_a->filled_size)
			equal_five(stack_a, stack_b);
	}
	exit(0);
}
