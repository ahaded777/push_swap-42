/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:08 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:09 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_stack_a(t_stack_a **stack_a)
{
	t_stack_a	*cu;
	t_stack_a	*tmp;

	cu = *stack_a;
	while (cu != NULL)
	{
		tmp = cu;
		cu = cu->next;
		free(tmp);
	}
	*stack_a = NULL;
}

void	free_stack_b(t_stack_b **stack_b)
{
	t_stack_b	*cu;
	t_stack_b	*tmp;

	cu = *stack_b;
	while (cu != NULL)
	{
		tmp = cu;
		cu = cu->next;
		free(tmp);
	}
	*stack_b = NULL;
}

void	free_stack_all(t_stack_a **stack_a, t_stack_b **stack_b, t_data data)
{
	(void)stack_b;
	free_stack_a(stack_a);
	if (stack_b)
		free_stack_b(stack_b);
	free_all(data.args);
	exit(EXIT_SUCCESS);
}
