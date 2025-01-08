/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:30 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:31 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_(const char *str, t_stack_a **stack_a)
{
	int		i;
	int		s;
	long	r;

	i = 0;
	s = 1;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = (r * 10) + (str[i] - 48);
		if ((r * s > 2147483647) || (r * s < -2147483648))
		{
			free_stack_a(stack_a);
			print_message("Error\n", 2);
		}
		i++;
	}
	return (s * r);
}

static int	count_words(int ac, char **av)
{
	int	i;
	int	word;

	i = 1;
	word = 0;
	while (i < ac)
	{
		word += count_word(av[i], ' ');
		i++;
	}
	return (word);
}

void	split_argv_utils(int ac, char **av, t_data *data, char **res)
{
	int		i;
	int		j;
	int		x;
	char	**strs;

	i = 1;
	x = 0;
	while (x < data->count)
	{
		j = 0;
		if (i == ac)
			break ;
		strs = ft_split(av[i], ' ');
		data->len_args = count_word(av[i], ' ');
		while (j < data->len_args)
		{
			res[data->t] = strs[j];
			j++;
			data->t++;
		}
		free(strs);
		i++;
		x++;
	}
}

void	split_argv(int ac, char **av, t_data *data)
{
	char	**res;

	data->count = count_words(ac, av);
	res = malloc(sizeof(char *) * (data->count + 1));
	if (!res)
		return ;
	split_argv_utils(ac, av, data, res);
	res[data->count] = NULL;
	data->args = res;
}

int	ft_isnotdigit(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (1);
	if ((str[i] == '-' || str[i] == '+') && (!str[i + 1] || !(str[i + 1] >= '0'
				&& str[i + 1] <= '9')))
		return (1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}
