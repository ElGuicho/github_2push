/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:19:09 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/11 15:21:29 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ifrr(swap_list *nums, int i)
{
	i = i - nums->steps_rr;
	if (i == 0)
	{
		while (nums->r_steps - nums->steps_rr != 0)
		{
			rb(nums);
			nums->r_steps--;
		}
	}
	else
	{
		while (i != 0)
		{
			ra(nums);
			i--;
		}
	}
	while (nums->steps_rr != 0)
	{
		rr(nums);
		nums->steps_rr--;
	}	
}

void	ifrrr(swap_list *nums, int i)
{
	i = i - (nums->n_args - nums->steps_rrr);
	if (i == 0)
	{
		while (nums->r_steps - nums->steps_rrr != 0)
		{
			rrb(nums);
			nums->r_steps--;
		}
	}
	else
	{
		if (i < 0)
			i = i * -1;
		while (i != 0)
		{
			rra(nums);
			i--;
		}
	}
	while (nums->steps_rrr != 0)
	{
		rrr(nums);
		nums->steps_rrr--;
	}	
}

void	mixed_rs(swap_list *nums, int i)
{
	correct_pos(nums, i);
	correct_pos_b(nums, nums->b_to_move);
}
