/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:17:00 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/17 17:00:05 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac <= 1)
		return (0);
	ft_check_valid_params(ac, av);
	ft_init_stack_a(&a, ac, av);
	ft_init_stack_b(&b);
	ft_check_sort(&a, &b);
	ft_stack_clear(&a);
	ft_stack_clear(&b);
	return (0);
}

void	ft_check_sort(t_stack *a, t_stack *b)
{
	if (a->len == 2)
		ft_sab(a, 1);
	else if (a->len == 3)
		ft_sort_three(a);
	else if (a->len == 4)
		ft_sort_four(a, b);
	else if (a->len == 5)
		ft_sort_five(a, b);
	else if (a->len <= 20)
		ft_sorting_massive(a, b, 2);
	else if (a->len <= 100)
		ft_sorting_massive(a, b, 4);
	else
		ft_sorting_massive(a, b, 8);
}
