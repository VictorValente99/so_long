/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 00:20:11 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/04 00:41:18 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	*get_sprite(t_game *game, char tile)
{
	if (tile == WALL)
		return (game->img.wall);
	else if (tile == FLOOR)
		return (game->img.floor);
	else if (tile == PLAYER)
		return (game->img.player);
	else if (tile == COLLECT)
		return (game->img.collectible);
	else if (tile == EXIT)
		return (game->img.exit);
	return (game->img.floor);
}

void	render_game(t_game *game)
{
	void	*sprite;
	int		x;
	int		y;	

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			sprite = get_sprite(game, game->map.grid[y][x]);
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.win,
				sprite, x * SPRITE_SIZE, y * SPRITE_SIZE);
			x++;
		}
		y++;
	}
}
