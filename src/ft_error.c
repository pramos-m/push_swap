/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:16:50 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/17 16:51:26 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_error(int num)
{
	if (num == ERRCODE0)
		write(STDERR_FILENO, ERR_MSG0, ft_strlen(ERR_MSG0));
	else if (num == ERRCODE1)
		write(STDERR_FILENO, ERR_MSG1, ft_strlen(ERR_MSG1));
	else if (num == ERRCODE2)
		write(STDERR_FILENO, ERR_MSG2, ft_strlen(ERR_MSG2));
	exit(EXIT_FAILURE);
}

void	ft_stack_clear(t_stack *s)
{
	t_elems	*tmp;

	while (s->first)
	{
		tmp = s->first->next;
		free(s->first);
		s->first = NULL;
		s->first = tmp;
	}
}

void	ft_clean(t_stack *s)
{
	ft_stack_clear(s);
	ft_error(ERRCODE2);
}
