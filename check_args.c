/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:06:51 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/15 00:36:36 by msaouab          ###   ########.fr       */
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

int	ft_check_str(char *str, int i)
{
	int	res;

	res = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	if (str[i] != '\0')
		ft_error(1);
	return (res);
}

int	ft_atoi(char *str)
{
	long	i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	res = ft_check_str(str, i);
	return (res * sign);
}
