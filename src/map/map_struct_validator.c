/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct_validator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:59:13 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/03 20:32:05 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

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
		if (ft_strlen(grid[i]) != ref_len)
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
			return (put_error("Map must be surrounded by walls (1)!"));
		x++;
	}
	while (y < game->map.height)
	{
		if (game->map.grid[y][0] != WALL
			|| game->map.grid[y][game->map.width - 1] != WALL)
			return (put_error("Map must be surrounded by walls (1)!"));
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!game || !game->map.grid)
		return (put_error("No map received"));
	if (!is_map_retangular(game->map.grid))
		return (0);
	if (!map_elements(game->map.grid))
		return (0);
	if (!map_check_borders(game))
		return (0);
	if (!validate_elements_count(game))
		return (0);
	if (!check_valid_path(game))
		return (0);
	return (1);
}
