/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:24:30 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/13 18:52:52 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_swap_list *nums)
{
	int	i;
	int	temp;

	i = 0;
	temp = nums->column_a[0];
	while (i < nums->n_args - 1)
	{
		nums->column_a[i] = nums->column_a[i + 1];
		i++;
	}
	nums->column_a[i] = temp;
	if (nums->rr == 0)
		write (1, "ra\n", 3);
	nums->n_steps++;
}

void	rb(t_swap_list *nums)
{
	int	i;
	int	temp;

	i = 0;
	temp = nums->column_b[0];
	while (i < nums->b_n_args - 1)
	{
		nums->column_b[i] = nums->column_b[i + 1];
		i++;
	}
	nums->column_b[i] = temp;
	if (nums->rr == 0)
		write (1, "rb\n", 3);
	nums->rr = 0;
	nums->n_steps++;
}

void	rr(t_swap_list *nums)
{
	nums->rr = 1;
	write (1, "rr\n", 3);
	ra(nums);
	rb(nums);
	nums->n_steps--;
}
