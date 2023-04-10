/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations_ss_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:48:23 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/17 15:31:08 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sab(t_stack *stack)
{
	t_elems	*tmp;

	if (stack->first && stack->first->next && stack->len > 0)
	{
		if (stack->len == 2)
			stack->last = stack->first;
		tmp = stack->first->next;
		stack->first->next = tmp->next;
		tmp->next = stack->first;
		stack->first = tmp;
	}
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_sab(stack_a);
	ft_sab(stack_b);
}
