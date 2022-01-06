/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:02:13 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/06 00:41:54 by msaouab          ###   ########.fr       */
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
	int	max_indx;
	int	max_num;
	int	i;

	i = 0;
	max_indx = 0;
	max_num = tab[0];
	while (i < size)
	{
		if (tab[i] > max_indx)
		{
			max_num = tab[i];
			max_indx = i;
		}
		i++;
	}
	return (max_indx);
}

void	rotate_table(int *tab, int size)
{
	int	tmp;
	int	i;

	if (size == 0)
		return ;
	tmp = tab[0];
	i = 0;
	while (i < size - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = tmp;
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
	int	to_find;
	int	traversed;
	int	*tab_to_detect;

	to_find = tab[mark_header];
	traversed = 0;
	tab_to_detect = malloc(sizeof(int) * size);
	tab_to_detect[mark_header] = TRUE;
	i = mark_header + 1;
	while (traversed < size - 1)
	{
		if (to_find < tab[i])
		{
			to_find = tab[i];
			tab_to_detect[i] = TRUE;
		}
		else
			tab_to_detect[i] = FALSE;
		i++;
		i = i % size;
		traversed++;
	}
	return (tab_to_detect);
}

int	*greater_than(int *tab, int size)
{
	int	*tab_groups;
	int	per_grp;
	int	index;
	int	count;
	int	i;

	tab_groups = malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
	{
		count = 1;
		tab_groups[i] = find_groups(tab, size, count, i);
	}
	i = -1;
	per_grp = tab_groups[0];
	index = 0;
	while (++i < size)
	{
		if (per_grp < tab_groups[i])
		{
			per_grp = tab_groups[i];
			index = i;
		}
	}
	return (true_false(tab, size, index));
}

void	first_move(t_stack *stack_a, t_stack *stack_b, int size, int *head)
{
	int	counter;
	int	initial_size_of_stack_a;

	counter = 0;
	initial_size_of_stack_a = stack_a->filled_size;
	while (counter < initial_size_of_stack_a)
	{
		if (head[0] == 0)
		{
			push_to_b(stack_a, stack_b);
			ft_putstr("pb\n");
			head[0] = 1;
			rotate_table(head, size);
		}
		else
		{
			rotate_a(stack_a);
			ft_putstr("ra\n");
			rotate_table(head, size);
		}
		counter++;
	}
}

void	sorting_stack_a(t_stack *stack_a)
{
	int	min_index;

	min_index = min_num_indx(stack_a->tab, stack_a->filled_size);
	while (min_index != 0)
	{
		rotate_a(stack_a);
		ft_putstr("ra\n");
		min_index--;
	}
}

int	count_instaction_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (i + 1 < stack_a->filled_size && stack_a->tab[i] < stack_a->tab[i + 1])
	{
		i++;
		start++;
	}
	if (i + 1 == stack_a->filled_size && stack_a->tab[i + 1] > stack_a->tab[0])
		i = 0;
	else
		i = start + 1;
	while (i < stack_a->filled_size && stack_b->tab[0] > stack_a->tab[i])
		i++;
	if (start && i == stack_a->filled_size)
	{
		i = 0;
		while (i < start && stack_b->tab[0] > stack_a->tab[i])
			i++;
	}
	return (i);
}

void	push_a_from_b(t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	i;

	i = 0;
	count = count_instaction_a(stack_a, stack_b);
	// printf("stackb.num : %d, count : %d\n", stack_b->tab[0], count);
	// printf("-------------\n");
	// i = 0;
	// while (i < stack_a->filled_size)
	// {
	// 	printf("stack_a[%d] = {%d}\n", i, stack_a->tab[i]);
	// 	i++;
	// }
	// printf("-------------\n");
	// i = 0;
	// while (i < stack_b->filled_size)
	// {
	// 	printf("stack_b[%d] = {%d}\n", i, stack_b->tab[i]);
	// 	i++;
	// }

	i = 0;
	if (count == 0)
	{
		push_to_a(stack_a, stack_b);
		ft_putstr("pa\n");
	}
	else if (count <= stack_a->filled_size / 2)
	{
		while (i++ < count)
		{
			rotate_a(stack_a);
			ft_putstr("ra\n");
		}
		push_to_a(stack_a, stack_b);
		ft_putstr("pa\n");
	}
	else if (count > stack_a->filled_size / 2)
	{
		count = stack_a->filled_size - count;
		while (i++ < count)
		{
			reverot_a(stack_a);
			ft_putstr("rra\n");
		}
		push_to_a(stack_a, stack_b);
		ft_putstr("pa\n");
	}
}

void	sorting_from_A_to_B(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < stack_a->filled_size)
	{
		push_a_from_b(stack_a, stack_b);
		i++;
	}
	i = min_num_indx(stack_a->tab, stack_a->filled_size);
	// printf("i = %d, size = %d\n", i, stack_a->filled_size / 2);
	if (i <= stack_a->filled_size / 2)
	{
		while (i--)
		{
			rotate_a(stack_a);
			ft_putstr("ra\n");
		}
	}
	else
	{
		while (stack_a->filled_size - i)
		{
			reverot_a(stack_a);
			ft_putstr("rra\n");
			i++;
		}
	}
}

void	push_swap(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
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
	initialize_stack(&stack_b, ac - 1);
	stack_b.filled_size = 0;
	first_move(&stack_a, &stack_b, ac - 1, mark_head);
	sorting_stack_a(&stack_a);
	sorting_from_A_to_B(&stack_a, &stack_b);
	
/* ************************************************************************** */
	// i = 0;
	// while (stack_a.tab[i])
	// {
	// 	printf("tab_indx = {%d}\ttab[i] = {%d}\n", tab_indx[i], stack_a.tab[i]);
	// 	i++;
	// }
	// i = 0;
	// printf("-------------\n");
	// // printf("  stack_a[i]\t   \tstack_b[i]\n");
	// while (i < stack_a.filled_size)
	// {
	// 	printf("stack_a[%d] = {%d}\n", i, stack_a.tab[i]);
	// 	i++;
	// }
	// printf("-------------\n");
	// i = 0;
	// while (i < stack_b.filled_size)
	// {
	// 	printf("stack_b[%d] = {%d}\n", i, stack_b.tab[i]);
	// 	i++;
	// }
/* ************************************************************************** */
}

int	main(int ac, char **av)
{
	if (ac <= 2)
		ft_error(ac);
	push_swap(ac, av);
}
