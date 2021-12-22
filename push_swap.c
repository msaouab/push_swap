/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:41:32 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/22 01:00:08 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_error_int()
{
	write(1, "error", 5);
	exit(1);
}

void	ft_error_arg()
{
	write(1, "not enough args", 15);
	exit(1);
}

int	ft_check_str(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			return (1);
		else
			ft_error_int();
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		tab[ac];
	int		i;

	if (ac <= 1)
		ft_error_arg();
	else if (ac == 2)
		return (0);
	else
	{
		i = 1;
		while (av[i])
		{
			if (ft_check_str(av[i]) == 1)
				tab[i] = ft_atoi(av[i]);
			i++;
		}
	}
}