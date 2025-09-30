/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:04:57 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/29 05:48:12 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*meta_malloc(size_t size)
{
	t_meta_info	*block;

	block = malloc(sizeof(t_meta_info) + size);
	block->size = size;
	return ((void *)(block + 1));
}

char	*ft_realloc(void *ptr, size_t size)
{
	void		*new_ptr;
	size_t		old_size;
	t_meta_info	*old_block;

	if (ptr == NULL)
		return (meta_malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	old_block = ((t_meta_info *)ptr) - 1;
	old_size = old_block->size;
	new_ptr = meta_malloc(size);
	if (!new_ptr)
		return (NULL);
	if (old_size < size)
		ft_memcpy(new_ptr, ptr, old_size);
	else
		ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
