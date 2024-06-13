/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:44:31 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/13 18:48:29 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atol(const char *str)
{
	int		i;
	long	sol;
	long	equ;

	i = 0;
	sol = 1;
	equ = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sol = -sol;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		equ = (equ * 10) + (str[i] - 48);
		i++;
	}
	sol = sol * equ;
	return (sol);
}

void	num_position(t_swap_list *nums)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < nums->n_args)
	{
		i = 0;
		while (nums->column_a[j] != nums->ordered_column[i])
			i++;
		nums->column_a[j] = i;
		j++;
	}
}

void	swap(t_swap_list *nums, int j)
{
	int	temp;

	temp = nums->ordered_column[j];
	nums->ordered_column[j] = nums->ordered_column[j + 1];
	nums->ordered_column[j + 1] = temp;
}

void	sort_nums(t_swap_list *nums, int *column_a)
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
}
