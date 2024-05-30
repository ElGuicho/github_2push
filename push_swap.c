/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmunoz <gmunoz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:59:39 by gmunoz            #+#    #+#             */
/*   Updated: 2024/05/23 18:36:12 by gmunoz           ###   ########.fr       */
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
	//printf ("total args: %d\n", n_args);
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

int in_order(swap_list *nums, int *n)
{
	int	i;

	i = 1;
	while (i < nums->n_args && n[i - 1] < n[i])
		i++;
	if (nums->n_args == i)
		return (1);
	return (0);
}

int	push_swap(int argc, char **argv)
{
	int	i;
	int n_args;
	swap_list	*nums;

	i = 1;
	nums = malloc(sizeof(swap_list));
	if (!nums)
		return (0);
	nums->n_steps = 0;
	n_args = arg_count(argc, argv, i);
	if (n_args == -1)
		return (free(nums), -1);
	nums->column_a = malloc(sizeof(int) * n_args);
	if (nums->column_a == NULL)
		return (free(nums), 0);
	nums->column_b = malloc(sizeof(int) * n_args);
	if (nums->column_b == NULL)
		return (free(nums), 0);
	nums->ordered_column = malloc(sizeof(int) * n_args);
	if (nums->ordered_column == NULL)
		return (free(nums), 0);
	nums->n_args = n_args;
	nums->b_n_args = 0;
	nums->rot_b = 0;
	argtoint(nums, argc, argv, i);
	if (in_order(nums, nums->column_a) == 1)
		return (1);
	if (n_args <= 3)
		move3(nums, nums->column_a);
	else if (n_args <= 5 && n_args > 3)
		move5(nums, nums->column_a);
	else if (n_args <= 100 && n_args > 5)
		move100(nums, 0);
	else if (n_args <= 500 && n_args > 100)
		move500(nums);
	i = 0;
	n_args = nums->n_args;
	while (n_args > 0)
	{
		ft_printf("final list[%d] = %d\n", i, nums->column_a[i]);
		i++;
		n_args--;
	}
	ft_printf("n_steps = %d\n", nums->n_steps);
	return (1);
}

//ft_split de espacios para arg_space
