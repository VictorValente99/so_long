/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:41:25 by victde-s          #+#    #+#             */
/*   Updated: 2025/11/27 17:49:16 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/minilibx/mlx.h"
#include "../libs/ft_printf/ft_printf.h"
#include "../libs/get_next_line/get_next_line.h"
#include "../libs/lib_ft/libft.h"
#include <fcntl.h>

#define SPRITE_SIZE 32

#define FLOOR_SPRITE "path"
#define WALL_SPRITE "path"
#define COLLECTIBLE_SPRITE "path"
#define EXIT_SPRITE "path"
#define OUT_SPRITE "path"

#define PLAYER_UP_SPRITE "path"
#define PLAYER_DOWN_SPRITE "path"
#define PLAYER_LEFT_SPRITE "path"
#define PLAYER_RIGTH_SPRITE "path"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define KEY_UP 65362
#define KEY_LEFT 65361
#define KEY_DOWN 65364
#define KEY_RIGTH 65363

#define ESC 65307

// ESTRUTURA DE DADOS PARA USO DA MINILIBX STATUS
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

//SPRITES
typedef struct s_img
{
	void	*wall;//1
	void	*floor;//0
	void	*player;//P
	void	*collectible;//C
	void	*exit;//E
}	t_img;

//PLAYER POSITION
typedef struct s_player_position
{
	int	x_pos;
	int	y_pos;
	int	movement_counter;
} t_player_position;

//MAPA
typedef struct s_map
{
	char	**grid;//vetor
	int		width;//largura
	int		height;//altura
	int		total_c;//total de coletaveis
	int		total_p;// posição inicial do p 
	int		total_e;//total de saídas
}	t_map;

//GLOBAL GAME STATUS
typedef struct s_game
{
	t_player_position	player;
	t_mlx				mlx;
	t_map				map;
	t_img				img;
}	t_game;


#endif