/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:46:57 by gmunoz            #+#    #+#             */
/*   Updated: 2024/07/23 15:35:34 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include "Libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

typedef struct push_list
{
	int	*column_a;
	int	*column_b;
	int	*ordered_column;
	int	n_args;
	int	b_n_args;
	int	ss;
	int	rr;
	int	rrr;
	int	r_steps;
	int	n_steps;
	int	num_to_move;
	int	possible_b;
	int	b_to_move;
	int	steps_ra;
	int	steps_rb;
	int	steps_rr;
	int	steps_rra;
	int	steps_rrb;
	int	steps_rrr;
	int	limit_error;
	int	has_space;
}	t_swap_list;

int			push_swap(int argc, char **argv);

// steps
void		sa(t_swap_list *nums);
void		sb(t_swap_list *nums);
void		ss(t_swap_list *nums);
void		ra(t_swap_list *nums);
void		rb(t_swap_list *nums);
void		rr(t_swap_list *nums);
void		rra(t_swap_list *nums);
void		rrb(t_swap_list *nums);
void		rrr(t_swap_list *nums);
void		pa(t_swap_list *nums);
void		pb(t_swap_list *nums);

//num_check
int			arg_count(int argc, char **argv, int i, int j);
void		argtoint(t_swap_list *nums, int argc, char **argv, int i);
int			in_order(t_swap_list *nums, int *n);
long int	ft_atol(const char *str);
void		split_free(char **str);

// arranging numbers
void		move3(t_swap_list *nums, int *n);
void		move5(t_swap_list *nums, int *n);
void		move100(t_swap_list *nums, int i);
void		move500(t_swap_list *nums, int i);

// 100+_num_functions
void		sort_nums(t_swap_list *nums, int *column_b);
void		num_position(t_swap_list *nums);
void		move_pa(t_swap_list *nums, int max_args);
void		move_pb(t_swap_list *nums, int i);

// steps_optimization
void		rarb_steps(t_swap_list *nums, int i);
void		rarrb_steps(t_swap_list *nums, int i);
void		rrarrb_steps(t_swap_list *nums, int i);
void		rrarb_steps(t_swap_list *nums, int i);

// step_initialization
void		ifrr(t_swap_list *nums, int i);
void		ifrrr(t_swap_list *nums, int i);
void		mixed_rs(t_swap_list *nums, int i);

#endif