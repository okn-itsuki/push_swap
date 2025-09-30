/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 04:26:14 by iokuno            #+#    #+#             */
/*   Updated: 2025/07/19 06:51:29 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
		ft_wordcount – count the number of words in a string separated
		by a specific delimiter

SYNOPSIS
		#include "libft.h"

		size_t ft_wordcount(const char *str, char delimiter);

DESCRIPTION
		The ft_wordcount() function counts how many words are present
		in the string str,using the given delimiter character to separate words.

		A word is defined as a sequence of non-delimiter characters.
		Consecutive delimiter characters are treated as a single separator.
		The function does not allocate memory
		or modify the input string — it only returns the number of
		word segments that exist between delimiters.

		This function is particularly useful when pre-calculating
		how many elements would be created by a split operation (e.g.,
			ft_split) based on a given delimiter.

PARAMETERS
		str          The input string to scan for words.
		delimiter    The character used to separate words in the string.

RETURN VALUE
		Returns the number of words found in str, separated by the delimiter.

EXAMPLES
		ft_wordcount("I like banana monkey", ' ')     → 4
		ft_wordcount(",,42,,Tokyo,,", ',')           → 2
		ft_wordcount("   ", ' ')                     → 0
		ft_wordcount("", ' ')                        → 0
		ft_wordcount("one", ',')                     → 1

NOTES
		- Words are only counted when a transition from a delimiter to a
			non-delimiter character occurs.
		- Leading, trailing,
			or consecutive delimiters are ignored for counting purposes.

SEE ALSO
		ft_split(3), ft_strlen(3)

AUTHOR
		iokuno


*/

#include "libft.h"

static int	is_delimiter(char c, char delimiter)
{
	return (c == delimiter);
}

size_t	ft_wordcount(const char *str, char delimiter)
{
	int		in_delim;
	size_t	word_count;

	in_delim = 1;
	word_count = 0;
	while (*str)
	{
		if (in_delim && !is_delimiter(*str, delimiter))
		{
			in_delim = 0;
			word_count++;
		}
		else if (!in_delim && is_delimiter(*str, delimiter))
			in_delim = 1;
		str++;
	}
	return (word_count);
}
