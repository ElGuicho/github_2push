/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:25:01 by gmunoz            #+#    #+#             */
/*   Updated: 2024/06/18 18:29:10 by gmunoz           ###   ########.fr       */
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

int	arg_count(int argc, char **argv, int i, int j)
{
	int	n_args;

	n_args = 0;
	if (argc == 0 || arg_chek(argc, argv, i) == -1)
		return (-1);
	i = 1;
	while (i < argc)
	{
		n_args++;
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		while (argv[i][j++] != '\0')
		{
			if (argv[i][j] == ' ')
			{
				while (argv[i][j] == ' ')
					j++;
				if (argv[i][j] != '\0')
					n_args++;
			}
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

int	arg_space(t_swap_list *nums, char *arg_w_spc, int nargs_in_lst, int i)
{
	char	**nb;

	nb = ft_split(arg_w_spc, ' ');
	if (nb == NULL)
		nums->limit_error = -1;
	if (nums->limit_error == -1)
		return (nargs_in_lst);
	while (nb[i] != NULL)
	{
		if (ft_atol(nb[i]) < INT_MIN || ft_atol(nb[i]) > INT_MAX)
		{
			nums->limit_error = -1;
			return (nargs_in_lst);
		}
		nums->column_a[nargs_in_lst++] = ft_atoi(nb[i]);
		i++;
	}
	nums->has_space = 1;
	free(nb);
	return (nargs_in_lst);
}

void	argtoint(t_swap_list *nums, int argc, char **argv, int i)
{
	int	j;
	int	nargs_in_lst;

	nargs_in_lst = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] == ' ')
			{
				nargs_in_lst = arg_space(nums, argv[i], nargs_in_lst, 0) - 1;
				break ;
			}
			j++;
		}
		if (nums->has_space == 0)
		{
			if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
				nums->limit_error = -1;
			nums->column_a[nargs_in_lst] = ft_atoi(argv[i]);
		}
		nargs_in_lst++;
		i++;
	}
}
