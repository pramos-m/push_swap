/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations_ss.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:48:23 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/13 16:53:10 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sab(t_stack *stack, char mode)
{
	t_elems	*tmp;

	if (stack->first && stack->first->next)
	{
		if (stack->len == 2)
			stack->last = stack->first;
		tmp = stack->first->next;
		stack->first->next = tmp->next;
		tmp->next = stack->first;
		stack->first = tmp;
		if (mode == 1)
			ft_printf("sa\n");
		else if (mode == 2)
			ft_printf("sb\n");
	}
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->first && stack_b->first)
	{
		ft_sab(stack_a, 0);
		ft_sab(stack_b, 0);
		ft_printf("ss\n");
	}
}
