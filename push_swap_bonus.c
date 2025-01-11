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

static void	new_nodes_bonus(t_stack_a **stack_a, char *str)
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

static void	add_args_to_list_bonus(t_stack_a **stack_a, t_data *data)
{
	int	i;

	i = data->count - 1;
	while (i >= 0)
	{
		new_nodes_bonus(stack_a, data->args[i]);
		i--;
	}
}

void	read_lines_and_execute_utils(t_stack_a **stack_a, t_stack_b **stack_b,
		char *str)
{
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		swap_stack_a(stack_a);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		swap_stack_b(stack_b);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		ss(stack_a, stack_b, 1);
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		push_stack_a(stack_a, stack_b);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		push_stack_b(stack_b, stack_a);
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		rotate_stack_a(stack_a);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		rotate_stack_b(stack_b);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		rr(stack_a, stack_b, 1);
	else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		reverse_rotate_stack_a(stack_a);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		reverse_rotate_stack_b(stack_b);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		rrr(stack_a, stack_b, 1);
	else
		print_message("Error\n", 2);
}

void	read_lines_and_execute(t_stack_a **stack_a, t_stack_b **stack_b,
		t_data *data)
{
	data->line = get_next_line(0);
	while (data->line != NULL)
	{
		read_lines_and_execute_utils(stack_a, stack_b, data->line);
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
	if (check_stack_sort(stack_a) == 1 || check_stack_sort(stack_a) == 42)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 2);
	free_stack_all(&stack_a, &stack_b, data);
	return (0);
}
