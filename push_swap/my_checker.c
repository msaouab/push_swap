/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 01:05:06 by msaouab           #+#    #+#             */
/*   Updated: 2022/01/16 08:21:57 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_checker(t_stack *stack_a, t_stack *stack_b, int fulllen)
{
	int	i;
	int	j;

	i = 0;
	j = stack_a->filled_size;
	while (i + 1 < j && stack_a->tab[i] < stack_a->tab[i + 1])
		i++;
	if (i + 1 == stack_a->filled_size)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	if (i + 1 != fulllen)
		free(stack_b->tab);
	free(stack_a->tab);
}

void	check_actions(t_stack *stack_a, t_stack *stack_b, char *act)
{
	if (ft_strncmp(act, "sa\n", 3) == 0)
		swap_a_checker(stack_a);
	else if (ft_strncmp(act, "sb\n", 3) == 0)
		swap_a(stack_b);
	else if (ft_strncmp(act, "ss\n", 3) == 0)
		swap_ss(stack_a, stack_b);
	else if (ft_strncmp(act, "ra\n", 3) == 0)
		rotate_a(stack_a);
	else if (ft_strncmp(act, "rb\n", 3) == 0)
		rotate_a(stack_b);
	else if (ft_strncmp(act, "rr\n", 3) == 0)
		rotate_ab(stack_a, stack_b);
	else if (ft_strncmp(act, "rra\n", 4) == 0)
		reverot_a(stack_a);
	else if (ft_strncmp(act, "pa\n", 3) == 0)
		push_to_a(stack_a, stack_b);
	else if (ft_strncmp(act, "pb\n", 3) == 0)
		push_to_b(stack_a, stack_b);
	else if (ft_strncmp(act, "rrb\n", 4) == 0)
		reverot_b(stack_b);
	else if (ft_strncmp(act, "rrr\n", 4) == 0)
		reverot_ab(stack_a, stack_b);
	else
		ft_error(1);
}

void	check_instructions(int *tab, int size)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*actions;
	int		i;

	i = 0;
	initialize_stack(&stack_a, size);
	initialize_stack(&stack_b, size);
	ft_memcpy(stack_a.tab, tab, (size) * 4);
	stack_a.filled_size = size;
	stack_b.filled_size = 0;
	actions = get_next_line(STDIN_FILENO);
	while (actions)
	{
		check_actions(&stack_a, &stack_b, actions);
		free(actions);
		actions = NULL;
		actions = get_next_line(STDIN_FILENO);
	}
	sorting_checker(&stack_a, &stack_b, size);
}

void	checker(char **str, int size)
{
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * (size));
	i = 0;
	while (str[i])
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	ft_check_dup(tab, size);
	check_instructions(tab, size);
	free(tab);
}

int	main(int ac, char **av)
{
	if (ac == 0)
		exit(0);
	checker(av + 1, ac - 1);
	return (0);
}
