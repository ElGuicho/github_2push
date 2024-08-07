/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/13 18:47:51 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	biggest_nb(t_swap_list *nums, int j, int k, int max_args)
{
	if (nums->column_b[0] + k == max_args)
	{
		k = 0;
		if (nums->column_a[nums->n_args - 1] > nums->column_a[0])
		{
			nums->steps_rb = 0;
			nums->steps_rrb = nums->n_args;
		}
		else
		{
			while (nums->column_a[k] < nums->column_a[k + 1]
				&& k < nums->n_args - 1)
			{
				k++;
				nums->steps_rb = k + 1;
				nums->steps_rrb = nums->n_args - (k + 1);
			}
		}
	}
	else
	{
		nums->steps_rb = j;
		nums->steps_rrb = nums->n_args - j;
	}
}

void	rb_or_rrb(t_swap_list *nums)
{
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
}

void	move_pa(t_swap_list *nums, int max_args)
{
	int	j;
	int	k;

	while (nums->b_n_args > 0)
	{
		j = 0;
		k = 1;
		while (nums->column_a[j] != nums->column_b[0] + k
			&& nums->column_b[0] + k != max_args)
		{
			j++;
			if (j == nums->n_args)
			{
				k++;
				j = 0;
			}
		}
		biggest_nb(nums, j, k, max_args);
		rb_or_rrb(nums);
		pa(nums);
	}
}

void	move100(t_swap_list *nums, int i)
{
	int	max_args;

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
