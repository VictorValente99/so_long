/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:36:42 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/01 18:32:37 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	game_find_player(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == PLAYER)
			{
				game->player.y = y;
				game->player.x = x;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (put_error("Player not found!"));
	}
static int	game_load_sprites_map(t_game *game)
{
	
}
static int	game_load_sprites_player(t_game *game)
{
	
}
int	game_init(t_game *game)
{
	if (!game_find_player(game))
		return (0);
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (message_error("Failed to init MLX!"));
	game->mlx.win = mlx_new_window(game->mlx.mlx,
			game->map.width * SPRITE_SIZE,
			game->map.height * SPRITE_SIZE, "so long");
	if (!game->mlx.win)
	{
		cleanup_game(game);
		return (message_error("Failed to create window!"));
	}
	if (!game_load_sprites_map(game) || !game_load_sprites_player(game))
	{
		cleanup_game(game);
		return (0);
	}
	game->map.total_c = map_count_element(game->map.grid, COLLECT);
	game->player.direction = PLAYER_RIGHT_SPRITE;
	game->player.steps = 0;
	return (1);
}
