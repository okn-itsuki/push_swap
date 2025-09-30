/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:47:09 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/29 21:55:03 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static int	get_pos(t_stack *stack, int target_idx)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == target_idx)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

static void	move_to_top(t_stack **stack_a, int target_idx)
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

void	case_five(t_stack **stack_a, t_stack **stack_b)
{
	move_to_top(stack_a, 0);
	pb(stack_a, stack_b);
	move_to_top(stack_a, 1);
	pb(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		case_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
