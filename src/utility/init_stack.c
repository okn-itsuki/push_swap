/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:14:35 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/29 21:56:36 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static void	append_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		handle_error();
	new_node->content = value;
	new_node->next = NULL;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new_node;
}

void	init_stack(t_stack **stack_a, int ac, char **av)
{
	int		i;
	t_stack	*current;
	long	num;

	i = 1;
	while (i < ac)
	{
		num = ft_atoi_cheak(av[i]);
		current = *stack_a;
		while (current)
		{
			if (current->content == (int)num)
				handle_error();
			current = current->next;
		}
		append_node(stack_a, (int)num);
		i++;
	}
}
