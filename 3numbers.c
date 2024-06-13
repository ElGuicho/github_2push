/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3numbers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:12:51 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/13 18:47:28 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move3(t_swap_list *nums, int *n)
{
	if (n[0] < n[1] && n[1] < n[2])
		return ;
	if (nums->n_args == 2 && n[0] > n[1])
		sa(nums);
	else if (n[0] > n[1] && n[0] < n[2])
		sa(nums);
	else if (n[0] > n[1] && n[1] < n[2])
		ra(nums);
	else if (n[0] > n[1])
	{
		ra(nums);
		sa(nums);
	}
	else if (n[0] > n[2])
		rra(nums);
	else if (n[0] < n[2])
	{
		sa(nums);
		ra(nums);
	}
}
