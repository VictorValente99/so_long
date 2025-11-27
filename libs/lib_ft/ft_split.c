/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:02:52 by victde-s          #+#    #+#             */
/*   Updated: 2025/09/04 16:53:29 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	counting_words(const char *str, char stop)
{
	int		word_counter;
	size_t	is_a_word;

	word_counter = 0;
	is_a_word = 0;
	while (*str)
	{
		if (*str != stop && !is_a_word)
		{
			is_a_word = 1;
			word_counter++;
		}
		else if (*str == stop)
			is_a_word = 0;
		str++;
	}
	return (word_counter);
}

char	**malloc_n_words(int n_words)
{
	char	**mallocked_words;

	mallocked_words = ft_calloc(n_words + 1, sizeof(char *));
	if (!mallocked_words)
		return (NULL);
	return (mallocked_words);
}

void	free_words(char **words, int filled)
{
	int	i;

	i = 0;
	while (i < filled)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

char	**put_words(char **splitted, const char *s, char c, int n_words)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (i < n_words)
	{
		while (s[j] && s[j] == c)
			j++;
		start = j;
		while (s[j] && s[j] != c)
			j++;
		splitted[i] = ft_substr(s, start, j - start);
		if (!splitted[i])
		{
			free_words(splitted, i);
			return (NULL);
		}
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	char	**words_vector;
	int		n_words;

	if (!s)
		return (NULL);
	n_words = counting_words(s, c);
	words_vector = malloc_n_words(n_words);
	if (!words_vector)
		return (NULL);
	return (put_words(words_vector, s, c, n_words));
}
