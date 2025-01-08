/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils3.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:55:00 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:55:01 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack_a(t_stack_a **stack_a, t_stack_b **stack_b)
{
	t_stack_b	*temp;

	if (!stack_b || !(*stack_b))
		return (0);
	temp = *stack_b;
	while (temp)
	{
		*stack_b = (*stack_b)->next;
		temp->next = (t_stack_b *)(*stack_a);
		*stack_a = (t_stack_a *)temp;
		break ;
	}
	return (1);
}

int	push_stack_b(t_stack_b **stack_b, t_stack_a **stack_a)
{
	t_stack_a	*temp;

	if (!stack_a || !(*stack_a))
		return (0);
	temp = *stack_a;
	while (temp)
	{
		*stack_a = (*stack_a)->next;
		temp->next = (t_stack_a *)(*stack_b);
		*stack_b = (t_stack_b *)temp;
		break ;
	}
	return (1);
}

int	pa(t_stack_a **stack_a, t_stack_b **stack_b)
{
	if (!push_stack_a(stack_a, stack_b))
		return (-1);
	ft_putstr_fd("pa\n", 1);
	return (0);
}

int	pb(t_stack_a **stack_a, t_stack_b **stack_b)
{
	if (!push_stack_b(stack_b, stack_a))
		return (-1);
	ft_putstr_fd("pb\n", 1);
	return (0);
}
