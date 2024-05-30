/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:40:32 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/22 14:46:43 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(swap_list *nums)
{
	int	i;
	int	temp;
	
	i = nums->n_args - 1;
	temp = nums->column_a[i];
	while (i != 0)
	{
		nums->column_a[i] = nums->column_a[i - 1];
		i--;
	}
	nums->column_a[i] = temp;
	if (nums->rrr == 0)
		write (1, "rra\n", 4);
	nums->n_steps++;
}

void	rrb(swap_list *nums)
{
	int	i;
	int	temp;
	
	i = nums->b_n_args - 1;
	temp = nums->column_b[i];
	while (i != 0)
	{
		nums->column_b[i] = nums->column_b[i - 1];
		i--;
	}
	nums->column_b[i] = temp;
	if (nums->rrr == 0)
		write (1, "rrb\n", 4);
	nums->rrr = 0;
	nums->n_steps++;
}

void	rrr(swap_list *nums)
{
	nums->rrr = 1;
	write (1, "rrr\n", 4);
	rra(nums);
	rrb(nums);
	nums->n_steps--;
}
