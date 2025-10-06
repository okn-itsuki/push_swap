/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:58:03 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/03 21:36:17 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

void	assign_index(t_stack **stack)
{
	t_stack	*current;
	t_stack	*scanner;
	int		rank;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		rank = 0;
		scanner = *stack;
		while (scanner)
		{
			if (current->content > scanner->content)
				rank++;
			scanner = scanner->next;
		}
		current->index = rank;
		current = current->next;
	}
}
