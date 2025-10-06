/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:48:15 by iokuno            #+#    #+#             */
/*   Updated: 2025/10/03 21:41:28 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (false);
	// printf("stackがNULL\n");
	while (stack->next)
	{
		if (stack->content > stack->next->content)
		{
			// printf("未ソート\n");
			return (false);
		}
		stack = stack->next;
	}
	// printf("ソート済み\n");
	return (true);
}
