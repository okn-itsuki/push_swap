/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 06:03:35 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/19 06:09:49 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strendswith - check if a string ends with a given suffix
**
** @param s:      The full string to check.
** @param suffix: The suffix to look for at the end of s.
** @return:       1 if s ends with suffix, 0 otherwise.
**
** Example:
**   ft_strendswith("file.txt", ".txt") → 1
*/

#include "libft.h"

int	ft_strendswith(const char *s, const char *suffix)
{
	size_t	s_len;
	size_t	suffix_len;

	if (!s || !suffix)
		return (0);
	s_len = ft_strlen(s);
	suffix_len = ft_strlen(suffix);
	if (suffix_len > s_len)
		return (0);
	return (ft_strncmp(s + s_len - suffix_len, suffix, suffix_len) == 0);
}
