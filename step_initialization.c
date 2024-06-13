/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:19:09 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/13 18:53:36 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ifrr(t_swap_list *nums, int i)
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

void	ifrrr(t_swap_list *nums, int i)
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

void	correct_pos_b(t_swap_list *nums, int i)
{
	if (nums->b_n_args - i < i)
	{
		while (i < nums->b_n_args)
		{
			rrb(nums);
			nums->r_steps--;
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			rb(nums);
			nums->r_steps--;
			i--;
		}
	}
}

void	correct_pos(t_swap_list *nums, int i)
{
	if (nums->n_args - i < i)
	{
		while (i < nums->n_args)
		{
			rra(nums);
			nums->r_steps--;
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(nums);
			nums->r_steps--;
			i--;
		}
	}
}

void	mixed_rs(t_swap_list *nums, int i)
{
	correct_pos(nums, i);
	correct_pos_b(nums, nums->b_to_move);
}
