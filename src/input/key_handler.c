/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 00:43:23 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/04 01:26:49 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == WALL)
		return ;
	if (game->map.grid[new_y][new_x] == COLLECT)
	{
		game->map.total_c--;
		game->map.grid[new_y][new_x] = FLOOR;
	}
	if (game->map.grid[new_y][new_x] == EXIT)
	{
		if (game->map.total_c == 0)
			exit_game(game, "GURLLLL YOU SLAY!! (.Y.)");
		return ;
	}
	game->map.grid[game->player.y][game->player.x] = FLOOR;
	game->map.grid[new_y][new_x] = PLAYER;
	game->player.x = new_x;
	game->player.y = new_y;
	game->player.steps++;
	ft_printf("Steps: %d\n", game->player.steps);
	render_game(game);
}

int	key_press(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (keycode == ESC)
		exit_game(game, "Bye darling! XOXO <3");
	else if (keycode == KEY_W || keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new_x++;
	else
		return (0);
	move_player(game, new_x, new_y);
	return (0);
}
