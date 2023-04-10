/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:17:00 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/17 18:01:15 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	ft_check_valid_params(ac, av);
	ft_init_stack_a(&a, ac, av);
	ft_init_stack_b(&b);
	ft_checking(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}

void	ft_checking(t_stack *a, t_stack *b)
{
	char	*str;
	char	*res;
	int		moves;

	res = "OK";
	moves = 0;
	str = get_next_line(0);
	while (str)
	{
		if (!ft_check_move(str, a, b))
			ft_exit(1, a, b);
		ft_free(&str, 2);
		moves++;
		str = get_next_line(0);
	}
	ft_free(&str, 2);
	if (!ft_issorted(a) || b->len > 0
		|| !ft_number_moves(a, moves))
		res = "KO";
	if (ft_printf("\n%s\n", res) == -1)
		ft_exit(1, a, b);
}

int	ft_check_move(char *str, t_stack *a, t_stack *b)
{
	char	**lst_mv;
	char	*moves;
	int		i;

	i = -1;
	moves = "sa\n sb\n ss\n ra\n rb\n rr\n pa\n pb\n rra\n rrb\n rrr\n";
	lst_mv = ft_split(moves, ' ');
	if (!lst_mv)
		return (0);
	while (lst_mv[++i])
	{
		if (!ft_strncmp(str, lst_mv[i], ft_strlen(str)))
		{
			ft_execute_move(lst_mv[i], a, b);
			ft_free(lst_mv, 1);
			return (1);
		}
	}
	ft_free(lst_mv, 1);
	return (0);
}

void	ft_execute_move(char *move, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa\n", move, ft_strlen(move)))
		ft_sab(a);
	else if (!ft_strncmp("sb\n", move, ft_strlen(move)))
		ft_sab(b);
	else if (!ft_strncmp("ss\n", move, ft_strlen(move)))
		ft_ss(a, b);
	else if (!ft_strncmp("ra\n", move, ft_strlen(move)))
		ft_rab(a);
	else if (!ft_strncmp("rb\n", move, ft_strlen(move)))
		ft_rab(b);
	else if (!ft_strncmp("rra\n", move, ft_strlen(move)))
		ft_rrab(a);
	else if (!ft_strncmp("rrb\n", move, ft_strlen(move)))
		ft_rrab(b);
	else if (!ft_strncmp("pb\n", move, ft_strlen(move)))
		ft_pab(b, a);
	else
		ft_pab(a, b);
}

int	ft_number_moves(t_stack *a, int c_moves)
{
	if (a->len == 2 && c_moves > 1)
		return (0);
	else if (a->len == 3 && c_moves > 3)
		return (0);
	else if (a->len < 6 && c_moves > 12)
		return (0);
	else if (a->len <= 100 && c_moves >= 1500)
		return (0);
	else if (a->len <= 500 && c_moves >= 11500)
		return (0);
	return (1);
}
