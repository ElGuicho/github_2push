/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:47:35 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/12 16:27:44 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	ifok;

	ifok = push_swap(argc, argv);
	if (ifok == 0 || ifok == -1	)
		write(2, "Error\n", 6);
	return (0);
}
