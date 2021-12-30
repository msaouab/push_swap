/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:02:13 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/30 12:15:33 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int ac)
{
	if (ac == 1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	if (ac == 2)
		exit(0);
	if (ac == 5)
		write(1, "woow\n", 5);
}

int	*ft_check_dup(int *arr, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				ft_error(1);
			j++;
		}
		i++;
	}
	return (arr);
}

void	initialize_stack(t_stack *given_stack, int stack_size)
{
	given_stack->filled_size = 0;
	given_stack->tab = malloc(sizeof(int) * stack_size);
}

int	min_indx(int *tab, int size)
{
	int	min;
	int	i;

	i = 0;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int	max_indx(int *tab, int size)
{
	int	max;
	int	i;

	i = 0;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	*set_index(int *tab, int size)
{
	int	*tab_indx;
	int	count;
	int	i;
	int	j;

	tab_indx = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		count = 0;
		tab_indx[i] = 0;
		j = i + 1;
		j %= size;
		while (count < size - 1)
		{
			if (tab[i] > tab[j])
				tab_indx[i]++;
			j++;
			j %= size;
			count++;
		}
		i++;
	}
	return (tab_indx);
}

int	find_groups(int *tab, int size, int count, int i)
{
	int	to_find;
	int	j;
	
	to_find = tab[i];
	j = i + 1;
	while (j < size)
	{
		if (to_find < tab[j])
		{
			to_find = tab[j];
			count++;
		}
		j++;
	}
	j = 0;
	while (j < i)
	{
		if (to_find < tab[j])
		{
			to_find = tab[j];
			count++;
		}
		j++;
	}
	return (count);
}

int	*greater_than(int *tab, int size)
{
	int	*tab_groups;
	int	per_grp;
	int	count;
	int	i;

	tab_groups = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		count = 1;
		tab_groups[i] = find_groups(tab, size, count, i);
		i++;
	}
	i = 0;
	per_grp = tab_groups[0];
	while (i < size)
	{
		if (per_grp < tab_groups[i])
			per_grp = i;
		i++;
	}
			printf("||per_groups = %d||\n", per_grp);
	// while (i < size)
	// {
	// 	printf(":: tab[i] = %d , tab_groups = %d  per_grp = %d::\n", tab[i], tab_groups[i], per_grp);
	// 	i++;
	// }
	return (tab_groups);
}

void	push_swap(int ac, char **av)
{
	t_stack	stack_a;
	// t_stack stack_b;
	int *tab_indx;
	int *tab;
	int i;

	tab = malloc(sizeof(int) * ac - 1);
	i = 0;
	while (av[i + 1])
	{
		tab[i] = ft_atoi(av[i + 1]);
		i++;
	}
	ft_check_dup(tab, ac - 1);
	initialize_stack(&stack_a, ac - 1);
	ft_memcpy(stack_a.tab, tab, (ac - 1) * 4);
	stack_a.filled_size = ac - 1;
	tab_indx = set_index(stack_a.tab, ac - 1);
	int	*mark_head = greater_than(stack_a.tab, ac - 1);
	i = 0;
	while (i < stack_a.filled_size)
	{
		printf("tab_index[%d] = |%d\t|%d\t|%d\n", i, stack_a.tab[i], tab_indx[i], mark_head[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac <= 2)
		ft_error(ac);
	push_swap(ac, av);
}