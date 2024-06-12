/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   500numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:23 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/12 16:36:26 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_nb(swap_list *nums, int *n, int i, int j, int k)
{
	if (n[i] - k == -1)
	{
		k = 0;
		if (nums->column_b[nums->b_n_args - 1] < nums->column_b[0])
		{
			nums->steps_rb = 0;
			nums->steps_rrb = nums->b_n_args;
			nums->possible_b = k;
		}
		else
		{
			while (nums->column_b[k] > nums->column_b[k + 1] && k < nums->b_n_args - 1)
				k++;
			nums->steps_rb = k + 1;
			nums->steps_rrb = nums->b_n_args - k - 1;
			nums->possible_b = k + 1;
		}
	}
	else
	{
		nums->steps_rb = j;
		nums->steps_rrb = nums->b_n_args - j;
	}
}

void	push_to_b(swap_list *nums, int *n, int i, int j, int k)
{
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
	nums->possible_b = j;
	smallest_nb(nums, n, i, j, k);
	rarb_steps(nums, i);
	rrarrb_steps(nums, i);
	rarrb_steps(nums, i);
	rrarb_steps(nums, i);
}

void move_pb(swap_list *nums, int i)
{
	pb(nums);
	pb(nums);
	while (nums->n_args > 3)
	{
		nums->r_steps = 500;
		i = 0;
		while (i < nums->n_args)
		{
			push_to_b(nums, nums->column_a, i, 0, 1);
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
}

void	move500(swap_list *nums, int i)
{
	int max_args;

	max_args = nums->n_args;
	nums->steps_rr = 0;
	nums->steps_rrr = 0;
	sort_nums(nums, nums->column_a);
	num_position(nums);
	move_pb(nums, i);
	move3(nums, nums->column_a);
	move_pa(nums, max_args);
	while (nums->column_a[0] != 0)
		rra(nums);
}
