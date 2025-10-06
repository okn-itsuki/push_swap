/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:31:21 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/02 22:01:19 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

static void	rotate(t_stack **stack_n)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack_n || !*stack_n || !(*stack_n)->next)
		return ;
	first = *stack_n;
	last = find_last(*stack_n);
	*stack_n = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(STDOUT_FILENO, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(STDOUT_FILENO, "rb\n", 3);
}
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(STDOUT_FILENO, "rr\n", 3);
}
