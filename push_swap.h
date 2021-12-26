/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:41:35 by msaouab           #+#    #+#             */
/*   Updated: 2021/12/26 09:52:58 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

/* ************************************************************************** */

typedef struct s_stack
{
	int	*tab;
	int	size;
}	t_stack;

/* ************************************************************************** */

void	swap_a(t_stack stack_a);
void	swap_b(t_stack stack_b);
void	swap_ss(t_stack stack_a, t_stack stack_b);
void	push_a(t_stack stack_a, t_stack stack_b);
void	push_b(t_stack stack_a, t_stack stack_b);
void	rotate_a(t_stack stack_a);
void	rotate_b(t_stack stack_b);
void	rot_ab(t_stack stack_a, t_stack stack_b);
void	reverot_a(t_stack stack_a);
void	reverot_b(t_stack stack_b);
void	reverot_ab(t_stack stack_a, t_stack stack_b);

/* ************************************************************************** */

size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
void	ft_error(int n);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif