/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:43:41 by victde-s          #+#    #+#             */
/*   Updated: 2025/08/29 00:49:51 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	original_dst;
	size_t	space;

	original_dst = ft_strlen(dst);
	dst_len = ft_strlen(dst);
	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	if (dst_len >= dstsize)
		return (dstsize + ft_strlen(src));
	space = (dstsize - dst_len) - 1;
	while (src[i] && i < space)
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (original_dst + ft_strlen(src));
}
