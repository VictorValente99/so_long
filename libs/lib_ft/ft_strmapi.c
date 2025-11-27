/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:13:15 by victde-s          #+#    #+#             */
/*   Updated: 2025/09/03 17:47:02 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	str = (char *)ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
