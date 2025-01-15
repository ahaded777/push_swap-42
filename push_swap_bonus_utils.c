/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:39:10 by aahaded           #+#    #+#             */
/*   Updated: 2025/01/13 18:39:11 by aahaded          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_nodes_bonus(t_stack_a **stack_a, char *str)
{
	t_stack_a	*new_node;

	if (!str)
		return ;
	new_node = malloc(sizeof(t_stack_a));
	if (!new_node)
		return ;
	new_node->data = ft_atoi_(str, stack_a);
	new_node->next = *stack_a;
	*stack_a = new_node;
}

void	add_args_to_list_bonus(t_stack_a **stack_a, t_data *data)
{
	int	i;

	i = data->count - 1;
	while (i >= 0)
	{
		new_nodes_bonus(stack_a, data->args[i]);
		i--;
	}
}

int	read_lines_and_execute_utils3(t_stack_a **stack_a, t_stack_b **stack_b,
		t_data *data)
{
	if (ft_strncmp(data->line, "rr\n", ft_strlen(data->line)) == 0)
	{
		rr(stack_a, stack_b, 1);
		return (0);
	}
	else if (ft_strncmp(data->line, "rra\n", ft_strlen(data->line)) == 0)
	{
		reverse_rotate_stack_a(stack_a);
		return (0);
	}
	else if (ft_strncmp(data->line, "rrb\n", ft_strlen(data->line)) == 0)
	{
		reverse_rotate_stack_b(stack_b);
		return (0);
	}
	else if (ft_strncmp(data->line, "rrr\n", ft_strlen(data->line)) == 0)
	{
		rrr(stack_a, stack_b, 1);
		return (0);
	}
	return (1);
}

int	read_lines_and_execute_utils2(t_stack_a **stack_a, t_stack_b **stack_b,
		t_data *data)
{
	if (ft_strncmp(data->line, "pb\n", ft_strlen(data->line)) == 0)
	{
		push_stack_b(stack_b, stack_a);
		return (0);
	}
	else if (ft_strncmp(data->line, "ra\n", ft_strlen(data->line)) == 0)
	{
		rotate_stack_a(stack_a);
		return (0);
	}
	else if (ft_strncmp(data->line, "rb\n", ft_strlen(data->line)) == 0)
	{
		rotate_stack_b(stack_b);
		return (0);
	}
	return (read_lines_and_execute_utils3(stack_a, stack_b, data));
}
