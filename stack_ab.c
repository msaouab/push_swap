/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 01:19:09 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/29 03:50:39 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	rot_ab(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putstr("rr\n");
}

void	reverot_ab(t_stack *stack_a, t_stack *stack_b)
{
	reverot_a(stack_a);
	reverot_b(stack_b);
	ft_putstr("rrr\n");
}
