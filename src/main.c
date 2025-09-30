/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:08:12 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/30 13:07:56 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	// printf("size : %d\n", size);
	if (size == 2)
		case_two(stack_a);
	else if (size == 3)
		case_three(stack_a);
	else if (size == 5)
		case_five(stack_a, stack_b);
	else
		general_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (EXIT_FAILURE);
	init_stack(&stack_a, ac, av);
	assign_index(&stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (EXIT_SUCCESS);
	}
	sort_stack(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}
