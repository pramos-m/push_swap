/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:36:54 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/17 18:05:38 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>
# include "../../lib/libft/libft.h"
# include "../../lib/printf/ft_printf.h"

typedef long long	t_ll;

// Error Codes
# define ERRCODE0	(int)0
# define ERRCODE1	(int)1
# define ERRCODE2	(int)2

// Error Messages
# define ERR_MSG0	(char *)"Error\n"
# define ERR_MSG1	(char *)"Error Not a valid input.\n"
# define ERR_MSG2	(char *)"Error Failed a node creation.\n"

// Directions for stack
# define ROT		(int)1
# define RROT		(int)2
# define ONTOP		(int)3
# define ERR_NUM	(int)0

typedef struct s_elems
{
	int				val;
	int				idx;
	struct s_elems	*next;
}					t_elems;

typedef struct s_stack
{
	int		len;
	t_elems	*first;
	t_elems	*last;
}			t_stack;

// Check Params
void	ft_execute_move(char *move, t_stack *a, t_stack *b);
void	ft_check_valid_params(int params, char **str);
int		ft_check_isdigit(int params, char **str);
int		ft_check_dups(int nbr, char **str);
int		ft_check_move(char *str, t_stack *a, t_stack *b);
void	ft_checking(t_stack *a, t_stack *b);
int		ft_while_is_digit(char *num);
int		ft_check_maxint(t_ll nbr);
int		ft_check_order(int nbr, char **str);
int		ft_number_moves(t_stack *a, int c_moves);
int		ft_is_int(char *num);

// Stack initiation
void	ft_init_stack_a(t_stack *a, int params, char **str);
void	ft_init_stack_b(t_stack *b);
void	ft_indexer(t_stack *stack);

// Stack movements sorting
void	ft_sab(t_stack *stack);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_pab(t_stack *stack_dest, t_stack *stack_origin);
void	ft_rab(t_stack *stack);
void	ft_rrab(t_stack *stack);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

// Sort utils
int		ft_issorted(t_stack *a);

// Error Functions
void	ft_error(int num);
void	ft_stack_clear(t_stack *s);
void	ft_clean(t_stack *s);
void	ft_exit(int num, t_stack *a, t_stack *b);
void	*ft_free(char **str, int option);

//void	ft_check_sort(t_stack *a, t_stack *b);
#endif
