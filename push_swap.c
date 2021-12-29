/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 03:37:18 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/29 08:16:28 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void align_fuckin_stacks(t_stack *stack_a, t_stack *stack_b, int best_index_to_push_from_b_to_a);

int get_min_number_index(int *tab, int size)
{
	int min;
	int i;
	int min_index = 0;

	i = 1;
	min = tab[0];

	while (i < size)
	{
		if (tab[i] < min)
		{
			min = tab[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int get_max_number_index(int *tab, int size)
{
	int max;
	int i;
	int max_index = 0;

	i = 1;
	max = tab[0];
	while (i < size)
	{
		if (tab[i] > max)
		{
			max = tab[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
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

int get_best_index(int *tab_best_move, int table_size)
{
	int best_moves = tab_best_move[0];
	int best_index = 0;
	int i = 1;

	while (i < table_size)
	{
		if (tab_best_move[i] < best_moves)
			best_index = i;
		i++;
	}
	return (best_index);
}

void rotate_table(int *tab, int size)
{
	int tmp;
	int i;

	if (size == 0)
		return;
	tmp = tab[0];
	i = 0;
	while (i < size - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = tmp;
}

int get_postins_in_stack_a(t_stack stack_a, int number, int i, int *max_and_min_index)
{
	int moves_counts;

	moves_counts = 0;
	if (number > stack_a.tab[max_and_min_index[0]])
	{
		if (max_and_min_index[0] == stack_a.filled_size - 1)
		{
			max_and_min_index[0] = 0;
			moves_counts = i + max_and_min_index[0];
		}
		else
			moves_counts = i + max_and_min_index[0] + 1;
	}
	else if (number > stack_a.tab[max_and_min_index[1]])
	{
		if (max_and_min_index[1] == stack_a.filled_size - 1)
		{
			max_and_min_index[1] = 0;
			moves_counts = i + max_and_min_index[1];
		}
		else
			moves_counts = i + max_and_min_index[1] + 1;
	}
	return (moves_counts);
}

int special_moves(t_stack stack_a, int moves_counts, int number)
{
	int i;
	int max_and_min_index[2];

	i = 0;
	if (moves_counts == 2147483647)
	{
		if (stack_a.tab[0] > number && number > stack_a.tab[stack_a.filled_size - 1])
			moves_counts = i;
		else
		{
			max_and_min_index[0] = get_max_number_index(stack_a.tab, stack_a.filled_size);
			max_and_min_index[1] = get_min_number_index(stack_a.tab, stack_a.filled_size);
			moves_counts = get_postins_in_stack_a(stack_a, number, i, max_and_min_index);
		}
	}
	return (moves_counts);
}

int count_moves_in_stack_a(t_stack stack_a, int number)
{
	int middle_of_stack;

	middle_of_stack = stack_a.filled_size / 2;
	int moves_counts = 2147483647;
	int j = 0;
	while (j < stack_a.filled_size + 1)
	{
		if (stack_a.tab[j] < number && number < stack_a.tab[j + 1])
		{
			if (j == stack_a.filled_size)
				j = 0;
			moves_counts = j + 1;
			break;
		}
		j++;
	}
	moves_counts = special_moves(stack_a, moves_counts, number);
	if (moves_counts > middle_of_stack)
	{
		moves_counts = stack_a.filled_size - moves_counts;
		moves_counts *= -1;
	}
	return (moves_counts);
}

int count_moves_in_stack_b(t_stack stack_b, int index)
{
	int middle_of_stack;

	middle_of_stack = stack_b.filled_size / 2;

	if (index > middle_of_stack)
	{
		index = stack_b.filled_size - index;
		index *= -1;
	}
	return (index);
}

void ft_error(int ac)
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

int *ft_check_dup(int *arr, int size)
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

void initialize_given_stack(t_stack *given_stack, int stack_size)
{
	given_stack->filled_size = 0;
	given_stack->tab = malloc(sizeof(int) * stack_size);
}

int main(int ac, char **av)
{
	t_stack stack_a;
	t_stack stack_b;
	int *tab;
	int i;

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
		// stack_a.tab = malloc(sizeof(int) * (ac - 1));
		initialize_given_stack(&stack_a, ac - 1);
		ft_memcpy(stack_a.tab, tab, (ac - 1) * 4);
		stack_a.filled_size = ac - 1;
		// if (stack_a.filled_size < 10)
		// 	small_stack(&stack_a, &stack_b);
		i = 0;
		// while (i < ac - 1)
		// 	printf("%d\n", stack_a.tab[i++]);
		// while (i < stack_a.filled_size)
		//	printf("%d\n", stack_a.tab[i++]);
		// while (i < ac - 1)
		// {
		// 	printf(" %d ", stack_a.tab[i]);
		// 	i++;
		// }
		// printf("\n");

		int *ordered_table = set_index(stack_a.tab, ac - 1);

		///// push false to stack b

		i = 0;
		initialize_given_stack(&stack_b, ac - 1);
		stack_b.filled_size = 0;
		int counter = 0;
		int initial_size_of_stack_a = stack_a.filled_size;
		while (counter < initial_size_of_stack_a)
		{
			if (ordered_table[0] == 0)
			{
				push_to_b(&stack_a, &stack_b);
				ft_putstr("pb\n");
				ordered_table[0] = 1;
				rotate_table(ordered_table, ac - 1);
			}
			else
			{
				rotate_a(&stack_a);
				ft_putstr("ra\n");
				rotate_table(ordered_table, ac - 1);
			}
			counter++;
		}
		// printf("\n\n stack a\n");
		// i = 0;
		// while (i < stack_a.filled_size)
		// {
		// 	printf("tab[%d] = %d\n", i, stack_a.tab[i]);
		// 	i++;
		// }

		// printf("\n\n stack b\n");
		// i = 0;
		// while (i < stack_b.filled_size)
		// {
		// 	printf("tab[%d] = %d\n", i, stack_b.tab[i]);
		// 	i++;
		// }

		// printf("filled a : %d   | filled b : %d \n", stack_a.filled_size, stack_b.filled_size);

		///// choose the best from stack b element to push to  stack a

		while (stack_b.filled_size > 0)
		{
			i = 0;

			int *tab_best_move = (int *)malloc(sizeof(int) * stack_b.filled_size);
			int tmp_moves_in_b = 0;
			int tmp_moves_in_a = 0;

			while (i < stack_b.filled_size)
			{
				tab_best_move[i] = 2147483647;
				i++;
			}
			i = 0;

			while (i < stack_b.filled_size)
			{
				tmp_moves_in_a = count_moves_in_stack_b(stack_b, i);
				tmp_moves_in_b = count_moves_in_stack_a(stack_a, stack_b.tab[i]);
				if (tmp_moves_in_a < 0)
					tmp_moves_in_a *= -1;
				if (tmp_moves_in_b < 0)
					tmp_moves_in_b *= -1;
				tab_best_move[i] = tmp_moves_in_a + tmp_moves_in_b;
				// printf("before best : count_moves_in_stack_a %d \n", tab_best_move[i]);
				i++;
			}

			// i = 0;
			// printf("\nbest_move\n");
			// while (i < stack_b.filled_size)
			// {
			// 	printf("best_move[%d] = %d\n", i, tab_best_move[i]);
			// 	i++;
			// }

			////// align both stacks

			int best_index_to_push_from_b_to_a = get_best_index(tab_best_move, stack_b.filled_size);

			// printf("\nbest_index_to_push_from_b_to_a : %d \n", best_index_to_push_from_b_to_a);
			align_fuckin_stacks(&stack_a, &stack_b, best_index_to_push_from_b_to_a);
			push_to_a(&stack_a, &stack_b);
			ft_putstr("pa\n");
		}
	}

	///// sort_stack_a

	int count_moves_stack_a_final = get_min_number_index(stack_a.tab, stack_a.filled_size);

	//printf(" ---- > min %d \n", count_moves_stack_a_final);
	while (count_moves_stack_a_final > 0)
	{
		rotate_a(&stack_a);
		ft_putstr("ra\n");
		count_moves_stack_a_final--;
	}
	while (count_moves_stack_a_final < 0)
	{
		reverot_a(&stack_a);
		ft_putstr("rra\n");
		count_moves_stack_a_final++;
	}
/*
	printf("\n\n stack a\n");
	i = 0;
	while (i < stack_a.filled_size)
	{
		printf("stack_a[%d] = %d\n", i, stack_a.tab[i]);
		i++;
	}
	printf("\n\n stack b\n");
	i = 0;
	while (i < stack_b.filled_size)
	{
		printf("stack_b[%d] = %d\n", i, stack_b.tab[i]);
		i++;
	}
	*/
}

void align_fuckin_stacks(t_stack *stack_a, t_stack *stack_b, int best_index_to_push_from_b_to_a)
{
	int moves_in_stack_a = count_moves_in_stack_a(*stack_a, stack_b->tab[best_index_to_push_from_b_to_a]);
	int moves_in_stack_b = count_moves_in_stack_b(*stack_b, best_index_to_push_from_b_to_a);
/*
	printf("\n\n     before align stack stack a\n");
	int i = 0;
	while (i < stack_a->filled_size)
	{
		printf("tab[%d] = %d\n", i, stack_a->tab[i]);
		i++;
	}

	printf("\n\n stack b\n");
	i = 0;
	while (i < stack_b->filled_size)
	{
		printf("tab[%d] = %d\n", i, stack_b->tab[i]);
		i++;
	}

	printf("align stacks number : %d  |   a  %d |  b  %d \n", stack_b->tab[best_index_to_push_from_b_to_a], moves_in_stack_a, moves_in_stack_b);
*/
	if (moves_in_stack_a != 0 && moves_in_stack_b != 0)
	{
		if (moves_in_stack_b * moves_in_stack_a > 0)
		{
			if (moves_in_stack_a > 0 && moves_in_stack_b > 0)
			{
				while (moves_in_stack_a > 0 && moves_in_stack_b > 0)
				{
					rot_ab(stack_a, stack_b);
					ft_putstr("rr\n");
					moves_in_stack_b--;
					moves_in_stack_a--;
				}
				while (moves_in_stack_a > 0)
				{
					rotate_a(stack_a);
					ft_putstr("ra\n");
					moves_in_stack_a--;
				}
				while (moves_in_stack_b > 0)
				{
					rotate_b(stack_b);
					ft_putstr("rb\n");
					moves_in_stack_b--;
				}
			}
			else
			{
				while (moves_in_stack_a < 0 && moves_in_stack_b < 0)
				{
					reverot_ab(stack_a, stack_b);
					ft_putstr("rrr\n");
					moves_in_stack_b++;
					moves_in_stack_a++;
				}
				while (moves_in_stack_a < 0)
				{
					reverot_a(stack_a);
					ft_putstr("rra\n");
					moves_in_stack_a++;
				}
				while (moves_in_stack_b < 0)
				{
					reverot_b(stack_b);
					ft_putstr("rrb\n");
					moves_in_stack_b++;
				}
			}
		}
		else
		{
			while (moves_in_stack_a < 0 && moves_in_stack_b < 0)
			{
				reverot_ab(stack_a, stack_b);
				ft_putstr("rrr\n");
				moves_in_stack_b++;
				moves_in_stack_a++;
			}

			while (moves_in_stack_a > 0)
			{
				rotate_a(stack_a);
				ft_putstr("ra\n");
				moves_in_stack_a--;
			}
			while (moves_in_stack_b > 0)
			{
				rotate_b(stack_b);
				ft_putstr("rb\n");
				moves_in_stack_b--;
			}
			while (moves_in_stack_a < 0)
			{
				reverot_a(stack_a);
				ft_putstr("rra\n");
				moves_in_stack_a++;
			}
			while (moves_in_stack_b < 0)
			{
				reverot_b(stack_b);
				ft_putstr("rrb\n");
				moves_in_stack_b++;
			}
		}
	}
	else
	{
		while (moves_in_stack_a > 0)
		{
			rotate_a(stack_a);
			ft_putstr("ra\n");
			moves_in_stack_a--;
		}
		while (moves_in_stack_a < 0)
		{
			reverot_a(stack_a);
			ft_putstr("rra\n");
			moves_in_stack_a++;
		}
		while (moves_in_stack_b > 0)
		{
			rotate_b(stack_b);
			ft_putstr("rb\n");
			moves_in_stack_b--;
		}
		while (moves_in_stack_b < 0)
		{
			reverot_b(stack_b);
			ft_putstr("rrb\n");
			moves_in_stack_b++;
		}
	}
}
