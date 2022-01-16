/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_stack_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:02:13 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/15 20:50:38 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_num_indx(int *tab, int size)
{
	int	min_num;
	int	min_indx;
	int	i;

	i = 1;
	min_indx = 0;
	min_num = tab[0];
	while (i < size)
	{
		if (tab[i] < min_num)
		{
			min_num = tab[i];
			min_indx = i;
		}
		i++;
	}
	return (min_indx);
}

int	max_num_indx(int *tab, int size)
{
	int	max_num;
	int	max_indx;
	int	i;

	i = 1;
	max_indx = 0;
	max_num = tab[0];
	while (i < size)
	{
		if (tab[i] > max_num)
		{
			max_num = tab[i];
			max_indx = i;
		}
		i++;
	}
	return (max_indx);
}

void	rotate_in_first_move(t_stack *stack_a, int *head, int counter)
{
	int	i;

	i = 0;
	if (head[counter] == 1 && i <= stack_a->filled_size / 2)
	{
		rotate_a(stack_a);
		ft_putstr_fd("ra\n", 1);
		i++;
	}
	if (head[counter] == 1 && i > stack_a->filled_size / 2)
	{
		reverot_a(stack_a);
		ft_putstr_fd("rra\n", 1);
		i--;
	}
}

void	first_move(t_stack *stack_a, t_stack *stack_b, int *head)
{
	int	i;
	int	counter;
	int	initial_size_of_stack_a;

	counter = 0;
	initial_size_of_stack_a = stack_a->filled_size;
	i = 0;
	while (counter < initial_size_of_stack_a)
	{
		i = 0;
		if (head[counter] == 0)
		{
			push_to_b(stack_a, stack_b);
			ft_putstr_fd("pb\n", 1);
		}
		rotate_in_first_move(stack_a, head, counter);
		counter++;
	}
}

void	sorting_stack_a(t_stack *stack_a)
{
	int	min_index;

	min_index = min_num_indx(stack_a->tab, stack_a->filled_size);
	if (min_index <= stack_a->filled_size / 2)
	{
		while (min_index > 0)
		{
			rotate_a(stack_a);
			ft_putstr_fd("ra\n", 1);
			min_index--;
		}
	}
	else
	{
		while (min_index < stack_a->filled_size)
		{
			reverot_a(stack_a);
			ft_putstr_fd("rra\n", 1);
			min_index++;
		}
	}
}
