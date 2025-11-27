/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:13:00 by victde-s          #+#    #+#             */
/*   Updated: 2025/09/01 20:44:14 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	n_digits(long n)
{
	size_t		count;
	long int	temp;

	if (n == 0)
		return (1);
	count = 0;
	temp = n;
	if (temp < 0)
	{
		temp = -temp;
		count++;
	}
	while (temp > 0)
	{
		temp = temp / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nbr;
	size_t		digits;

	nbr = n;
	digits = n_digits(n);
	str = (char *)ft_calloc(digits + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = 48;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	digits -= 1;
	while (nbr > 0)
	{
		str[digits--] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (str);
}
