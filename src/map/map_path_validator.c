/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_validator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:06:56 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/03 19:27:23 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static char	**copy_map(char **grid, int height)
{
	char	**new_map;
	int		i;

	new_map = malloc(sizeof(char *) * (height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_map[i] = ft_strdup(grid[i]);
		if (!new_map[i])
		{
			while (i > 0)
				free(new_map[--i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

static void	find_player(t_game *game, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.grid[i][j] == PLAYER)
			{
				*x = j;
				*y = i;
				game->player.x = j;
				game->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	flood_fill(char **map, int x, int y, t_path_data *data)
{
	if (map[y][x] == WALL)
		return ;
	if (map[y][x] == 'V')
		return ;
	if (map[y][x] == COLLECT)
		data->collected++;
	if (map[y][x] == EXIT)
		data->exit_found++;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
}

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	check_valid_path(t_game *game)
{
	char		**map_copy;
	int			player_x;
	int			player_y;
	t_path_data	data;

	map_copy = copy_map(game->map.grid, game->map.height);
	if (!map_copy)
		return (put_error("Memory allocation has failed"));
	find_player(game, &player_x, &player_y);
	data.collected = 0;
	data.exit_found = 0;
	flood_fill(map_copy, player_x, player_y, &data);
	free_map(map_copy);
	if (data.collected != game->map.total_c)
		return (put_error("Invalid path: can't reach all collectibles"));
	if (data.exit_found != 1)
		return (put_error("Invalid path: can't reach the exit"));
	return (1);
}
