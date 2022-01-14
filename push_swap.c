/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:02:13 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/14 22:51:03 by msaouab          ###   ########.fr       */
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
	{
		write(1, "error\n", 6);
		exit(0);
	}
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

void	ft_free(int *tab)
{
	free(tab);
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

int	*true_false(int *tab, int size, int indx)
{
	int i;
	int tmp;
	int	*tab_to_detect;

	tab_to_detect = malloc(sizeof(int) * size);
	i = indx;
	tmp = tab[indx];
	while (i < size)
	{
		if (tmp < tab[i])
		{
			tab_to_detect[i] = TRUE;
			tmp = tab[i];
		}
		else
			tab_to_detect[i] = FALSE;
		i++;
	}
	i = 0;
	while (indx && i < indx)
	{
		if (tab[i] > tmp)
		{
			tab_to_detect[i] = TRUE;
			tmp = tab[i];
		}
		else
			tab_to_detect[i] = FALSE;
		i++;
	}
	tab_to_detect[indx] = TRUE;
	return (tab_to_detect);
}

void	first_move(t_stack *stack_a, t_stack *stack_b, int *head)
{
	int	i;
	int	counter;
	int	initial_size_of_stack_a;

	counter = 0;
	initial_size_of_stack_a = stack_a->filled_size;
	while (counter < initial_size_of_stack_a)
	{
		if (head[counter] == 0)
		{
			push_to_b(stack_a, stack_b);
			ft_putstr("pb\n");
			counter++;
		}
		else
		{
			i = 0;
			while (head[counter])
			{
				i++;
				counter++;
			}
			if (counter == initial_size_of_stack_a)
				i = 0;
			if (i <= stack_a->filled_size / 2)
			{
				while (i)
				{
					rotate_a(stack_a);
					ft_putstr("ra\n");
					i--;
				}
			}
			else
			{
				while (i < stack_a->filled_size)
				{
					reverot_a(stack_a);
					ft_putstr("rra\n");
					i++;
				}
			}
		}
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
			ft_putstr("ra\n");
			min_index--;
		}
	}
	else
	{
		while (min_index < stack_a->filled_size)
		{
			reverot_a(stack_a);
			ft_putstr("rra\n");
			min_index++;
		}
	}
}

int	*perfect_groups(int *tab, int size)
{
	int	*tab_groups;
	int	*tab_true;
	int	per_grp;
	int	index;
	int	count;
	int	i;
	int	j;

	tab_groups = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		count = 1;
		j = i + 1;
		per_grp = tab[i];
		while (j < size)
		{
			if (per_grp < tab[j])
			{
				per_grp = tab[j];
				count++;
			}
			j++;
		}
		j = 0;
		while (j < i)
		{
			if (per_grp < tab[j])
			{
				per_grp = tab[j];
				count++;
			}
			j++;
		}
		tab_groups[i] = count;
		i++;
	}
	index = max_num_indx(tab_groups, size);
	tab_true = true_false(tab, size, index);





// 	i = 0;
// 	printf("indx = %d\n", index);
// 	printf("tab_groups[%d] = %d\n", index, tab_groups[index]);
// 	printf("count +++++++++= = %d\n", count);

// count = 0;
// 	while (i < size)
// 	{
// 		if (i == index)
// 			printf("---------");
// 		if (tab_true[i] == 1)
// 			count++;
// 		printf("tab_true = %d \t \t tab_groups = %d \t \t tab[i] = %d\n", tab_true[i], tab_groups[i], tab[i]);
// 		i++;
// 	}
// 	printf("----------------------------------------\ncount = %d \n----------------------------------------------\n", count);




	
	ft_free(tab_groups);
	return (tab_true);
}

void	push_swap(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*tab_indx;
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
	tab_indx = set_index(stack_a.tab, ac);
	mark_head = perfect_groups(stack_a.tab, stack_a.filled_size);
	initialize_stack(&stack_b, ac);
	stack_b.filled_size = 0;
	first_move(&stack_a, &stack_b, mark_head);
	recuvery_data_from_b(&stack_a, &stack_b);
	sorting_stack_a(&stack_a);
	ft_free(stack_b.tab);
	ft_free(tab);
	ft_free(tab_indx);
	ft_free(mark_head);
	ft_free(stack_a.tab);
/* ************************************************************************** */
	// i = 0;
	// printf("-----------------------\n");
	// while (i < stack_a.filled_size)
	// {
	// 	printf("||stack_a[%d] = {%d}\n", i, stack_a.tab[i]);	
	// 	i++;
	// }
	// printf("-----------------------\n");
/* ************************************************************************** */
}

int	main(int ac, char **av)
{
	if (ac < 2)
		ft_error(ac);
	push_swap(ac - 1, av + 1);
}
