/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:39:10 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/13 01:14:55 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bes_move_a(t_stack *stack_a, t_stack *stack_b);

int	*bes_move_b(t_stack *stack_b);

void	push_element_to_a(t_stack *stack_a, t_stack *stack_b, int best_indx)
{
	int	*tab_move_a;
	int	*tab_move_b;
	int a_best_move;
	int b_best_move;

	tab_move_a = bes_move_a(stack_a, stack_b);
	tab_move_b = bes_move_b(stack_b);
	a_best_move = tab_move_a[best_indx];
	b_best_move = tab_move_b[best_indx];
	// printf("----------\nindx = {%d}\t \t a_move = {%d} \t \t b_move = {%d}\n", best_indx, a_best_move, b_best_move);
	if (a_best_move * b_best_move >= 0)
	{
		if (a_best_move != 0 && b_best_move != 0)
		{
			while (a_best_move > 0)
			{
				rotate_ab(stack_a, stack_b);
				a_best_move--;
				b_best_move--;	
			}
			while (a_best_move < 0)
			{
				reverot_ab(stack_a, stack_b);
				a_best_move++;
				b_best_move++;
			}
		}
	}
	if (a_best_move != 0)
	{
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
	}
	if (b_best_move != 0)
	{
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
	}
	push_to_a(stack_a, stack_b);
	ft_putstr("pa\n");
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
		// printf("t_movement[%d] = {%d} \t a_tab = {%d} \t b_tab = {%d}\n", i, t_movement[i], indx_min_num_a[i], indx_min_num_b[i]);
		i++;
	}
	// t_movement = abs_movement(t_movement, stack_b->filled_size); // free and return just the value in the code;
	return (t_movement);
}

int	best_move(t_stack *stack_a, t_stack *stack_b)
{
	int	*tab_move;
	int	indx_min_num;
	
	tab_move = total_movement(stack_a, stack_b);
	indx_min_num = min_num_indx(tab_move, stack_b->filled_size);
	return (indx_min_num);
}

void	recuvery_data_from_b(t_stack *stack_a, t_stack *stack_b)
{
	int	indx;
	// int	i;

	// i = 1;//stack_b->filled_size;
	while (stack_b->filled_size != 0)
	{
		indx = best_move(stack_a, stack_b);
		push_element_to_a(stack_a, stack_b, indx);
		// i--;

		/* ************************************************************************** */
	
	// int	j;
	
	// j = 0;
	// printf("-----------------------\n");
	// // printf("  stack_a[i]\t   \tstack_b[i]\n");
	// while (j < stack_a->filled_size)
	// {
	// 	printf("||stack_a[%d] = {%d}\n", j, stack_a->tab[j]);	
	// 	j++;
	// }
	// printf("-----------------------\n");
	// j = 0;
	// while (j < stack_b->filled_size)
	// {
	// 	printf("stack_b[%d] = {%d}\n", j, stack_b->tab[j]);
	// 	j++;
	// }
	// printf("-----------------------\n");
/* ************************************************************************** */
		
	}
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
				// printf("stack_a[%d] = %d \t stack_b[%d] = %d \t stack_a[%d] = %d \t  a_move[%d] = %d\n", i, stack_a->tab[i], j, stack_b->tab[j], i + 1, stack_a->tab[i + 1], j, a_move[j]);
			i++;
		}
		if (i == stack_a->filled_size && stack_a->tab[0] < stack_b->tab[j])
		{
			i = 0;
			while (i < indx_min_num && stack_a->tab[i] < stack_b->tab[j])
			{
					// printf("stack_a[%d] = %d \t stack_b[%d] = %d \t stack_a[%d] = %d \t  a_move[%d] = %d\n", i, stack_a->tab[i], j, stack_b->tab[j], i + 1, stack_a->tab[i + 1], j, a_move[j]);
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
