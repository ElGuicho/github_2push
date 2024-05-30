/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:11 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/30 19:29:00 by gmunoz           ###   ########.fr       */
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

void	push_to_b(swap_list *nums, char *n, int i, int j, int k)
{
	int n_steps;
	
	n_steps = 0;
	nums->pb_steps = 0;
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
		//i need to identify the highest number in stack b count the steps to the top lol
	}
}

void	move100(swap_list *nums, int i)
{
	int	j;
	int	k;
	int	sort20;
	int	a_args;
	
	a_args = nums->n_args;
	sort_nums(nums, nums->column_a);
	num_position(nums);
	pb(nums);
	pb(nums);
	while (nums->n_args > 3)
	{
		while (i < nums->n_args)
		{
			push_to_b(nums, nums->column_a, i, 0, 1);
			i++;
		}
	}
	move3(nums, nums->column_a);
	while (nums->b_n_args > 0)
	{
		
	}
}
