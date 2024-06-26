/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:39 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/18 18:06:31 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freee(t_swap_list *nums)
{
	if (nums->column_a)
		free(nums->column_a);
	if (nums->column_b)
		free(nums->column_b);
	if (nums->ordered_column)
		free(nums->ordered_column);
	if (nums)
		free(nums);
}

int	lst_allocating(t_swap_list *nums, char **argv, int argc)
{
	int	i;
	int	n_args;

	i = 1;
	nums->n_steps = 0;
	n_args = arg_count(argc, argv, i, 0);
	if (n_args == -1)
		return (freee(nums), -1);
	nums->column_a = malloc(sizeof(int) * n_args);
	if (nums->column_a == NULL)
		return (freee(nums), -1);
	nums->column_b = malloc(sizeof(int) * n_args);
	if (nums->column_b == NULL)
		return (freee(nums), -1);
	nums->ordered_column = malloc(sizeof(int) * n_args);
	if (nums->ordered_column == NULL)
		return (freee(nums), -1);
	nums->n_args = n_args;
	nums->b_n_args = 0;
	nums->limit_error = 0;
	nums->has_space = 0;
	argtoint(nums, argc, argv, i);
	if (nums->limit_error == -1)
		return (freee(nums), -1);
	return (n_args);
}

int	same_num(t_swap_list *nums)
{
	int	i;
	int	j;

	i = 0;
	while (i < nums->n_args)
	{
		j = i + 1;
		while (j < nums->n_args)
		{
			if (nums->column_a[i] == nums->column_a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	in_order(t_swap_list *nums, int *n)
{
	int	i;

	i = 1;
	while (i < nums->n_args && n[i - 1] < n[i])
		i++;
	if (nums->n_args == i)
		return (1);
	return (0);
}

int	push_swap(int argc, char **argv)
{
	t_swap_list	*nums;
	int			n_args;

	nums = malloc(sizeof(t_swap_list));
	if (!nums)
		return (-1);
	n_args = lst_allocating(nums, argv, argc);
	if (n_args == -1 || same_num(nums) == -1)
		return (-1);
	if (in_order(nums, nums->column_a) == 1)
		return (1);
	if (n_args <= 3)
		move3(nums, nums->column_a);
	else if (n_args <= 5 && n_args > 3)
		move5(nums, nums->column_a);
	else if (n_args <= 100 && n_args > 5)
		move100(nums, 0);
	else if (n_args <= 500 && n_args > 100)
		move500(nums, 0);
	freee(nums);
	return (1);
}
