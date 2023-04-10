/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:02 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/16 18:00:23 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_cut(t_stack *b, int idx, int cut)
{
	if (idx < cut / 2)
	{
		ft_rab(b, 2);
	}
}

int	ft_bigger_idx(t_stack *stack)
{
	t_elems	*tmp;
	int		idx;

	tmp = stack->first;
	idx = stack->len - 1;
	while (tmp->next)
	{
		if (tmp->idx == idx)
			return (tmp->idx);
		tmp = tmp->next;
	}
	if (tmp->idx == idx)
		return (tmp->idx);
	return (idx);
}

int	ft_where_to_move(t_stack *stack, int big_idx, ssize_t *movements)
{
	int		pos;
	int		half;
	t_elems	*first;

	first = stack->first;
	pos = 0;
	half = stack->len / 2;
	pos = ft_check_first(first, pos, big_idx);
	if (pos == 0)
		return (ONTOP);
	else if (pos < half)
	{
		*movements = pos;
		return (ROT);
	}
	else if (pos >= half)
	{
		*movements = stack->len - pos;
		return (RROT);
	}
	return (ERR_NUM);
}

void	ft_sort_aux(t_stack *a, t_stack *b, int cut)
{
	while (a->len)
	{
		ft_pab(a, b, 2);
		ft_sort_cut(b, b->first->idx, cut);
	}
	ft_indexer(b);
	ft_backto_a(a, b);
}
