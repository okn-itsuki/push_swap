/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:08:12 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/03 21:40:34 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		dprintf(1, "index %d : content %d\n", stack->index, stack->content);
		stack = stack->next;
	}
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	// printf("--befor---------------------------\n");
	// print_stack(*stack_a);
	if (size == 2)
		case_two(stack_a);
	else if (size == 3)
		case_three(stack_a);
	else if (size == 4)
		case_four(stack_a, stack_b);
	else if (size == 5)
		case_five(stack_a, stack_b);
	else
		general_sort(stack_a, stack_b);
	// printf("--after---------------------------\n");
	// print_stack(*stack_a);
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
