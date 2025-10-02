/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:42:00 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/02 21:43:22 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static void	swap(t_stack **stack)
{
	t_stack	*frist;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	frist = *stack;
	second = frist->next;
	frist->next = second->next;
	second->next = frist;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	write(STDOUT_FILENO, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	write(STDOUT_FILENO, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(STDOUT_FILENO, "ss\n", 3);
}
