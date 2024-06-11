/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:46:57 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/11 14:24:35 by gmunoz           ###   ########.fr       */
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

typedef  struct push_list
{
	int	*column_a;
	int	*column_b;
	int	*ordered_column;
	int	n_args;
	int	b_n_args;
	int	ss;
	int	ra;
	int	rr;
	int	rrr;
	int	r_steps;
	int	n_steps;
	int	pb_steps;
	int	num_to_move;
	int	possible_b;
	int b_to_move;
	int	steps_ra;
	int	steps_rb;
	int	steps_rr;
	int	steps_rra;
	int	steps_rrb;
	int	steps_rrr;
	int	steps_after_r;
	int rot_b;
}	swap_list;

int	push_swap(int argc, char **argv);

// steps
void	sa(swap_list *nums);
void	sb(swap_list *nums);
void	ss(swap_list *nums);
void	ra(swap_list *nums);
void	rb(swap_list *nums);
void	rr(swap_list *nums);
void	rra(swap_list *nums);
void	rrb(swap_list *nums);
void	rrr(swap_list *nums);
void	pa(swap_list *nums);
void	pb(swap_list *nums);

// arranging numbers
void	move3(swap_list *nums, int *n);
void	move5(swap_list *nums, int *n);
void	move100(swap_list *nums, int i);
void	move500(swap_list *nums, int i);

int in_order(swap_list *nums, int *n);

// 100num_functions
void	sort_nums(swap_list *nums, int *column_b);
void	num_position(swap_list *nums);
void	last_nbs(swap_list *nums, int less_than_5);
void	correct_pos(swap_list *nums, int i);
void	correct_pos_b(swap_list *nums, int i);
void	placed_column_a(swap_list *nums, int n, int i, int j);
void	push_to_b(swap_list *nums, int *n, int i, int j, int k);

// steps_optimization
void	rarb_steps(swap_list *nums, int i);
void	rarrb_steps(swap_list *nums, int i);
void	rrarrb_steps(swap_list *nums, int i);
void	rrarb_steps(swap_list *nums, int i);

// step_initialization
void	ifrr(swap_list *nums, int i);
void	ifrrr(swap_list *nums, int i);
void	mixed_rs(swap_list *nums, int i);

#endif