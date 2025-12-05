/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 01:43:11 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/05 18:20:19 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int	close_window(t_game *game)
{
	exit_game(game, "Didn't you like me? kkkrying");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (put_error("Usage: ./so_long <map.ber>"));
	if (!map_check_extension(argv[1], ".ber"))
		return (put_error("Map must have .ber extension"));
	if (!game_init(&game))
		return (1);
	if (!map_read(&game, argv[1]))
		return (cleanup_game(&game), 1);
	if (!validate_map(&game))
		return (cleanup_game(&game), 1);
	if (!load_sprites(&game))
		return (cleanup_game(&game), 1);
	game.mlx.win = mlx_new_window(game.mlx.mlx,
			game.map.width * SPRITE_SIZE,
			game.map.height * SPRITE_SIZE, "So Long");
	if (!game.mlx.win)
		return (cleanup_game(&game), put_error("Failed to create window"));
	render_game(&game);
	mlx_hook(game.mlx.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx.mlx);
	return (0);
}
