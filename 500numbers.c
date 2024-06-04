/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   500numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:23 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/04 14:26:20 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(swap_list *nums, int *n, int i, int j, int k)
{
	nums->r_steps = 500;
	nums->steps_ra = i;
	nums->steps_rra = nums->n_args - i;
	while (nums->column_b[j] != n[i] - k && n[i] - k != -1)
	{
		j++;
		if (j == nums->b_n_args)
		{
			k++;
			j = 0;
		}
	}
	if (n[i] - k == -1)
	{
		k = 0;
		if (nums->column_b[nums->b_n_args - 1] < nums->column_b[0])
		{
			nums->steps_rb = 0;
			nums->steps_rrb = nums->b_n_args;
		}
		else while (nums->column_b[k] > nums->column_b[k + 1] && k < nums->b_n_args - 1)
			k++;
		nums->steps_rb = k + 1;
		nums->steps_rrb = nums->b_n_args - k + 1;
	}
	else
	{
		nums->steps_rb = j + 1;
		nums->steps_rrb = nums->b_n_args - j + 1;
	}
	rarb_steps(nums, i);
	rrarrb_steps(nums, i);
	rarrb_steps(nums, i);
	rrarb_steps(nums, i);
}

void	move500(swap_list *nums, int i)
{
	int	j;
	int	k;
	
	nums->ra = 0;
	nums->steps_rr = 0;
	nums->steps_rrr = 0;
	sort_nums(nums, nums->column_a);
	num_position(nums);
	pb(nums);
	pb(nums);
	while (nums->n_args > 3)
	{
		while (i < nums->n_args)
		{
			push_to_a(nums, nums->column_a, i, 0, 1);
			i++;
		}
		if (nums->steps_rr != 0)
			ifrr(nums, nums->num_to_move);
		else if (nums->steps_rrr != 0)
			ifrrr(nums, nums->num_to_move);
		else
			mixed_rs(nums, nums->num_to_move);
		pb(nums);
	}
	move3(nums, nums->column_a);
	while (nums->b_n_args > 0)
	{
		j = 0;
		k = 1;
		while (nums->column_a[j] != nums->column_b[0] + k && nums->column_b[0] + k != nums->n_args)
		{
			j++;
			if (j == nums->n_args)
			{
				k++;
				j = 0;
			}
		}
		if (nums->column_b[0] + k == nums->n_args)
		{
			k = 0;
			if (nums->column_b[nums->n_args - 1] > nums->column_a[0])
			{
				nums->steps_rb = 0;
				nums->steps_rrb = nums->b_n_args;
			}
			else while (nums->column_b[k] < nums->column_b[k + 1] && k < nums->n_args - 1)
				k++;
			nums->steps_rb = k + 1;
			nums->steps_rrb = nums->b_n_args - k + 1;
		}
		else
		{
			nums->steps_rb = j + 1;
			nums->steps_rrb = nums->b_n_args - j + 1;
		}
		if (nums->steps_rb <= nums->steps_rrb)
		{
			while (nums->steps_rb > 0)
			{
				ra(nums);
				nums->steps_rb--;
			}
		}
		else
		{
			while (nums->steps_rrb > 0)
			{
				rra(nums);
				nums->steps_rrb--;
			}
		}
		pa(nums);
			//push all numbers to stack a
	}
	while (nums->column_a[0] != 0)
		rra(nums);
}

/* en vez de ordenar los numeros en b y luego pasarlos a a, irlos ordenando mientras
los paso a a. */