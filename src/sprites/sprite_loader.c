/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_loader.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:20:20 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/03 21:48:17 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	load_sprites(t_game *game)
{
	int	width;
	int	height;
	
	game->img.wall = mlx_xpm_file_to_image(game->mlx.mlx,
			WALL_SPRITE, &width, &height);
	game->img.floor = mlx_xpm_file_to_image(game->mlx.mlx,
			FLOOR_SPRITE, &width, &height);
	game->img.player = mlx_xpm_file_to_image(game->mlx.mlx,
			PLAYER_SPRITE, &width, &height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx.mlx,
			COLLECTIBLE_SPRITE, &width, &height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx.mlx,
			EXIT_SPRITE, &width, &height);
	if (!game->img.wall || !game->img.floor || !game->img.player
			|| !game->img.collectible || !game->img.exit)
			{
				free_sprites(game);
				return (put_error("Failed to load sprites"));
			}
		return (1);
}
