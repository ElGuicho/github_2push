/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:46:57 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/23 17:35:18 by gmunoz           ###   ########.fr       */
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
	int	rr;
	int	rrr;
	int	n_steps;
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
void	move500(swap_list *nums);
void	hundred_move3(swap_list *nums, int *n, int i);
void	hundred_move5(swap_list *nums, int *n, int i);

int in_order(swap_list *nums, int *n);

// 100num_functions
void	sort_nums(swap_list *nums, int *column_b);
void	num_position(swap_list *nums);
void	last_nbs(swap_list *nums, int less_than_5);
void	correct_pos(swap_list *nums, int i);
void	placed_column_a(swap_list *nums, int n, int i, int j);

#endif