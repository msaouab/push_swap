/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 03:37:18 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/27 10:48:57 by msaouab          ###   ########.fr       */
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
		write(1, "??\n", 4);
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


int	main(int ac, char **av)
{
	t_stack	stack_a;
	// t_stack	stack_b;
	int		*tab;
	int		i;

	if (ac <= 2)
		ft_error(ac);
	if (ac > 2)
	{
		tab = malloc(sizeof(int) * ac - 1);
		i = 0;
		while (av[i + 1])
		{
			tab[i] = ft_atoi(av[i + 1]);
			i++;
		}
		ft_check_dup(tab, ac - 1);
		stack_a.tab = malloc(sizeof(int) * (ac - 1));
		ft_memcpy(stack_a.tab, tab, (ac - 1) * 4);
		i = 0;
		while (i < ac - 1)
			printf("%d\n", stack_a.tab[i++]);
	}
}
