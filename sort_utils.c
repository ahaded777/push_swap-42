/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:39 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:40 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(int a, int b)
{
	return (a < b);
}

int	sizelist_stack_a(t_stack_a **stack_a)
{
	int			i;
	t_stack_a	*lst;

	i = 0;
	lst = *stack_a;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	sizelist_stack_b(t_stack_b **stack_b)
{
	int			i;
	t_stack_b	*lst;

	i = 0;
	lst = *stack_b;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	is_max_nbr(t_stack_b **stack_b, t_data data)
{
	int			max_value;
	t_stack_b	*tmp;

	(void)data;
	if (!stack_b || !*stack_b)
		return (0);
	tmp = *stack_b;
	max_value = tmp->data;
	while (tmp)
	{
		if (tmp->data > max_value)
			max_value = tmp->data;
		tmp = tmp->next;
	}
	return (max_value);
}

int	find_index(t_stack_b **stack_b, int max)
{
	int			i;
	t_stack_b	*tmp;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->data == max)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}
