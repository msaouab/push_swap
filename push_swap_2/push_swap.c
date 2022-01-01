/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:02:13 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/01 11:46:26 by msaouab          ###   ########.fr       */
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
	int	i;
	int	j;

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
	int	*new_indx;
	int	count;
	int	i;
	int	j;

	new_indx = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		count = 0;
		new_indx[i] = 0;
		j = i + 1;
		j %= size;
		while (count < size - 1)
		{
			if (tab[i] > tab[j])
				new_indx[i]++;
			j++;
			j %= size;
			count++;
		}
		i++;
	}
	return (new_indx);
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

int	*true_false(int *tab, int size, int mark_header)
{
	int	i;
	int traversed;
	int	to_find;
	int	*tab_to_detect;

	to_find = tab[mark_header];
	traversed = 0;
	tab_to_detect = malloc(sizeof(int) * size);
	tab_to_detect[mark_header] = true;
	i = mark_header + 1;
	printf("index to start with = %d\n", i);
	while (traversed < size - 1)
	{
		if (to_find < tab[i])
		{
			to_find = tab[i];
			tab_to_detect[i] = true;
		}
		else
			tab_to_detect[i] = false;
		i++;
		i = i % size;
		traversed++;
	}
	i = 0;
	while (i < size)
		printf("%d\n", tab_to_detect[i++]);
	return (tab_to_detect);
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
int index = 0;
	while (i < size)
	{
		if (per_grp < tab_groups[i])
		{
			printf("%d\n", i);
			per_grp = tab_groups[i];
			index = i;
		}
		i++;
	}
	printf("per group = %d\n", per_grp);
	printf("index = %d\n", index);
	tab_groups = true_false(tab, size, index);
	return (tab_groups);
}

void	push_swap(int ac, char **av)
{
	t_stack	stack_a;
	int		*tab_indx;
	int		*mark_head;
	int		*tab;
	int		i;

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
	mark_head = greater_than(stack_a.tab, ac - 1);
	i = 0;
	printf("-------------\n");
	printf("  tab_index[i]  \tnew_indx\tbest_group\n");
	while (i < stack_a.filled_size)
	{
		printf("tab_index[%d] = |%d\t  |%d\t\t   |%d\n", i, stack_a.tab[i], tab_indx[i], mark_head[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac <= 2)
		ft_error(ac);
	push_swap(ac, av);
}
