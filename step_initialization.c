/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:19:09 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/04 19:05:38 by gmunoz           ###   ########.fr       */
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
	ft_printf("i = %d\n", i);
	i = i - (nums->b_n_args - nums->steps_rrr);
	if (i == 0)
	{
		while (nums->r_steps - nums->steps_rrr != 0)
		{
			rrb(nums);
			nums->r_steps--;
		}
	}
	else										//CHECK TTHIS SHIT
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
	if (nums->ra == 1)
	{
		while (nums->r_steps != 0)
		{
			rrb(nums);
			nums->r_steps--;
			ft_printf("r_steps = %d\n", nums->r_steps);
			ft_printf("n_steps = %d\n", nums->n_steps);
		}
	}
	else
	{
		while (nums->r_steps != 0)
		{
			ft_printf("r_steps = %d\n", nums->r_steps);
			rb(nums);
			nums->r_steps--;
		}
	}
	nums->ra = 0;
}
