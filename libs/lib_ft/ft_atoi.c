/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:24:19 by victde-s          #+#    #+#             */
/*   Updated: 2025/08/29 13:58:12 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	no_spaces(const char **nptr)
{
	while ((**nptr >= 9 && **nptr <= 13) || **nptr == 32)
		(*nptr)++;
}

int	sign_checkage(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '+' || **nptr == '-')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
		if (**nptr == '+' || **nptr == '-')
			return (0);
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	n;
	int				sign;

	n = 0;
	no_spaces(&nptr);
	sign = sign_checkage(&nptr);
	if (sign == 0)
		return (0);
	while (ft_isdigit(*nptr))
	{
		n = n * 10 + (*nptr - 48);
		nptr++;
	}
	return (sign * (int)n);
}
