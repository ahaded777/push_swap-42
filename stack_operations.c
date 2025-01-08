/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:55:03 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:55:04 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_stack_a(t_stack_a **stack_a)
{
	t_stack_a	*tmp;
	t_stack_a	*current;

	if (!stack_a || !(*stack_a) || !((*stack_a)->next))
		return (0);
	current = *stack_a;
	while (current && current->next)
	{
		tmp = current->next;
		current->next = tmp->next;
		tmp->next = current;
		*stack_a = tmp;
		break ;
	}
	return (1);
}

int	swap_stack_b(t_stack_b **stack_b)
{
	t_stack_b	*tmp;
	t_stack_b	*current;

	if (!stack_b || !(*stack_b) || !((*stack_b)->next))
		return (0);
	current = *stack_b;
	while (current && current->next)
	{
		tmp = current->next;
		current->next = tmp->next;
		tmp->next = current;
		*stack_b = tmp;
		break ;
	}
	return (1);
}

int	sa(t_stack_a **stack_a)
{
	if (!swap_stack_a(stack_a))
		return (-1);
	ft_putstr_fd("sa\n", 1);
	return (0);
}

int	sb(t_stack_b **stack_b)
{
	if (!swap_stack_b(stack_b))
		return (-1);
	ft_putstr_fd("sb\n", 1);
	return (0);
}

int	ss(t_stack_a **stack_a, t_stack_b **stack_b, int index)
{
	if (!swap_stack_a(stack_a) && !swap_stack_b(stack_b))
		return (-1);
	if (index == 0)
		ft_putstr_fd("ss\n", 1);
	return (0);
}
