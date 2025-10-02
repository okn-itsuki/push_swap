/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:49:57 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/01 16:53:49 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSW_H
# define PUSW_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

bool				is_sorted(t_stack *stack);
void				handle_error(void);
void				free_stack(t_stack **stack);
int					ft_atoi_cheak(const char *nptr);
void				init_stack(t_stack **stack_a, int ac, char **av);
void				assign_index(t_stack **stack);
int					stack_size(t_stack *stack);
void				move_to_top(t_stack **stack_a, int target_idx);

void				case_two(t_stack **stack_a);
void				case_three(t_stack **stack_a);
void				case_four(t_stack **stack_a, t_stack **stack_b);
void				case_five(t_stack **stack_a, t_stack **stack_b);
void				general_sort(t_stack **stack_a, t_stack **stack_b);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);

void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif