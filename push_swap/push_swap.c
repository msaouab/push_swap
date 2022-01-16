/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 00:02:13 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/15 20:49:40 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	help_to_find_perfect_group(int *tab, int size, int i)
{
	int	count;
	int	traverse;
	int	per_grp;
	int	j;

	traverse = 0;
	count = 1;
	j = i;
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
	if (ac == 1)
		ft_error(1);
	push_swap(ac - 1, av + 1);
}
