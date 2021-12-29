/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tab_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:31:45 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/29 06:46:15 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int get_min_number_index(int *tab, int size)
{
	int min;
	int i;

	i = 1;
	min = tab[0];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int get_max_number_index(int *tab, int size)
{
	int max;
	int i;

	i = 1;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int get_index_of_number(int *tab, int size, int number)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == number)
			return (i);
		i++;
	}
	return (0);
}
*/
int *set_index(int *tab, int size)
{
	int *tab_index;
	int i;
	int j;
	int count = 0;

	tab_index = malloc(sizeof(int) * size);

	i = 0;
	while (i < size)
	{
		tab_index[i] = 0;
		j = i + 1;
		if (j == size)
			j = 0;
		// j = j % size;
		count = 0;
		while (count < size - 1)
		{
			if (tab[j] < tab[i])
				tab_index[i]++;
			j++;
			if (j == size)
				j = 0;
			// j = j % size;
			count++;
		}
		i++;
	}
	i = 0;
	//while (i < size)
	//{
	//	printf("tab_index[%d] = %d\n", i, tab_index[i]);
	//	i++;
	//}
//
	i = 0;
	count = 0;
	int min_index = get_min_number_index(tab_index, size);
	int *order_tab = (int *)malloc(sizeof(int) * size);
	while (count < size)
	{
		order_tab[count] = false;
		count++;
	}
	/*
	j = min_index + 1;
	j %= size;
	while (count < size - 1)
	{
		if (tab_index[j] == index)
		{
			order_tab[j] = true;
			index++;
		}
		j++;
		j %= size;
		// if (j == size)
		// 	j = 0;
		count++;
	}*/
	//printf("min index : %d\n", min_index);
	j = min_index + 1;
	order_tab[min_index] = true;
	j %= size;
	int index = tab_index[min_index] + 1;
	// int tmp = index;
	count = 0;
	while (count < size - 1)
	{
		if (tab_index[j] == index)
		{
			order_tab[j] = true;
			index++;
		}
		j++;
		count++;
		if (j == size)
			j = 0;
	}
	i = 0;
	//printf("\n\n\n");
	//while (i < size)
	//{
	//	printf("order_tab[%d] = %s\n", i, order_tab[i] == 1 ? "true" : "false");
	//	i++;
	//}
	return order_tab;
}
