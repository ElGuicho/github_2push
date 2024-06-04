/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_optimization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:42:36 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/04 19:02:38 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rrarb_steps(swap_list *nums, int i)
{
	int r_steps;

	r_steps = nums->steps_rra + nums->steps_rb;
	if (r_steps < nums->r_steps)
	{
		nums->r_steps = r_steps;
		nums->num_to_move = i;
		nums->steps_rr = 0;
		nums->steps_rrr = 0;
	}
	ft_printf("rrarb_steps = %d\n", nums->r_steps);
}

void rarrb_steps(swap_list *nums, int i)
{
	int r_steps;

	r_steps = nums->steps_ra + nums->steps_rrb;
	if (r_steps < nums->r_steps)
	{
		nums->r_steps = r_steps;
		nums->num_to_move = i;
		nums->steps_rr = 0;
		nums->steps_rrr = 0;
	}
	ft_printf("rarrb_steps = %d\n", nums->r_steps);
}

void rrarrb_steps(swap_list *nums, int i)
{
	ft_printf("column_a[%d] = %d\n", i, nums->column_a[i]);
	int steps_rrr;
	int r_steps;
	
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
		nums->r_steps = r_steps;
		nums->num_to_move = i;
		nums->steps_rrr = steps_rrr;
		nums->steps_rr = 0;
	}
	ft_printf("rrarrb_steps = %d\n", nums->r_steps);
}

void rarb_steps(swap_list *nums, int i)
{
	int steps_rr;
	int r_steps;
	
/* 	printf("nums->steps_rb = %d\n", nums->steps_rb);
	printf("nums->steps_ra = %d\n", nums->steps_ra); */
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
		nums->r_steps = r_steps;
		nums->num_to_move = i;
		nums->steps_rr = steps_rr;
		nums->steps_rrr = 0;
	}
	ft_printf("rarb_steps = %d\n", nums->r_steps);
}
