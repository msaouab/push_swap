/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:19:14 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/27 11:16:06 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stack stack_b)
{
	int	tmp;

	if (!stack_b.tab)
		return ;
	tmp = stack_b.tab[0];
	stack_b.tab[0] = stack_b.tab[1];
	stack_b.tab[1] = tmp;
}

void	push_b(t_stack stack_b, t_stack stack_a)
{
	int	i;

	if (stack_a.size == 0)
		return ;
	if (stack_b.size != 0)
	{
		i = stack_b.size - 1;
		while (i >= 0)
		{
			stack_b.tab[i + 1] = stack_b.tab[i];
			i--;
		}
	}
	stack_b.tab[0] = stack_a.tab[0];
	// while (stack_b.tab[i])
	// 	i++;
	// stack_b.tab = malloc(sizeof(int) * (i + 1));
}

void	rotate_b(t_stack stack_b)
{
	int	tmp;
	int	i;

	if (!stack_b.tab)
		return ;
	i = 0;
	tmp = stack_b.tab[0];
	while (stack_b.tab[i])
	{
		stack_b.tab[i] = stack_b.tab[i + 1];
		i++;
	}
	stack_b.tab[i] = tmp;
}

void	reverot_b(t_stack stack_b)
{
	int	tmp;
	int	i;

	if (!stack_b.tab)
		return ;
	i = 0;
	while (stack_b.tab[i])
		i++;
	tmp = stack_b.tab[i];
	while (stack_b.tab[i])
	{
		stack_b.tab[i + 1] = stack_b.tab[i];
		i--;
	}
	stack_b.tab[0] = tmp;
}
