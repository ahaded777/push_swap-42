/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:30 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:31 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args_utils2(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->args[i])
	{
		j = 0;
		while (data->args[j])
		{
			if (!data->args[j + i + 1])
				break ;
			if ((ft_atoi(data->args[i]) == ft_atoi(data->args[j + i + 1])))
			{
				free_all(data->args);
				print_message("Error\n", 2);
			}
			j++;
		}
		i++;
	}
}

void	check_args_utils(char **av, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ')
				break ;
			j++;
		}
		if (ft_strlen(av[i]) == (size_t)j)
		{
			free_all(data->args);
			print_message("Error\n", 2);
		}
		i++;
	}
	check_args_utils2(data);
}

void	check_args(char **av, t_data *data)
{
	int	i;

	i = 0;
	while (data->args[i])
	{
		if (ft_isnotdigit(data->args[i]) == 1)
		{
			free_all(data->args);
			print_message("Error\n", 2);
		}
		i++;
	}
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
		{
			free_all(data->args);
			print_message("Error\n", 2);
		}
		i++;
	}
	check_args_utils(av, data);
}
