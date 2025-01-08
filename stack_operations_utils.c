/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:52 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:53 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_stack_a(t_stack_a **stack_a)
{
	t_stack_a	*tmp;
	t_stack_a	*last;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	tmp = *stack_a;
	last = *stack_a;
	while (last->next)
		last = last->next;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	return (1);
}

int	reverse_rotate_stack_b(t_stack_b **stack_b)
{
	t_stack_b	*tmp;
	t_stack_b	*last;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return (0);
	tmp = *stack_b;
	last = *stack_b;
	while (last->next)
		last = last->next;
	while (tmp->next != last)
		tmp = tmp->next;
	tmp->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	return (1);
}

int	rra(t_stack_a **stack_a)
{
	if (!reverse_rotate_stack_a(stack_a))
		return (-1);
	ft_putstr_fd("rra\n", 1);
	return (0);
}

int	rrb(t_stack_b **stack_b)
{
	if (!reverse_rotate_stack_b(stack_b))
		return (-1);
	ft_putstr_fd("rrb\n", 1);
	return (0);
}

int	rrr(t_stack_a **stack_a, t_stack_b **stack_b, int index)
{
	if (!reverse_rotate_stack_a(stack_a) && !reverse_rotate_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr_fd("rrr\n", 1);
	return (0);
}
