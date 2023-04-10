/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:25:27 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/17 16:47:37 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_valid_params(int params, char **str)
{
	if (!ft_check_isdigit(params, str))
		ft_error(ERRCODE1);
	if (!ft_check_dups(params, str))
		ft_error(ERRCODE1);
	if (ft_check_order(params, str))
		exit(EXIT_SUCCESS);
}

int	ft_check_isdigit(int params, char **str)
{
	int		i;
	t_ll	tmpnbr;

	i = 0;
	while (++i < params)
	{
		if (!ft_while_is_digit(str[i]) || !ft_is_int(str[i]))
			return (0);
		tmpnbr = ft_atol(str[i]);
		if (!ft_check_maxint(tmpnbr))
			return (0);
	}
	return (1);
}

int	ft_check_dups(int nbr, char **str)
{
	ssize_t	i;
	ssize_t	j;
	t_ll	nbr1;
	t_ll	nbr2;

	i = 0;
	while (++i < nbr)
	{
		j = i;
		nbr1 = ft_atol(str[i]);
		while (++j < nbr)
		{
			nbr2 = ft_atol(str[j]);
			if (nbr1 == nbr2)
				return (0);
		}
	}
	return (1);
}

int	ft_check_order(int nbr, char **str)
{
	ssize_t	idx;
	t_ll	nbr1;
	t_ll	nbr2;

	idx = 0;
	--nbr;
	while (++idx < nbr)
	{
		nbr1 = ft_atol(str[idx]);
		nbr2 = ft_atol(str[idx + 1]);
		if (nbr1 > nbr2)
			return (0);
	}
	return (1);
}

int	ft_is_int(char *num)
{
	int			i;
	long long	tmp;

	i = 0;
	if (!num || !*num)
		return (0);
	if (ft_strchr("+-", num[i]))
		i++;
	while (num[i] && num[i] == '0')
		i++;
	if (!num[i])
		i--;
	if (ft_strlen(&num[i]) > 10)
		return (0);
	tmp = ft_atol(num);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (0);
	return (1);
}
