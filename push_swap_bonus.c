/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:54:10 by aahaded           #+#    #+#             */
/*   Updated: 2025/01/08 17:05:20 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	read_lines_and_execute_utils(t_stack_a **stack_a, t_stack_b **stack_b,
		t_data *data)
{
	if (ft_strncmp(data->line, "sa\n", ft_strlen(data->line)) == 0)
	{
		swap_stack_a(stack_a);
		return (0);
	}
	else if (ft_strncmp(data->line, "sb\n", ft_strlen(data->line)) == 0)
	{
		swap_stack_b(stack_b);
		return (0);
	}
	else if (ft_strncmp(data->line, "ss\n", ft_strlen(data->line)) == 0)
	{
		ss(stack_a, stack_b, 1);
		return (0);
	}
	else if (ft_strncmp(data->line, "pa\n", ft_strlen(data->line)) == 0)
	{
		push_stack_a(stack_a, stack_b);
		return (0);
	}
	read_lines_and_execute_utils2(stack_a, stack_b, data);
	return (1);
}

void	read_lines_and_execute(t_stack_a **stack_a, t_stack_b **stack_b,
		t_data *data)
{
	data->line = get_next_line(0);
	while (data->line != NULL)
	{
		if (read_lines_and_execute_utils(stack_a, stack_b, data) == 1)
		{
			free(data->line);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		free(data->line);
		data->line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_data		data;
	t_stack_a	*stack_a;
	t_stack_b	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(0);
	initialize_structures(&data);
	split_argv(ac, av, &data);
	check_args(av, &data);
	add_args_to_list_bonus(&stack_a, &data);
	read_lines_and_execute(&stack_a, &stack_b, &data);
	if (check_stack_sort(stack_a) == 1 && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	free_stack_all(&stack_a, &stack_b, data);
	return (0);
}
