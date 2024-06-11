/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:47:35 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/11 17:12:48 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "Libft/libft.h"

int	main(int argc, char **argv)
{
	int	ifok;

	ifok = push_swap(argc, argv);
	if (ifok == 1)
		write(1, "OK\n", 3);
	else if (ifok == 0)
		write(1, "Malloc error\n", 13);
	else
		write(1, "Argument error\n", 15);
	return (0);
}
