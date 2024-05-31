/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:19:09 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/31 18:07:02 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ifrr(swap_list *nums, int i)
{
	i = i - nums->steps_rr;
	if (i == 0)
	{
		while (nums->n_steps - nums->steps_rr != 0)
		{
			rb(nums);
			nums->n_steps--;
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
	i = i - (nums->b_n_args - nums->steps_rrr);
	if (i == 0)
	{
		while (nums->n_steps - nums->steps_rrr != 0)
		{
			rrb(nums);
			nums->n_steps--;
		}
	}
	else
	{
		while (i != 0)
		{
			rra(nums);
			i++;
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
	if (nums->ra == 1)
	{
		while (nums->n_steps != 0)
		{
			rrb(nums);
			nums->n_steps--;
		}
	}
	else
	{
		while (nums->n_steps != 0)
		{
			rb(nums);
			nums->n_steps--;
		}
	}
}
