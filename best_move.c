/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:50:03 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/15 04:15:03 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_move(int t)
{
	if (t < 0)
		t *= -1;
	return (t);
}

int	*bes_move_a(t_stack *stack_a, t_stack *stack_b)
{
	int	indx_min_num;
	int	*a_move;
	int	i;
	int	j;

	j = 0;
	indx_min_num = min_num_indx(stack_a->tab, stack_a->filled_size);
	a_move = malloc(sizeof(int) * stack_b->filled_size);
	while (j < stack_b->filled_size)
	{
		i = indx_min_num;
		while (i < stack_a->filled_size && stack_a->tab[i] < stack_b->tab[j])
			i++;
		if (i == stack_a->filled_size && stack_a->tab[0] < stack_b->tab[j])
		{
			i = 0;
			while (i < indx_min_num && stack_a->tab[i] < stack_b->tab[j])
				i++;
		}
		a_move[j] = i;
		if (a_move[j] > stack_a->filled_size / 2)
			a_move[j] = (stack_a->filled_size - i) * -1;
		j++;
	}
	return (a_move);
}

int	*bes_move_b(t_stack *stack_b)
{
	int	*b_move;
	int	i;

	i = 0;
	b_move = malloc(sizeof(int) * stack_b->filled_size);
	while (i < stack_b->filled_size)
	{
		b_move[i] = i;
		if (b_move[i] > stack_b->filled_size / 2)
			b_move[i] = (stack_b->filled_size - i) * -1;
		i++;
	}
	return (b_move);
}

int	*total_movement(t_stack *stack_a, t_stack *stack_b)
{
	int	*t_move;
	int	*indx_min_num_a;
	int	*indx_min_num_b;
	int	i;

	indx_min_num_a = bes_move_a(stack_a, stack_b);
	indx_min_num_b = bes_move_b(stack_b);
	i = 0;
	t_move = malloc(sizeof(int) * stack_b->filled_size);
	while (i < stack_b->filled_size)
	{
		t_move[i] = abs_move(indx_min_num_a[i]) + abs_move(indx_min_num_b[i]);
		i++;
	}
	ft_free(indx_min_num_a, indx_min_num_b);
	return (t_move);
}

int	best_move(t_stack *stack_a, t_stack *stack_b)
{
	int	*tab_move;
	int	indx_min_num;

	tab_move = total_movement(stack_a, stack_b);
	indx_min_num = min_num_indx(tab_move, stack_b->filled_size);
	ft_free(tab_move, NULL);
	return (indx_min_num);
}
