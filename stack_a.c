/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:19:03 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/26 09:52:01 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack stack_a)
{
	int	tmp;

	if (!stack_a.tab || stack_a.tab <= 1)
		return ;
	tmp = stack_a.tab[0];
	stack_a.tab[0] = stack_a.tab[1];
	stack_a.tab[1] = tmp;
}

void	push_a(t_stack stack_a, t_stack stack_b)
{
	int	i;

	i = 0;
	if (!stack_a.tab || !stack_b.tab)
		return ;
	while (stack_a.tab[i])
		i++;
	stack_a.tab = malloc(sizeof(int) * (i + 1));
	while (stack_a.tab[i])
	{
		stack_a.tab[i + 1] = stack_a.tab[i];
		i--;
	}
	stack_a.tab[0] = stack_b.tab[0];
}

void	rotate_a(t_stack stack_a)
{
	int	tmp;
	int	i;

	if (!stack_a.tab)
		return ;
	i = 0;
	tmp = stack_a.tab[0];
	while (stack_a.tab[i])
	{
		stack_a.tab[i] = stack_a.tab[i + 1];
		i++;
	}
	stack_a.tab[i] = tmp;
}

void	reverot_a(t_stack stack_a)
{
	int	tmp;
	int	i;

	if (!stack_a.tab)
		return ;
	i = 0;
	while (stack_a.tab[i])
		i++;
	tmp = stack_a.tab[i];
	while (stack_a.tab[i])
	{
		stack_a.tab[i + 1] = stack_a.tab[i];
		i--;
	}
	stack_a.tab[0] = tmp;
}