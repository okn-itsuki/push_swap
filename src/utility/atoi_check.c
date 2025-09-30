/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:48:31 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/28 20:48:14 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pusw.h"

static int	ft_isspace(const char c)
{
	return ((c >= (char)9 && c <= (char)13) || c == (char)32);
}

static int	check_int(int sign, long int nb, char next)
{
	if (sign == 1)
	{
		if ((long)INT_MAX / 10 < nb)
			return (1);
		if ((long)INT_MAX / 10 == nb && (long)INT_MAX % 10 < next - '0')
			return (1);
	}
	if (sign == -1)
	{
		if ((long)INT_MIN / -10 < nb)
			return (-1);
		if ((long)INT_MIN / -10 == nb && (long)INT_MIN % -10 * -1 < next - '0')
			return (-1);
	}
	return (0);
}

int	ft_atoi_cheak(const char *nptr)
{
	long	nb;
	int		sign;

	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nb = 0;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			handle_error();
		if (check_int(sign, nb, *nptr) == 1)
			handle_error();
		if (check_int(sign, nb, *nptr) == -1)
			handle_error();
		nb = 10 * nb + (long int)(*nptr - '0');
		nptr++;
	}
	return ((int)(nb * sign));
}
