/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   100num_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:44:31 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/22 14:42:58 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	num_position(swap_list *nums)
{
	int	i;
	int	j;

	i = 0;
/* 	j = nums->n_args;
	while (j > 0)
	{
		ft_printf("column a[%d] = %d\n", i, nums->column_a[i]);
		i++;
		j--;
	} */
	j = 0;
	while (j < nums->n_args)
	{
		i = 0;
		while (nums->column_a[j] != nums->ordered_column[i])
			i++;
		nums->column_a[j] = i;
		j++;
	}
	/* i = 0;
	j = nums->n_args;
	while (j > 0)
	{
		ft_printf("column a 0 to 99[%d] = %d\n", i, nums->column_a[i]);
		i++;
		j--;
	} */
}

void	swap(swap_list *nums, int j)
{
	int	temp;
	
	temp = nums->ordered_column[j];
	nums->ordered_column[j] = nums->ordered_column[j + 1];
	nums->ordered_column[j + 1] = temp;
}

void	sort_nums(swap_list *nums, int *column_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nums->n_args)
	{
		nums->ordered_column[i] = column_a[i];
		i++;
	}
	i = 0;
	while (i < nums->n_args)
	{
		while (j < nums->n_args - 1)
		{
			if (nums->ordered_column[j] > nums->ordered_column[j + 1])
				swap(nums, j);
			j++;
		}
		j = 0;
		i++;
	}
	/* i = 0;
	j = nums->n_args;
	while (j > 0)
	{
		ft_printf("ordered colummn[%d] = %d\n", i, nums->ordered_column[i]);
		i++;
		j--;
	} */
}
