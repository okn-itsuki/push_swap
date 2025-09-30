/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:20:27 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/29 21:21:57 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*node_to_move;

	if (!stack_2 || !*stack_2)
		return ;
	node_to_move = *stack_2;
	*stack_2 = (*stack_2)->next;
	node_to_move->next = *stack_1;
	*stack_1 = node_to_move;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(STDOUT_FILENO, "pa\n", 3);
}
void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(STDOUT_FILENO, "pb\n", 3);
}
