/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:37:03 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/29 21:24:27 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static void	rev_rotate(t_stack **stack_n)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!stack_n || !*stack_n || (*stack_n)->next)
		return ;
	last = *stack_n;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack_n;
	*stack_n = last;
}

void	rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(STDOUT_FILENO, "rra\n", 3);
}

void	rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(STDOUT_FILENO, "rrb\n", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(STDOUT_FILENO, "rrr\n", 3);
}
