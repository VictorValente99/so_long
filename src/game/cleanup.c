/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 01:32:37 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/04 02:29:10 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void	free_map(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	cleanup_game(t_game *game)
{
	free_sprites(game);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if (game->map.grid)
		free_map(game->map.grid);
	if (game->mlx.mlx)
	{
		mlx_destroy_display(game->mlx.mlx);
		free(game->mlx.mlx);
	}
}

void	exit_game(t_game *game, char *message)
{
	if (message)
		ft_printf("%s\n", message);
	cleanup_game(game);
	exit(0);
}
