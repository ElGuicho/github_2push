/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:04 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/13 18:48:11 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	four_args(t_swap_list *nums, int *n)
{
	if (n[0] > n[1] && n[1] < n[2] && n[1] < n[3])
		ra(nums);
	if (n[0] > n[2] && n[1] > n[2] && n[2] < n[3])
	{
		ra(nums);
		ra(nums);
	}
	if (n[0] > n[3] && n[1] > n[3] && n[2] > n[3])
		rra(nums);
	if (in_order(nums, nums->column_a) == 1)
		return ;
	pb(nums);
	move3(nums, nums->column_a);
	pa(nums);
}

void	move5(t_swap_list *nums, int *n)
{
	if (nums->n_args == 4)
	{
		four_args(nums, n);
		return ;
	}
	if (n[1] < n[0] && n[1] < n[2] && n[1] < n[3] && n[1] < n[4])
		ra(nums);
	else if (n[2] < n[0] && n[2] < n[1] && n[2] < n[3] && n[2] < n[4])
	{
		ra(nums);
		ra(nums);
	}
	else if (n[3] < n[0] && n[3] < n[1] && n[3] < n[2] && n[3] < n[4])
	{
		rra(nums);
		rra(nums);
	}
	else if (n[4] < n[0] && n[4] < n[1] && n[4] < n[2] && n[4] < n[3])
		rra(nums);
	if (in_order(nums, nums->column_a) == 1)
		return ;
	pb(nums);
	four_args(nums, nums->column_a);
	pa(nums);
}
