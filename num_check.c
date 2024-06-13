/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:25:01 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/13 13:59:54 by gmunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_chek(int argc, char **argv, int i)
{
	int	j;

	j = 0;
	while (i < argc)
	{
		j = 0;
		if (((argv[i][j] == '-') || (argv[i][j] == '+'))
			&& (ft_isdigit(argv[i][j + 1]) == 1))
			j++;
		while (argv[i][j] != '\0' || argv[i][0] == '\0')
		{
			if (ft_isdigit(argv[i][j]) == 1)
				j++;
			else if (argv[i][j] == ' ')
			{
				j++;
				if ((argv[i][j] == '-') || (argv[i][j] == '+'))
					j++;
			}
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int	arg_count(int argc, char **argv, int i)
{
	int	j;
	int	n_args;

	j = 0;
	n_args = 0;
	if (argc == 0 || arg_chek(argc, argv, i) == -1)
		return (-1);
	i = 1;
	while (i < argc)
	{
		n_args++;
		j = 0;
		while (argv[i][j++] != '\0')
		{
			if (argv[i][j] == ' ')
				n_args++;
		}
		i++;
	}
	return (n_args);
}

int	digits_in_nb(char *arg_w_spc, int i, int arg_len)
{
	int	j;

	j = 0;
	while (arg_w_spc[i] != ' ' && i < arg_len)	
	{
		i++;
		j++;
	}
	return (j);
}

int	arg_space(swap_list *nums, char *arg_w_spc, int nargs_in_lst, int i)
{
	int arg_len;
	char	*start_nb;

	arg_len = ft_strlen(arg_w_spc);
	nums->column_a[nargs_in_lst] = ft_atoi(arg_w_spc);
	
	nargs_in_lst++;
	i = i + digits_in_nb(arg_w_spc, i, arg_len);
	while (i < arg_len)
	{
		while (arg_w_spc[i - 1] != ' ' && arg_w_spc[i] != '\0')
		{
			i++;
		}
		start_nb = arg_w_spc + i;
		nums->column_a[nargs_in_lst] = ft_atoi(start_nb);
		i = i + digits_in_nb(arg_w_spc, i, arg_len);
		nargs_in_lst++;
	}
	return (nargs_in_lst);
}

void	argtoint(swap_list *nums, int argc, char **argv, int i)
{
	int	j;
	int	nargs_in_lst;
	int	has_space;

	nargs_in_lst = 0;
	while (i < argc)
	{
		j = 0;
		has_space = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
			{
				nargs_in_lst = arg_space(nums, argv[i], nargs_in_lst, 0) - 1;
				has_space = 1;
				break ;
			}
			j++;
		}
		if (has_space == 0)
			nums->column_a[nargs_in_lst] = ft_atoi(argv[i]);
		nargs_in_lst++;
		i++;
	}
}
