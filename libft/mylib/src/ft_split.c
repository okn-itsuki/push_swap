/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:09:08 by oitsuki           #+#    #+#             */
/*   Updated: 2025/09/22 20:43:19 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free_all(char **split, size_t count)
{
	while (count > 0)
	{
		free(split[--count]);
	}
	free(split);
	return (NULL);
}

static char	**_ft_split(char **result, const char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	i = 0;
	end = 0;
	while (s[end])
	{
		if (s[end] != c && (end == 0 || s[end - 1] == c))
			start = end;
		if (s[end] != c && (s[end + 1] == '\0' || s[end + 1] == c))
		{
			result[i] = ft_substr(s, start, end - start + 1);
			if (!result[i])
				return (ft_free_all(result, i));
			i++;
		}
		end++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = ft_calloc(ft_wordcount(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	return (_ft_split(result, s, c));
}
