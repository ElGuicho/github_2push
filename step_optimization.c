/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:42:36 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/31 16:54:14 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrarb_steps(swap_list *nums, int i)
{
	int steps_rr;
	int steps_rrr;
	int n_steps;
	
	n_steps = nums->steps_rra + nums->steps_rb;
	if (n_steps < nums->n_steps)
	{
		nums->n_steps = n_steps;
		nums->num_to_move = i;
		nums->steps_rr = 0;
		nums->steps_rrr = 0;
	}
}

void rarrb_steps(swap_list *nums, int i)
{
	int steps_rr;
	int steps_rrr;
	int n_steps;
	
	n_steps = nums->steps_ra + nums->steps_rrb;
	if (n_steps < nums->n_steps)
	{
		nums->n_steps = n_steps;
		nums->num_to_move = i;
		nums->steps_rr = 0;
		nums->steps_rrr = 0;
	}
}

void rrarrb_steps(swap_list *nums, int i)
{
	int steps_rr;
	int steps_rrr;
	int n_steps;
	
	if (nums->steps_rra < nums->steps_rrb)
	{
		steps_rrr = nums->steps_rra;
		n_steps = nums->steps_rrb;
	}
	else
	{
		steps_rrr = nums->steps_rrb;
		n_steps = nums->steps_rra;
	}
	if (n_steps < nums->n_steps)
	{
		nums->n_steps = n_steps;
		nums->num_to_move = i;
		nums->steps_rrr = steps_rrr;
		nums->steps_rr = 0;
	}
}

void rarb_steps(swap_list *nums, int i)
{
	int steps_rr;
	int steps_rrr;
	int n_steps;
	
	if (nums->steps_ra < nums->steps_rb)
	{
		steps_rr = nums->steps_ra;
		n_steps = nums->steps_rb;
	}
	else
	{
		steps_rr = nums->steps_rb;
		n_steps = nums->steps_ra;
	}
	if (n_steps < nums->n_steps)
	{
		nums->n_steps = n_steps;
		nums->num_to_move = i;
		nums->steps_rr = steps_rr;
		nums->steps_rrr = 0;
	}
}
