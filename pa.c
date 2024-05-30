/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:49:56 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/22 14:46:58 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(swap_list *nums)
{
	int	i;

	nums->n_args = nums->n_args + 1;
	nums->b_n_args = nums->b_n_args - 1;
	i = nums->n_args - 1;
	while (i != 0)
	{
		nums->column_a[i] = nums->column_a[i - 1];
		i--;
	}
	nums->column_a[0] = nums->column_b[0];
	while (i < nums->b_n_args)
	{
		nums->column_b[i] = nums->column_b[i + 1];
		i++;
	}
	write (1, "pa\n", 3);
	nums->n_steps++;
}
