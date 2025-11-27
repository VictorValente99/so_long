/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:33:09 by victde-s          #+#    #+#             */
/*   Updated: 2025/09/03 18:13:58 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr;
	unsigned const char	*ptr1;

	if (n == 0 || (!dest && !src))
		return (dest);
	ptr = (unsigned char *)dest;
	ptr1 = (unsigned const char *)src;
	while (n--)
		*ptr++ = *ptr1++;
	return (dest);
}
