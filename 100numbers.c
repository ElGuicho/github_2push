/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/23 18:31:51 by gmunoz           ###   ########.fr       */
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
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(nums);
			i--;
		}
	}
}

void	placed_column_a(swap_list *nums, int n, int i, int j)
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
}

void	move100(swap_list *nums, int i)
{
	int	j;
	int	k;
	int	sort20;
	int	a_args;

	sort20 = 19;
	a_args = nums->n_args;
	sort_nums(nums, nums->column_a);
	num_position(nums);
	while (nums->n_args > 5)
	{
		i = 0;
		j = nums->n_args - 1;
		k = 0;
		while (nums->column_a[i] > sort20 || nums->column_a[i] > a_args - 6)
			i++;
		while (nums->column_a[j] > sort20 || nums->column_a[i] > a_args - 6)
			j--;
		if (i <= nums->n_args - j)
		{
			j = nums->n_args - 1;
			while ((nums->column_a[k] > sort20 + 21 && nums->column_a[k] < sort20 + 1) || nums->column_a[k] > a_args - 6)
				k++;
			while ((nums->column_a[j] > sort20 + 21 && nums->column_a[k] < sort20 + 1) || nums->column_a[j] > a_args - 6)
				j--;
			if (sort20 >= a_args - 1)
			{
				k = 99;
				j = k;
			}
			if (k <= nums->n_args - j)
			{
				if (i <= k)
				{
					while (i-- > 0)
						ra(nums);
				}
				else
				{
					while (k-- > 0)
					{
						ra(nums);
						nums->rot_b = 1;
					}
				}
			}
			else
			{
				if (i <= nums->n_args - j)
				{
					while (i-- > 0)
						ra(nums);
				}
				else
				{
					while (j++ < nums->n_args)
					{
						rra(nums);
						nums->rot_b = 1;
					}
				}
			}
		}
		else
		{
			i = nums->n_args - 1;
			while ((nums->column_a[k] > sort20 + 21 && nums->column_a[k] < sort20 + 1) || nums->column_a[k] > a_args - 6)
				k++;
			while ((nums->column_a[i] > sort20 + 21 && nums->column_a[i] < sort20 + 1) || nums->column_a[i] > a_args - 6)
				i--;
			if (sort20 >= a_args - 1)
			{
				k = 99;
				i = k;
			}
			if (k <= nums->n_args - i)
			{
				if (nums->n_args - j <= k)
				{
					while (j++ < nums->n_args)
						rra(nums);
				}
				else
				{
					while (k-- > 0)
					{
						ra(nums);
						nums->rot_b = 1;
					}
				}
			}
			else
			{
				if (nums->n_args - j <= nums->n_args - i)
				{
					while (j++ < nums->n_args)
						rra(nums);
				}
				else
				{
					while (i++ < nums->n_args)
					{
						rra(nums);
						nums->rot_b = 1;
					}
				}
			}
			
		}
		/* if (i <= nums->n_args - j + 1)
		{
			while (i-- > 0)
				ra(nums);
		}
		else
		{
			while (j++ < nums->n_args + 1)
				rra(nums); */
		//placed_column_b(nums, nums->column_a[0], 0, nums->b_n_args - 1);
		pb(nums);
		if (nums->rot_b == 1)
		{
			rb(nums);
			nums->rot_b = 0;
		}
		/* if ((nums->b_n_args <= 30 && nums->b_n_args > 1) && nums->column_b[0] < 15 && nums->column_b[1] > nums->column_b[0])
			rb(nums); */
		/* if (nums->b_n_args > 30 && (nums->column_b[0] < sort20 + 15 && nums->column_b[0] > 30))
			rb(nums); */
		/* i = 0;
		j = nums->b_n_args;
		while (j > 0)
		{
			ft_printf("column b[%d] = %d\n", i, nums->column_b[i]);
			i++;
			j--;
		} */
		if (nums->n_args == a_args - sort20 + 1)
			sort20 = sort20 + 40;
	}
	move5(nums, nums->column_a);
	//sort20 = 30;
	while (nums->b_n_args > 0)
	{
		i = 0;
		j = nums->b_n_args - 1;
		while (nums->column_b[i] < nums->b_n_args - 1)
			i++;
		while (nums->column_b[j] < nums->b_n_args - 1)
			j--;
		if (i <= nums->b_n_args - j)
		{
			while (i-- > 0)
				rb(nums);
		}
		else
		{
			while (j++ < nums->b_n_args)
				rrb(nums);
		}
		//placed_column_a(nums, nums->column_b[0], 0, nums->n_args - 1);
		pa(nums);
		/* if (sort20-- == 0)
			sort20 = 30; */
		/* i = 0;
		j = nums->n_args;
		while (j > 0)
		{
			ft_printf("column a[%d] = %d\n", i, nums->column_a[i]);
			i++;
			j--;
		} */
	}
	if (nums->column_a[0] != 0)
	{
		j = nums->n_args - 1;
		while (nums->column_a[j] != 0)
			j--;
		while (j++ < nums->n_args)
			rra(nums);	
	}
	//move5(nums, nums->column_a);
	/* i = 0;
	while (nums->column_b[i] > nums->column_b[i + 1])
		i++;
	correct_pos(nums, i + 1);
	while (nums->b_n_args > 0)
		pa(nums); */
}
