/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:47:11 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/06 12:06:11 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	case_three(t_stack **stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	n1 = (*stack_a)->content;
	n2 = (*stack_a)->next->content;
	n3 = (*stack_a)->next->next->content;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		sa(stack_a);
	else if (n1 > n2 && n2 > n3)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (n1 > n2 && n2 < n3 && n1 > n3)
		ra(stack_a);
	else if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (n1 < n2 && n2 > n3 && n1 > n3)
		rra(stack_a);
}
