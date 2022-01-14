/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:39:10 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/14 23:15:13 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	push_element_to_a(t_stack *stack_a, t_stack *stack_b, int best_indx)
{
	int	*tab_move_a;
	int	*tab_move_b;
	int	a_best_move;
	int	b_best_move;

	tab_move_a = bes_move_a(stack_a, stack_b);
	tab_move_b = bes_move_b(stack_b);
	a_best_move = tab_move_a[best_indx];
	b_best_move = tab_move_b[best_indx];
	while (a_best_move > 0 && b_best_move > 0)
	{
		rotate_ab(stack_a, stack_b);
		a_best_move--;
		b_best_move--;
	}
	while (a_best_move < 0 && b_best_move < 0)
	{
		reverot_ab(stack_a, stack_b);
		a_best_move++;
		b_best_move++;
	}
	while (a_best_move > 0)
	{
		rotate_a(stack_a);
		ft_putstr("ra\n");
		a_best_move--;
	}
	while (a_best_move < 0)
	{
		reverot_a(stack_a);
		ft_putstr("rra\n");
		a_best_move++;
	}
	while (b_best_move > 0)
	{
		rotate_b(stack_b);
		ft_putstr("rb\n");
		b_best_move--;
	}
	while (b_best_move < 0)
	{
		reverot_b(stack_b);
		ft_putstr("rrb\n");
		b_best_move++;
	}
	push_to_a(stack_a, stack_b);
	ft_putstr("pa\n");
	ft_free(tab_move_a);
	ft_free(tab_move_b);
}

int	abs_movement(int t)
{
	if (t < 0)
		t *= -1;
	return (t);
}

int	*total_movement(t_stack *stack_a, t_stack *stack_b)
{
	int	*t_movement;
	int	*indx_min_num_a;
	int	*indx_min_num_b;
	int	i;

	indx_min_num_a = bes_move_a(stack_a, stack_b);
	indx_min_num_b = bes_move_b(stack_b);
	i = 0;
	t_movement = malloc(sizeof(int) * stack_b->filled_size);
	while (i < stack_b->filled_size)
	{
		t_movement[i] = abs_movement(indx_min_num_a[i]) + abs_movement(indx_min_num_b[i]);
		i++;
	}
	ft_free(indx_min_num_a);
	ft_free(indx_min_num_b);
	return (t_movement);
}

int	best_move(t_stack *stack_a, t_stack *stack_b)
{
	int	*tab_move;
	int	indx_min_num;

	tab_move = total_movement(stack_a, stack_b);
	indx_min_num = min_num_indx(tab_move, stack_b->filled_size);





	// int i;
	// i = 0;
	// printf("\n\n. : | ");
	// while (i < stack_b->filled_size)
	// 	printf(" %d |", tab_move[i++]);
	// printf(" : .\nmin_idx = 	%d\n\n", indx_min_num);
	
	
	
	
	
	
	
	ft_free(tab_move);
	return (indx_min_num);
	
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
		{
			i++;
		}
		if (i == stack_a->filled_size && stack_a->tab[0] < stack_b->tab[j])
		{
			i = 0;
			while (i < indx_min_num && stack_a->tab[i] < stack_b->tab[j])
			{
				i++;
			}
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

void	recuvery_data_from_b(t_stack *stack_a, t_stack *stack_b)
{
	int	indx;

	while (stack_b->filled_size != 0)
	{
		indx = best_move(stack_a, stack_b);
		push_element_to_a(stack_a, stack_b, indx);
	}
}
