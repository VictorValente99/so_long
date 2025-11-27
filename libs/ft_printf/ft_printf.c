/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 13:13:42 by victde-s          #+#    #+#             */
/*   Updated: 2025/10/21 16:13:40 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_checker(char format, va_list ap)
{
	unsigned long int	ptr;

	if(!format)
		return (-1)

	if (format == '%')
		return (ft_putchar('%'));
	else if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == 'x')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (format == 'u')
		return (ft_unsigned_putnbr(va_arg(ap, unsigned int)));
	else if (format == 'p')
	{
		ptr = va_arg(ap, unsigned long int);
		if (!ptr)
			return (ft_putstr("(nil)"));
		return ((ft_putstr("0x")) + ft_putnbr_hexa(ptr, "0123456789abcdef"));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_format_checker(*format, ap);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}
