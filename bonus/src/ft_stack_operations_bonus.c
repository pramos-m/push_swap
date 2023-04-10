/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_operations_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:48:23 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:32 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_pab(t_stack *stack_dest, t_stack *stack_origin)
{
	t_elems	*tmp;

	if (stack_origin->len == 0)
		return ;
	tmp = stack_origin->first;
	if (stack_origin->len != 1)
		stack_origin->first = stack_origin->first->next;
	tmp->next = stack_dest->first;
	stack_dest->first = tmp;
	if (stack_origin->len == 1)
	{
		stack_origin->first = NULL;
		stack_origin->last = NULL;
	}
	else if (stack_dest->len < 1)
	{
		stack_dest->last = tmp;
		stack_dest->first->next = NULL;
	}
	stack_origin->len--;
	stack_dest->len++;
}

void	ft_rab(t_stack *stack)
{
	t_elems	*tmp;

	if (stack->first && stack->first->next && stack->len > 0)
	{
		tmp = stack->first;
		stack->first = stack->first->next;
		tmp->next = NULL;
		stack->last->next = tmp;
		stack->last = tmp;
	}
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rab(stack_a);
	ft_rab(stack_b);
}

void	ft_rrab(t_stack *stack)
{
	t_elems	*tmp;
	t_elems	*tmp2;

	if (stack->first && stack->first->next)
	{
		tmp = stack->first;
		tmp2 = tmp->next;
		while (tmp2->next)
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
		tmp->next = NULL;
		tmp2->next = stack->first;
		stack->first = tmp2;
		stack->last = tmp;
	}
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->first && stack_b->first)
	{
		ft_rrab(stack_a);
		ft_rrab(stack_b);
	}
}
