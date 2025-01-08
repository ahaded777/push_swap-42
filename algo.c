/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:49 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:50 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	small_nbr(t_stack_a **stack_a, t_data *data, int index)
{
	int	i;

	i = 0;
	while (i <= index)
	{
		if ((*stack_a)->data <= data->sorted_array[i])
			return (1);
		i++;
	}
	return (0);
}

void	push_to_b(t_stack_a **stack_a, t_stack_b **stack_b, t_data *data)
{
	while (*stack_a)
	{
		if (small_nbr(stack_a, data, data->start))
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			data->start++;
			data->end++;
		}
		else if (small_nbr(stack_a, data, data->end))
		{
			pb(stack_a, stack_b);
			if ((*stack_b) && (*stack_b)->next)
			{
				if ((*stack_b)->data < (*stack_b)->next->data)
					sb(stack_b);
			}
			data->start++;
			data->end++;
		}
		else
			ra(stack_a);
	}
}

void	push_to_a(t_stack_a **stack_a, t_stack_b **stack_b, t_data data)
{
	int	max;
	int	index;
	int	size;

	while (*stack_b)
	{
		max = is_max_nbr(stack_b, data);
		index = find_index(stack_b, max);
		size = sizelist_stack_b(stack_b);
		if (index <= size / 2)
		{
			while ((*stack_b)->data != max)
				rb(stack_b);
		}
		else
		{
			while ((*stack_b)->data != max)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
	}
}
