/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_receive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:23:47 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/03 20:33:00 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	map_get_lines(int *fd, char **map)
{
	char	*line;
	char	*temp;

	while (1)
	{
		line = get_next_line(*fd);
		if (!line)
			break ;
		temp = ft_strjoin(*map, line);
		free(line);
		if (!temp)
		{
			free(*map);
			return (put_error("Memory allocation has failed."));
		}
		free(*map);
		*map = temp;
	}
	return (1);
}

static void	map_set_dimensions(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.grid[i])
		i++;
	game->map.height = i;
	if (i > 0)
		game->map.width = ft_strlen(game->map.grid[0]);
}

int	map_read(t_game *game, const char *map_path)
{
	char	*map;
	int		fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (put_error("The map couldn't be opened"));
	map = ft_strdup("");
	if (!map || !map_get_lines(&fd, &map))
	{
		if (map)
			free (map);
		close(fd);
		return (put_error("Memory allocation has failed"));
	}
	game->map.grid = ft_split(map, '\n');
	free(map);
	close(fd);
	if (!game->map.grid || !game->map.grid[0])
		return (put_error("Map parsing has failed"));
	map_set_dimensions(game);
	return (1);
}
