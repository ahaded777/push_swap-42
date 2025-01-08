/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:54 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:56:53 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_stack_a(t_stack_a **stack_a)
{
	t_stack_a	*tmp;
	t_stack_a	*last;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	tmp = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	return (1);
}

int	rotate_stack_b(t_stack_b **stack_b)
{
	t_stack_b	*tmp;
	t_stack_b	*last;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return (0);
	tmp = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	return (1);
}

int	ra(t_stack_a **stack_a)
{
	if (!rotate_stack_a(stack_a))
		return (-1);
	ft_putstr_fd("ra\n", 1);
	return (0);
}

int	rb(t_stack_b **stack_b)
{
	if (!rotate_stack_b(stack_b))
		return (-1);
	ft_putstr_fd("rb\n", 1);
	return (0);
}

int	rr(t_stack_a **stack_a, t_stack_b **stack_b, int index)
{
	if (!rotate_stack_a(stack_a) && !rotate_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr_fd("rr\n", 1);
	return (0);
}
