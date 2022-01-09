/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:39:10 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/08 17:13:25 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*total_move(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	*tab_move_b;
	int	*tab_move_a;
	int	*tab_total_move;

	tab_move_a = best_move_a(stack_a, stack_b);
	tab_move_b = best_move_b(stack_b);
	tab_total_move = malloc(sizeof(int) * stack_b->filled_size);
	i = 0;
	while (i < stack_b->filled_size)
	{
		tab_total_move[i] = tab_move_a[i] + tab_move_b[i];
		printf("tab a = %d, tab b = %d, tot move = %d\n", tab_move_a[i], tab_move_b[i], tab_total_move[i]);
		i++;
	}
	return (tab_total_move);
}

void	best_move(t_stack *stack_a, t_stack *stack_b)
{
	int	*tab_total_move;
	
	tab_total_move = total_move(stack_a, stack_b);
	
	int j = 0;
	printf("1-----------------------\n");
	while (j < stack_b->filled_size)
	{
		printf("total move[%d] == {%d}\n", j, tab_total_move[j]);
		j++;
	}
	// printf("-----------------------\n");
	// while (i < stack_b->filled_size)
	// {
	// 	printf("tab_move in b[%d] == {%d}\n", i, tab_move_b[i]);
	// 	i++;
	// }
	printf("2-----------------------\n");
}

int	*best_move_a(t_stack *stack_a, t_stack *stack_b)
{
	int	*tab_move;
	int	count;
	int	i;
	int	j;

	tab_move = malloc(sizeof(int) * stack_b->filled_size);
	j = 0;
	while (j < stack_b->filled_size)
	{
		i = 0;
		count = 0;
		while (i < stack_a->filled_size)
		{
			if (stack_b->tab[j] > stack_a->tab[i])
				count++;
			i++;
		}
		if (count <= stack_a->filled_size / 2)
			tab_move[j++] = count;
		else
			tab_move[j++] = ((stack_a->filled_size - count) * -1);
	}
	return (tab_move);
}

int	*best_move_b(t_stack *stack_b)
{
	int	*tab_move;
	int	i;

	i = 0;
	tab_move = malloc(sizeof(int) * stack_b->filled_size);
	while (i < stack_b->filled_size)
	{
		if (i <= stack_b->filled_size / 2)
			tab_move[i] = i;
		else if (i > stack_b->filled_size / 2)
			tab_move[i] = (stack_b->filled_size - i) * -1;
		i++;
	}
	return (tab_move);
}
