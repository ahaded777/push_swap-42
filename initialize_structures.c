/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_structures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:25 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:26 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_structures(t_data *data)
{
	data->args = NULL;
	data->len_args = 0;
	data->t = 0;
	data->count = 0;
	data->start = 0;
	data->end = 0;
}
