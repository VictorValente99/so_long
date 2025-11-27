/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:05:35 by victde-s          #+#    #+#             */
/*   Updated: 2025/08/29 01:07:36 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	convert;

	i = 0;
	convert = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == convert)
			return ((char *)&s[i]);
		i++;
	}
	if (convert == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
