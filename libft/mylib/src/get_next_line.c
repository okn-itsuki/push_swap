/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 08:07:13 by okunoitsuki       #+#    #+#             */
/*   Updated: 2025/07/29 17:09:02 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_(const char *s1, const char *s2)
{
	char	*mem;
	size_t	i;
	size_t	j;
	size_t	len_1;
	size_t	len_2;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	mem = malloc(len_1 + len_2 + 1);
	if (!mem)
		return (NULL);
	i = 0;
	while (len_1 > i)
	{
		mem[i] = s1[i];
		i++;
	}
	j = 0;
	while (len_2 > j)
	{
		mem[i + j] = s2[j];
		j++;
	}
	return (mem[i + j] = '\0', mem);
}

static char	*read_to_str(int fd, char *str)
{
	char	*buff;
	ssize_t	bytes;
	char	*tmp;

	if (!str)
		str = ft_strdup("");
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes = 1;
	while (ft_find_next_line(str) == ft_strlen(str) && bytes)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buff), free(str), NULL);
		buff[bytes] = '\0';
		tmp = str;
		str = ft_strjoin_(str, buff);
		free(tmp);
		if (!str)
			return (free(buff), NULL);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[FD_MAX];
	char		*line;
	char		*tmp;
	size_t		idx;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(str[fd]), str[fd] = NULL, NULL);
	str[fd] = read_to_str(fd, str[fd]);
	if (!str[fd])
		return (free(str[fd]), str[fd] = NULL, NULL);
	if (!*str[fd])
		return (free(str[fd]), str[fd] = NULL, NULL);
	idx = ft_find_next_line(str[fd]);
	line = ft_substr(str[fd], 0, idx + 1);
	tmp = str[fd];
	str[fd] = ft_substr(str[fd], idx + 1, ft_strlen(str[fd]) - idx);
	if (!str[fd])
	{
		free(line);
		str[fd] = NULL;
	}
	free(tmp);
	return (line);
}
