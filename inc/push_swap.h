/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos-m <pramos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:36:54 by pramos-m          #+#    #+#             */
/*   Updated: 2023/01/17 18:04:51 by pramos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<limits.h>
# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"

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

//Structures of stacks and nodes
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
void	ft_check_valid_params(int params, char **str);
int		ft_check_isdigit(int params, char **str);
int		ft_while_is_digit(char *num);
int		ft_check_maxint(t_ll nbr);
int		ft_check_dups(int nbr, char **str);
int		ft_check_order(int nbr, char **str);
int		ft_is_int(char *num);
void	ft_check_sort(t_stack *a, t_stack *b);

// Stack initiation
void	ft_init_stack_a(t_stack *a, int params, char **str);
void	ft_init_stack_b(t_stack *b);
void	ft_indexer(t_stack *stack);
t_elems	*ft_newnode(int nbr);

// Stack movements sorting
void	ft_sab(t_stack *stack, char mode);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_pab(t_stack *stack_dest, t_stack *stack_origin, char mode);
void	ft_rab(t_stack *stack, char mode);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
void	ft_rrab(t_stack *stack, char mode);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

// Short sorting
void	ft_sort_three(t_stack *a);
void	ft_sort_four(t_stack *a, t_stack *b);
void	ft_sort_five(t_stack *a, t_stack *b);
int		ft_issorted(t_stack *a);
int		ft_find_smallest(t_stack *a);

// Big sorting
void	ft_sorting_massive(t_stack *a, t_stack *b, int chunks);
void	ft_backto_a(t_stack *a, t_stack *b);
void	put_first_b(int big_idx, t_stack *a, t_stack *b);
void	ft_putfirst_b1_aux(t_stack *a, t_stack *b, int nbr, ssize_t mov);
void	ft_putfirst_b2_aux(t_stack *a, t_stack *b, int nbr, ssize_t mov);

// Sort utils
void	ft_sort_aux(t_stack *a, t_stack *b, int cut);
void	ft_sort_cut(t_stack *b, int idx, int cut);
int		ft_bigger_idx(t_stack *stack);
int		ft_where_to_move(t_stack *stack, int big_idx, ssize_t *movements);
ssize_t	ft_check_first(t_elems *first, ssize_t pos, int nbr);

// Error Functions
void	ft_error(int num);
void	ft_stack_clear(t_stack *s);
void	ft_clean(t_stack *s);

#endif
