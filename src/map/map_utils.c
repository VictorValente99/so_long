/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:51:11 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/03 20:24:10 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	map_check_extension(const char *filename, const char *extension)
{
	int	len_filename;
	int	len_extension;

	if (!filename || !extension)
		return (0);
	len_filename = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	if (len_filename < len_extension)
		return (0);
	if (ft_strncmp(filename + (len_filename - len_extension),
			extension, len_extension) == 0)
		return (1);
	return (0);
}
