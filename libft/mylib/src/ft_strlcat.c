/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:35:39 by oitsuki           #+#    #+#             */
/*   Updated: 2025/08/04 04:17:24 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	i = 0;
	len_dst = ft_strnlen(dst, size);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	while (src[i] && size - 1 > len_dst)
	{
		dst[i + len_dst] = src[i];
		size--;
		i++;
	}
	dst[i + len_dst] = '\0';
	return (len_dst + len_src);
}
