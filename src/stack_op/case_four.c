/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:13:18 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/01 14:38:47 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	case_four(t_stack **stack_a, t_stack **stack_b)
{
	move_to_top(stack_a, 0);
	pb(stack_a, stack_b);
	move_to_top(stack_a, 1);
	pb(stack_a, stack_b);
	if (!is_sorted(*stack_a))
		case_two(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
