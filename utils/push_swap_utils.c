/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:29:18 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/13 16:18:13 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_while_is_digit(char *num)
{
	int	i;

	i = 0;
	if ((num[0] == '-' || num[0] == '+') && num[1])
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
			i++;
	}
	return (1);
}

int	ft_check_maxint(t_ll nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

int	ft_issorted(t_stack *a)
{
	t_elems	*tmp;

	if (!a->first)
		return (0);
	tmp = a->first;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_find_smallest(t_stack *a)
{
	t_elems	*tmp;
	int		smallest;

	smallest = 0;
	tmp = a->first;
	while (tmp)
	{
		if (tmp->idx == 0)
			break ;
		smallest++;
		tmp = tmp->next;
	}
	return (smallest);
}

ssize_t	ft_check_first(t_elems *first, ssize_t pos, int nbr)
{
	while (first)
	{
		if (first->idx == nbr)
			break ;
		++pos;
		first = first->next;
	}
	return (pos);
}
