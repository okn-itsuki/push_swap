/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:31:20 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/02 21:55:46 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static int	get_pos(t_stack *stack, int target_idx)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == target_idx)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

void	move_to_top(t_stack **stack_a, int target_idx)
{
	int		pos;
	size_t	size;

	size = stack_size(*stack_a);
	pos = get_pos(*stack_a, target_idx);
	if (pos <= (int)size / 2)
	{
		while (pos-- > 0)
			ra(stack_a);
	}
	else
	{
		while (pos++ < (int)size)
			rra(stack_a);
	}
}
