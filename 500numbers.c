/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   500numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:13:23 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/30 17:50:54 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move500(swap_list *nums)
{
	int	i;
	int	j;
	int	sort20;
	int	a_args;

	a_args = nums->n_args;
	sort_nums(nums, nums->column_a);
	num_position(nums);
	while (nums->n_args > 3)
	{
		
	}
	move3(nums, nums->column_a);
	sort20 = 30;
	while (nums->b_n_args > 0)
	{
		
	}
}

/* en vez de ordenar los numeros en b y luego pasarlos a a, irlos ordenando mientras
los paso a a. */