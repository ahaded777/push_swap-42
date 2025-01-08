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

void	fill_array_from_stack(t_stack_a **stack_a, t_data *data)
{
	int			i;
	t_stack_a	*tmp;

	data->sorted_array = malloc(sizeof(int) * data->count);
	if (!data->sorted_array)
		return ;
	i = 0;
	tmp = *stack_a;
	while (i < data->count)
	{
		data->sorted_array[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
}

void	bubble_sort_array(int *array, int count)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < count - 1)
	{
		if (array[i] > array[i + 1])
		{
			tmp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

void	sort_and_push_to_array(t_stack_a **stack_a, t_data *data)
{
	fill_array_from_stack(stack_a, data);
	if (!data->sorted_array)
		return ;
	bubble_sort_array(data->sorted_array, data->count);
}

void	sort_few_elements(t_stack_a **stack_a, t_stack_b **stack_b, t_data data)
{
	sort_element(stack_a, stack_b, data);
	sort_and_push_to_array(stack_a, &data);
	if (data.count >= 6)
	{
		if (data.count >= 100)
			data.end = data.count / 16;
		else
			data.end = data.count / 6;
		push_to_b(stack_a, stack_b, &data);
		if (sizelist_stack_b(stack_b) == data.count)
			push_to_a(stack_a, stack_b, data);
	}
	free(data.sorted_array);
}
