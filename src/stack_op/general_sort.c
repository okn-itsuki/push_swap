/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 21:13:09 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/29 21:56:01 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	general_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	current_idx;
	int	max_bit;
	int	i;
	int	j;

	size = stack_size(*stack_a);
	max_bit = 0;
	while ((size - 1) >> max_bit != 0)
		max_bit++;
	i = 0;
	while (i < max_bit)
	{
		j = 0;
		while (j < size)
		{
			current_idx = (*stack_a)->index;
			if (((current_idx >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (stack_size(*stack_a) != 0)
			pa(stack_a, stack_a);
		i++;
	}
}
