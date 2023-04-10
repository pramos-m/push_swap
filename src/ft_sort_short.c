/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:18:30 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/13 17:37:53 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stack *a)
{
	if (ft_issorted(a))
		return ;
	if ((a->first->val) < (a->first->next->val))
		ft_rrab(a, 1);
	else if ((a->first->val) > (a->first->next->next->val))
		ft_rab(a, 1);
	if (!ft_issorted(a))
		ft_sab(a, 1);
}

void	ft_sort_four(t_stack *a, t_stack *b)
{
	size_t	idx;

	idx = ft_find_smallest(a);
	if (idx == 1)
		ft_sab(a, 1);
	else if (idx == 2)
	{
		ft_rab(a, 1);
		ft_rab(a, 1);
	}
	else if (idx == 3)
	{
		ft_rrab(a, 1);
	}
	if (!ft_issorted(a))
	{
		ft_pab(b, a, 2);
		ft_indexer(a);
		ft_sort_three(a);
		ft_pab(a, b, 1);
		ft_indexer(a);
	}
}

void	ft_sort_five(t_stack *a, t_stack *b)
{
	ssize_t	idx;

	idx = ft_find_smallest(a);
	if (idx == 1)
		ft_sab(a, 1);
	else if (idx == 2)
	{
		ft_rab(a, 1);
		ft_sab(a, 1);
	}
	else if (idx == 3)
	{
		ft_rrab(a, 1);
		ft_rrab(a, 1);
	}
	else if (idx == 4)
		ft_rrab(a, 1);
	if (!ft_issorted(a))
	{
		ft_pab(b, a, 2);
		ft_indexer(a);
		ft_sort_four(a, b);
		ft_pab(a, b, 1);
		ft_indexer(a);
	}
}
