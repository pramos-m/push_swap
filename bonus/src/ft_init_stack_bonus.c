/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:55:36 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/13 17:55:08 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_elems	*ft_newnode(int nbr)
{
	t_elems	*new;

	new = (t_elems *)malloc(sizeof(t_elems));
	if (!new)
		return (NULL);
	new->val = nbr;
	new->idx = 0;
	new->next = NULL;
	return (new);
}

void	ft_init_stack_a(t_stack *a, int params, char **str)
{
	t_elems	*lst;
	t_elems	*tmp;

	a->len = -1;
	a->first = NULL;
	a->last = NULL;
	while (++a->len < params -1)
	{
		lst = ft_newnode(ft_atol(str[a->len + 1]));
		if (!lst)
			return (ft_clean(a));
		if (!a->last)
		{
			a->first = lst;
			a->last = lst;
		}
		else
		{
			tmp = a->last;
			a->last = lst;
			tmp->next = a->last;
		}
	}
	ft_indexer(a);
}

void	ft_init_stack_b(t_stack *b)
{
	b->len = 0;
	b->first = NULL;
	b->last = NULL;
}

void	ft_indexer(t_stack *stack)
{
	t_elems	*tmp;
	t_elems	*current_stack;
	ssize_t	idx;
	ssize_t	count;

	current_stack = stack->first;
	count = -1;
	while (current_stack)
	{
		idx = 0;
		tmp = stack->first;
		while (tmp)
		{
			if (current_stack->val > tmp->val)
				idx++;
			tmp = tmp->next;
		}
		current_stack->idx = idx;
		current_stack = current_stack->next;
	}
}
