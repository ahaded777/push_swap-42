/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:33 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:34 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_nodes(t_stack_a **stack_a, char *str)
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

void	add_args_to_list(t_stack_a **stack_a, t_data *data)
{
	int	i;

	i = data->count;
	while (i >= 0)
	{
		new_nodes(stack_a, data->args[i]);
		i--;
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
		exit(EXIT_FAILURE);
	initialize_structures(&data);
	split_argv(ac, av, &data);
	check_args(av, &data);
	add_args_to_list(&stack_a, &data);
	if (check_stack_sort(stack_a) == 1 || check_stack_sort(stack_a) == 42)
		free_stack_all(&stack_a, &stack_b, data);
	else
		sort_few_elements(&stack_a, &stack_b, data);
	free_stack_all(&stack_a, &stack_b, data);
}
