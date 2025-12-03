/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements_validator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:50:29 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/03 19:37:29 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	is_true_element(char c)
{
	if (c == WALL || c == FLOOR || c == COLLECT)
		return (1);
	if (c == EXIT || c == PLAYER)
		return (1);
	return (0);
}

static int	map_elements(char **grid)
{
	int	x;
	int	y;

	if (!grid)
		return (0);
	y = 0;
	while (grid[y] != NULL)
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

static void	count_elements(char **grid, int *p, int *c, int *e)
{
	int	x;
	int	y;

	y = 0;
	*p = 0;
	*c = 0;
	*e = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == PLAYER)
				(*p)++;
			else if (grid[y][x] == EXIT)
				(*e)++;
			else if (grid[y][x] == COLLECT)
				(*c)++;
			x++;
		}
		y++;
	}
}

static int	validate_elements_count(t_game *game)
{
	int	player;
	int	exit;
	int	collect;

	count_elements(game->map.grid, &player, &exit, &collect);
	if (player != 1)
		return (put_error("Map must have at least one player"));
	if (exit != 1)
		return (put_error("Map must have at least one exit"));
	if (collect < 1)
		return (put_error("Map must have at least one collectible"));
	game->map.total_c = collect;
	return (1);
}
