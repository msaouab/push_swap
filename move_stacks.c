/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:39:10 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/06 19:52:23 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_move(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	
	i = 0;
	printf("-------------\n");
	while (i < stack_a->filled_size)
	{
		printf("stack_a[%d] = {%d}\n", i, stack_a->tab[i]);
		i++;
	}
	printf("-------------\n");
	i = 0;
	while (i < stack_b->filled_size)
	{
		printf("stack_b[%d] = {%d}\n", i, stack_b->tab[i]);
		i++;
	}
	// i = 0;
	// while (stack_a->)
}