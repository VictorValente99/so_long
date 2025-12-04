/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:43:09 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/04 02:29:35 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_sprites(t_game *game)
{
	if (game->img.wall)
		mlx_destroy_image(game->mlx.mlx, game->img.wall);
	if (game->img.floor)
		mlx_destroy_image(game->mlx.mlx, game->img.floor);
	if (game->img.player)
		mlx_destroy_image(game->mlx.mlx, game->img.player);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx.mlx, game->img.collectible);
	if (game->img.exit)
		mlx_destroy_image(game->mlx.mlx, game->img.exit);
}
