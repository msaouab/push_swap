/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:02:13 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/15 05:20:39 by msaouab          ###   ########.fr       */
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

int	*true_false(int *tab, int size, int indx)
{
	int	i;
	int	tmp;
	int	*tab_to_detect;
	int	traverse;

	tab_to_detect = malloc(sizeof(int) * size);
	i = indx;
	tmp = tab[indx];
	traverse = 0;
	while (traverse < size)
	{
		if (tmp < tab[i])
		{
			tab_to_detect[i] = TRUE;
			tmp = tab[i];
		}
		else
			tab_to_detect[i] = FALSE;
		i++;
		i = i % size;
		traverse++;
	}
	tab_to_detect[indx] = TRUE;
	return (tab_to_detect);
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

int	help_to_find_perfect_group(int *tab, int size, int i)
{
	int	count;
	int	traverse;
	int	per_grp;
	int	j;

	traverse = 0;
	count = 1;
	j = i + 1;
	per_grp = tab[i];
	while (traverse < size)
	{
		if (per_grp < tab[j])
		{
			per_grp = tab[j];
			count++;
		}
		j++;
		j = j % size;
		traverse++;
	}
	return (count);
}

int	*perfect_groups(int *tab, int size)
{
	int	*tab_groups;
	int	*tab_true;
	int	index;
	int	i;

	tab_groups = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		tab_groups[i] = help_to_find_perfect_group(tab, size, i);
		i++;
	}
	index = max_num_indx(tab_groups, size);
	tab_true = true_false(tab, size, index);
	ft_free(tab_groups, NULL);
	return (tab_true);
}

void	push_swap(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*mark_head;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * (ac));
	i = 0;
	while (av[i])
	{
		tab[i] = ft_atoi(av[i]);
		i++;
	}
	ft_check_dup(tab, ac);
	initialize_stack(&stack_a, ac);
	ft_memcpy(stack_a.tab, tab, (ac) * 4);
	stack_a.filled_size = ac;
	mark_head = perfect_groups(stack_a.tab, stack_a.filled_size);
	initialize_stack(&stack_b, ac);
	stack_b.filled_size = 0;
	first_move(&stack_a, &stack_b, mark_head);
	recuvery_data_from_b(&stack_a, &stack_b);
	sorting_stack_a(&stack_a);
	ft_free(mark_head, tab);
	ft_free(stack_b.tab, stack_a.tab);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_error(ac);
	push_swap(ac - 1, av + 1);
}
