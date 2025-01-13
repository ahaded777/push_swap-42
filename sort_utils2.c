/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:43 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:44 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_sort(t_stack_a *stack_a)
{
	t_stack_a	*tmp;

	tmp = stack_a;
	if (!stack_a)
		return (42);
	while (tmp->next)
	{
		if (!cmp(tmp->data, tmp->next->data))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_smallest_element_index(t_stack_a **stack_a)
{
	int (e1), (e2), (e3), (e4), (e5);
	e1 = (*stack_a)->data;
	e2 = (*stack_a)->next->data;
	e3 = (*stack_a)->next->next->data;
	e4 = (*stack_a)->next->next->next->data;
	e5 = (*stack_a)->next->next->next->next->data;
	if (cmp(e1, e2) == 1 && cmp(e1, e3) == 1 && cmp(e1, e4) == 1 && cmp(e1,
			e5) == 1)
		return (0);
	if (cmp(e2, e1) == 1 && cmp(e2, e3) == 1 && cmp(e2, e4) == 1 && cmp(e2,
			e5) == 1)
		return (1);
	if (cmp(e3, e1) == 1 && cmp(e3, e2) == 1 && cmp(e3, e4) == 1 && cmp(e3,
			e5) == 1)
		return (2);
	if (cmp(e4, e1) == 1 && cmp(e4, e2) == 1 && cmp(e4, e3) == 1 && cmp(e4,
			e5) == 1)
		return (3);
	if (cmp(e5, e1) == 1 && cmp(e5, e2) == 1 && cmp(e5, e3) == 1 && cmp(e5,
			e4) == 1)
		return (4);
	return (-1);
}

void	move_smallest_to_b(t_stack_a **stack_a, t_stack_b **stack_b, int index)
{
	if (index == 0)
		pb(stack_a, stack_b);
	else if (index == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 2)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 4)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	push_smallest_to_b(t_stack_a **stack_a, t_stack_b **stack_b)
{
	int	smallest_index;

	smallest_index = find_smallest_element_index(stack_a);
	move_smallest_to_b(stack_a, stack_b, smallest_index);
}

void	sort_five_elements(t_stack_a **stack_a, t_stack_b **stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	sort_four_elements(stack_a, stack_b);
	pa(stack_a, stack_b);
}
