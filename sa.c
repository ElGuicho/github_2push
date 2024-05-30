/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:03:04 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/22 14:39:21 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(swap_list *nums)
{
	int	temp;
	
	temp = nums->column_a[0];
	nums->column_a[0] = nums->column_a[1];
	nums->column_a[1] = temp;
	if (nums->ss == 0)
		write (1, "sa\n", 3);
	nums->n_steps++;
}

void	sb(swap_list *nums)
{
	int	temp;
	
	temp = nums->column_b[0];
	nums->column_b[0] = nums->column_b[1];
	nums->column_b[1] = temp;
	if (nums->ss == 0)
		write (1, "sb\n", 3);
	nums->ss = 0;
	nums->n_steps++;
}

void	ss(swap_list *nums)
{
	nums->ss = 1;
	write (1, "ss\n", 3);
	sa(nums);
	sb(nums);
	nums->n_steps--;
}
