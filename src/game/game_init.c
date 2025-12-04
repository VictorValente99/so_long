/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:36:42 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/04 02:01:10 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	game_init(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		return (put_error("Failed to init MLX"));
	return (1);
}
