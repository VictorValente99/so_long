/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 18:25:05 by victde-s          #+#    #+#             */
/*   Updated: 2025/08/29 01:07:48 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[len] && len < dstsize - 1)
	{
		dst[len] = src[len];
		len++;
	}
	dst[len] = '\0';
	return (ft_strlen(src));
}
