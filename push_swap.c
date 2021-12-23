/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:41:32 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/23 04:56:00 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error(int n)
{
	if (n <= 1)
	{
		write(1, "not enough args", 15);
		exit(1);
	}
	if (n == 2)
		exit (0);
	if (n == 65 || n == 48)
	{
		write(1, "error", 5);
		exit(1);
	}
}

// char	*ft_check_str(char *arg)
// {
// 	int	i;

// 	i = 0;
// 	while (arg[i])
// 	{
// 		if (arg[i] == '-')
// 			i++;
// 		if (arg[i] >= '0' && arg[i] <= '9')
// 			ft_error(65);
// 		else if (arg[i] <= '0' && arg[i] >= '9')
// 			ft_error(65);
// 		i++;
// 	}
// 	return (arg);
// }

int	*ft_check_dup(int *arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (arr[i] == arr[j])
				ft_error(48);
			j++;
		}
		i++;
	}
	return (arr);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a = NULL;
	// t_stack	*stack_b;
	int		*arr;
	int		i;

	arr = 0;
			// i = 2;÷
			// while (av[i])
	if (ac <= 2)
		ft_error(ac);
	else
	{
		stack_a = (t_stack *)malloc(sizeof(t_stack) * (ac + 1));
		if (!stack_a->tab)
			return (0);
		i = 1;
		while (av[i])
		{
			// if (ft_check_str(av[i]) == 1)
				arr = ft_atoi(av[i]);
				ft_check_dup(arr);
				printf("%d\n", ft_check_dup(arr);
			i++;
		}
	}
}
