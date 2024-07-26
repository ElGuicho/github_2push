/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:47:35 by gmunoz            #+#    #+#             */
/*   Updated: 2024/07/26 17:01:59 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	ifok;

	if (argc == 1)
		return (0);
	ifok = push_swap(argc, argv);
	if (ifok == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
