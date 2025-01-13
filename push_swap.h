/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahaded <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:54:37 by aahaded         #+#    #+#             */
/*   Updated: 2025/01/08 14:54:38 by aahaded        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char				**args;
	int					len_args;
	int					t;
	int					count;
	int					*sorted_array;
	int					start;
	int					end;
	char				*line;
}						t_data;

typedef struct s_stack_a
{
	int					data;
	struct s_stack_a	*next;
}						t_stack_a;

typedef struct s_stack_b
{
	int					data;
	struct s_stack_b	*next;
}						t_stack_b;

void					initialize_structures(t_data *data);
void					free_all(char **arr);
void					free_stack_a(t_stack_a **stack_a);
void					free_stack_b(t_stack_b **stack_b);
void					print_message(char *message, int fd);
void					free_stack_all(t_stack_a **stack_a, t_stack_b **stack_b,
							t_data data);
void					split_argv(int ac, char **av, t_data *data);
int						ft_isnotdigit(char *str);
int						ft_atoi_(const char *str, t_stack_a **stack_a);
int						sizelist_stack_a(t_stack_a **stack_a);
int						sizelist_stack_b(t_stack_b **stack_b);
int						is_max_nbr(t_stack_b **stack_b, t_data data);
int						find_index(t_stack_b **stack_b, int max);
int						cmp(int a, int b);
int						find_smallest_element_index(t_stack_a **stack_a);
void					move_smallest_to_b(t_stack_a **stack_a,
							t_stack_b **stack_b, int index);
void					move_smallest_to_b(t_stack_a **stack_a,
							t_stack_b **stack_b, int index);
void					push_smallest_to_b(t_stack_a **stack_a,
							t_stack_b **stack_b);
void					sort_five_elements(t_stack_a **stack_a,
							t_stack_b **stack_b);
int						check_stack_sort(t_stack_a *stack_a);
void					sort_three_elements(t_stack_a **stack_a);
void					sort_four_elements_utils(t_stack_a **stack_a,
							t_stack_b **stack_b);
void					sort_four_elements(t_stack_a **stack_a,
							t_stack_b **stack_b);
int						sort_element(t_stack_a **stack_a, t_stack_b **stack_b,
							t_data data);
void					check_args(char **av, t_data *data);
void					add_args_to_list(t_stack_a **stack_a, t_data *data);
void					print_message_and_free(char *message,
							t_stack_a **stack_a, t_stack_b **stack_b, int fd);
void					new_nodes_bonus(t_stack_a **stack_a, char *str);
void					add_args_to_list_bonus(t_stack_a **stack_a,
							t_data *data);
int						read_lines_and_execute_utils3(t_stack_a **stack_a,
							t_stack_b **stack_b, t_data *data);
int						read_lines_and_execute_utils2(t_stack_a **stack_a,
							t_stack_b **stack_b, t_data *data);

int						swap_stack_a(t_stack_a **stack_a);
int						swap_stack_b(t_stack_b **stack_b);
int						push_stack_a(t_stack_a **stack_a, t_stack_b **stack_b);
int						push_stack_b(t_stack_b **stack_b, t_stack_a **stack_a);
int						rotate_stack_a(t_stack_a **stack_a);
int						rotate_stack_b(t_stack_b **stack_b);
int						reverse_rotate_stack_a(t_stack_a **stack_a);
int						reverse_rotate_stack_b(t_stack_b **stack_b);

int						sa(t_stack_a **stack_a);
int						sb(t_stack_b **stack_b);
int						ss(t_stack_a **stack_a, t_stack_b **stack_b, int index);
int						pa(t_stack_a **stack_a, t_stack_b **stack_b);
int						pb(t_stack_a **stack_a, t_stack_b **stack_b);
int						ra(t_stack_a **stack_a);
int						rb(t_stack_b **stack_b);
int						rr(t_stack_a **stack_a, t_stack_b **stack_b, int index);
int						rra(t_stack_a **stack_a);
int						rrb(t_stack_b **stack_b);
int						rrr(t_stack_a **stack_a, t_stack_b **stack_b,
							int index);

void					sort_few_elements(t_stack_a **stack_a,
							t_stack_b **stack_b, t_data data);
int						check_stack_sort(t_stack_a *stack_a);

void					push_to_b(t_stack_a **stack_a, t_stack_b **stack_b,
							t_data *data);
void					push_to_a(t_stack_a **stack_a, t_stack_b **stack_b,
							t_data data);

#endif
