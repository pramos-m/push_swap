/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:20:02 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/13 16:29:43 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting_massive(t_stack *a, t_stack *b, int chunks)
{
	int	idx;
	int	count;
	int	cut;

	count = 0;
	cut = a->len / chunks;
	while (a->first && count++ <= chunks)
	{
		idx = 0;
		while (a->first && idx < cut)
		{
			if (a->first && a->first->idx < cut)
			{
				ft_pab(b, a, 2);
				ft_sort_cut(b, b->first->idx, cut);
				idx++;
			}
			else
				ft_rab(a, 1);
		}
		ft_indexer(a);
	}
	ft_sort_aux(a, b, cut);
}

void	ft_backto_a(t_stack *a, t_stack *b)
{
	while (b->len)
	{
		put_first_b(ft_bigger_idx(b), a, b);
		ft_pab(a, b, 1);
		ft_indexer(a);
		if (a->len >= 2 && a->first->next->idx == (a->first->idx - 1))
			ft_sab(a, 1);
	}
}

void	put_first_b(int big_idx, t_stack *a, t_stack *b)
{
	ssize_t	movements;
	ssize_t	mov;

	movements = 0;
	mov = ft_where_to_move(b, big_idx, &movements);
	if (mov == ONTOP || mov == ERR_NUM)
		return ;
	if (mov == ROT)
		ft_putfirst_b1_aux(a, b, big_idx, movements);
	if (mov == RROT)
		ft_putfirst_b2_aux(a, b, big_idx, movements);
}

void	ft_putfirst_b1_aux(t_stack *a, t_stack *b, int nbr, ssize_t mov)
{
	ssize_t	idx;

	idx = 0;
	while (b->first && ++idx <= mov)
	{
		if (b->first->idx == (nbr))
			ft_pab(a, b, 1);
		else if (b->first->idx == (nbr - 1))
			ft_pab(a, b, 1);
		else
			ft_rab(b, 2);
	}
}

void	ft_putfirst_b2_aux(t_stack *a, t_stack *b, int nbr, ssize_t mov)
{
	ssize_t	idx;
	int		flag;

	idx = 0;
	flag = 0;
	while (b->len > 1 && ++idx <= mov)
	{
		if (b->first->idx == (nbr))
		{
			ft_pab(a, b, 1);
			if (flag)
				ft_sab(a, 1);
			flag = 0;
			mov++;
		}
		else if (b->first->idx == (nbr - 1))
		{
			ft_pab(a, b, 1);
			flag = 1;
			mov++;
		}
		else
			ft_rrab(b, 2);
	}
}
