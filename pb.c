/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:50:02 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/22 14:46:56 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(swap_list *nums)
{
	int	i;

	nums->n_args = nums->n_args - 1;
	nums->b_n_args = nums->b_n_args + 1;
	i = nums->b_n_args - 1;
	while (i != 0)
	{
		nums->column_b[i] = nums->column_b[i - 1];
		i--;
	}
	nums->column_b[0] = nums->column_a[0];
	while (i < nums->n_args)
	{
		nums->column_a[i] = nums->column_a[i + 1];
		i++;
	}
	write (1, "pb\n", 3);
	nums->n_steps++;
}
//4 8 9 6
	/* printf("nums[0] = %d\n", nums->column_a[0]);
	printf("nums[1] = %d\n", nums->column_a[1]);
	printf("nums[2] = %d\n", nums->column_a[2]);
	printf("nums[3] = %d\n", nums->column_a[3]); */