/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:59:33 by victde-s          #+#    #+#             */
/*   Updated: 2025/11/12 15:54:26 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_len(const char *str1)
{
	size_t	i;

	if (!str1)
		return (0);
	i = 0;
	while (str1[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	if (!str1 && !str2)
		return (NULL);
	joined = malloc(ft_len(str1) + ft_len(str2) + 1);
	if (!joined)
		return (free(str1), NULL);
	while (str1 && str1[i])
	{
		joined[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
		joined[i++] = str2[j++];
	joined[i] = '\0';
	free(str1);
	return (joined);
}

char	*ft_get_line(char *stash)
{
	size_t	i;
	char	*line;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + (stash[i] == '\n') + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i++])
		return (free(stash), NULL);
	new = malloc(ft_len(stash + i) + 1);
	if (!new)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		new[j++] = stash[i++];
	new[j] = '\0';
	free(stash);
	return (new);
}
