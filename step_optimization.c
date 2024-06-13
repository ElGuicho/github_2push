/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:42:36 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/13 18:54:44 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrarb_steps(t_swap_list *nums, int i)
{
	int	r_steps;

	r_steps = nums->steps_rra + nums->steps_rb;
	if (r_steps < nums->r_steps)
	{
		nums->b_to_move = nums->possible_b;
		nums->r_steps = r_steps;
		nums->num_to_move = i;
		nums->steps_rr = 0;
		nums->steps_rrr = 0;
	}
}

void	rarrb_steps(t_swap_list *nums, int i)
{
	int	r_steps;

	r_steps = nums->steps_ra + nums->steps_rrb;
	if (r_steps < nums->r_steps)
	{
		nums->b_to_move = nums->possible_b;
		nums->r_steps = r_steps;
		nums->num_to_move = i;
		nums->steps_rr = 0;
		nums->steps_rrr = 0;
	}
}

void	rrarrb_steps(t_swap_list *nums, int i)
{
	int	steps_rrr;
	int	r_steps;

	if (nums->steps_rra < nums->steps_rrb)
	{
		steps_rrr = nums->steps_rra;
		r_steps = nums->steps_rrb;
	}
	else
	{
		steps_rrr = nums->steps_rrb;
		r_steps = nums->steps_rra;
	}
	if (r_steps < nums->r_steps)
	{
		nums->b_to_move = nums->possible_b;
		nums->r_steps = r_steps;
		nums->num_to_move = i;
		nums->steps_rrr = steps_rrr;
		nums->steps_rr = 0;
	}
}

void	rarb_steps(t_swap_list *nums, int i)
{
	int	steps_rr;
	int	r_steps;

	if (nums->steps_ra < nums->steps_rb)
	{
		steps_rr = nums->steps_ra;
		r_steps = nums->steps_rb;
	}
	else
	{
		steps_rr = nums->steps_rb;
		r_steps = nums->steps_ra;
	}
	if (r_steps < nums->r_steps)
	{
		nums->b_to_move = nums->possible_b;
		nums->r_steps = r_steps;
		nums->num_to_move = i;
		nums->steps_rr = steps_rr;
		nums->steps_rrr = 0;
	}
}
