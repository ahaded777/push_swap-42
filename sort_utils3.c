/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:46 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:48 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_element(t_stack_a **stack_a, t_stack_b **stack_b, t_data data)
{
	if (data.count == 2 && !cmp((*stack_a)->data, (*stack_a)->next->data))
		sa(stack_a);
	if (data.count == 3)
		sort_three_elements(stack_a);
	if (data.count == 4)
		sort_four_elements(stack_a, stack_b);
	if (data.count == 5)
		sort_five_elements(stack_a, stack_b);
	return (0);
}

void	sort_three_elements(t_stack_a **stack_a)
{
	int (e1), (e2), (e3);
	e1 = (*stack_a)->data;
	e2 = (*stack_a)->next->data;
	e3 = (*stack_a)->next->next->data;
	if (cmp(e1, e2) == 0 && cmp(e2, e3) == 1 && cmp(e1, e3) == 1)
		sa(stack_a);
	else if (cmp(e1, e2) == 0 && cmp(e2, e3) == 0)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (cmp(e1, e2) == 0 && cmp(e2, e3) == 1 && cmp(e1, e3) == 0)
		ra(stack_a);
	else if (cmp(e1, e2) == 1 && cmp(e2, e3) == 0 && cmp(e1, e3) == 1)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (cmp(e1, e2) == 1 && cmp(e2, e3) == 0 && cmp(e1, e3) == 0)
		rra(stack_a);
}

void	sort_four_elements_utils(t_stack_a **stack_a, t_stack_b **stack_b)
{
	sort_three_elements(stack_a);
	pa(stack_a, stack_b);
}

void	sort_four_elements(t_stack_a **stack_a, t_stack_b **stack_b)
{
	int (e1), (e2), (e3), (e4);
	e1 = (*stack_a)->data;
	e2 = (*stack_a)->next->data;
	e3 = (*stack_a)->next->next->data;
	e4 = (*stack_a)->next->next->next->data;
	if (cmp(e1, e2) == 1 && cmp(e1, e3) == 1 && cmp(e1, e4) == 1)
		pb(stack_a, stack_b);
	else if (cmp(e2, e1) == 1 && cmp(e2, e3) == 1 && cmp(e2, e4) == 1)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (cmp(e3, e1) == 1 && cmp(e3, e2) == 1 && cmp(e3, e4) == 1)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if (cmp(e4, e1) == 1 && cmp(e4, e2) == 1 && cmp(e4, e3) == 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_four_elements_utils(stack_a, stack_b);
}
