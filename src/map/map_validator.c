/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:59:13 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/02 18:09:50 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	map_check_extension(char *filename, char *extension)
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

static int	is_map_retangular(char **grid)
{
	int	ref_len;
	int	i;

	if (!grid || !grid[0])
		return (0);
	ref_len = ft_strlen(grid[0]);
	i = 1;
	while (grid[i])
	{
		if(ft_strlen(grid[i]) != ref_len)
		{
			put_error("Map must be rectangular");
			return (0);
		}
		i++;
	}
	return (1);
}
static int	map_check_borders(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->map.width)
	{
		if (game->map.grid[0][x] != WALL
			|| game->map.grid[game->map.height - 1][x] != WALL)
			return (message_error("Map must be surrounded by walls (1)!"));
		x++;
	}
	while (y < game->map.height)
	{
		if (game->map.grid[y][0] != WALL
			|| game->map.grid[y][game->map.width - 1] != WALL)
			return (message_error("Map must be surrounded by walls (1)!"));
		y++;
	}
	return (1);
}
static int	map_elements(char **grid)
{
	int	x;
	int	y;

	if (!grid)
		return (0);	
	y = 0;
	while(grid[y] != NULL)
	{
		x = 0;
		while (grid[y][x] != '\0')
		{
			if (!is_true_element(grid[y][x]))
				return (put_error("Invalid char in the map\n"));
			x++;
		}
		y++;
	}
	return (1);
}