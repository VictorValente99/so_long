/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:00:48 by victde-s          #+#    #+#             */
/*   Updated: 2025/09/25 17:00:39 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long int	nbr;
	int			count;

	nbr = (long int)n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_putnbr_hexa(unsigned long int n, const char *base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_putnbr_hexa(n / 16, base);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	int			count;

	count = 0;
	if (n >= 10)
		count += ft_unsigned_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
