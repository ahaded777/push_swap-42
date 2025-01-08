/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:27 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:57:16 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_message(char *message, int fd)
{
	ft_putstr_fd(message, fd);
	if (fd == 2)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
