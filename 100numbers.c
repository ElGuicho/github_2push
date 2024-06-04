/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/04 18:50:39 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	correct_pos(swap_list *nums, int i)
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
			nums->ra = 1;
			nums->r_steps--;
			i--;
		}
	}
}

/* void	placed_column_a(swap_list *nums, int n, int i, int j)
{
	if (nums->n_args < 2)
		return ;
	if (nums->n_args == 2 && nums->column_a[0] > nums->column_a[1])
		ra(nums);
	while (nums->column_a[i] < n && i < nums->n_args)
		i++;
	if (i == 0 && (nums->column_a[0] < nums->column_a[j] || nums->column_a[j] < n))
	{
		//printf("n = %d\n", n);
		return ;
	}
	if (i == 0 && nums->column_a[j] > n)
	{
		while (nums->column_a[j] > n && j > 0)
			j--;
		if (j == 0)
		{
			while (nums->column_a[j] < nums->column_a[j + 1])
				j++;
		}
		correct_pos(nums, j + 1);
	}
	else if (i == nums->n_args)
	{
		i = 0;
		while (nums->column_a[i] < nums->column_a[i + 1])
			i++;
		correct_pos(nums, i + 1);
	}
	else
		correct_pos(nums, i); 
} */

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
	ft_printf("nums->column_b[%d] = %d\n", j, nums->column_b[j]);
	if (n[i] - k == -1)
	{
		k = 0;
		if (nums->column_b[nums->b_n_args - 1] < nums->column_b[0])
		{
			nums->steps_rb = 0;
			nums->steps_rrb = nums->b_n_args;
		}
		else
		{
			while (nums->column_b[k] > nums->column_b[k + 1] && k < nums->b_n_args - 1)
				k++;
			nums->steps_rb = k + 1;
			nums->steps_rrb = nums->b_n_args - k + 1;
		}
	}
	else
	{
		nums->steps_rb = j;
		nums->steps_rrb = nums->b_n_args - j;
	}
	rarb_steps(nums, i);
	rrarrb_steps(nums, i);
	rarrb_steps(nums, i);
	rrarb_steps(nums, i);
}

void	move100(swap_list *nums, int i)
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
		nums->r_steps = 500;
		i = 0;
		while (i < nums->n_args)
		{
			push_to_b(nums, nums->column_a, i, 0, 1);
			i++;
		}
		ft_printf("r_steps = %d\n", nums->r_steps);
		ft_printf("num_to_move = %d\n", nums->num_to_move);
		ft_printf("steps_rr = %d\n", nums->steps_rr);
		ft_printf("steps_rrr = %d\n", nums->steps_rrr);
		if (nums->steps_rr != 0)
			ifrr(nums, nums->num_to_move);
		else if (nums->steps_rrr != 0)
			ifrrr(nums, nums->num_to_move);
		else
			mixed_rs(nums, nums->num_to_move);
		ft_printf("b_n_args = %d\n", nums->b_n_args);
		i = 0;
		j = nums->n_args;
		while (j > 0)
		{
			ft_printf("column_a[%d] = %d\n", i, nums->column_a[i]);
			i++;
			j--;
		}
		ft_printf("--------------------\n");
		i = 0;
		j = nums->b_n_args;
		while (j > 0)
		{
			ft_printf("column_b[%d] = %d\n", i, nums->column_b[i]);
			i++;
			j--;
		}
		pb(nums);
	}
	move3(nums, nums->column_a);
	while (nums->b_n_args > 0)
	{
		j = 0;
		k = 1;
		while (nums->column_a[j] != nums->column_b[0] + k && k != nums->n_args)
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
