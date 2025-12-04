/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victde-s <victde-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:41:25 by victde-s          #+#    #+#             */
/*   Updated: 2025/12/03 21:44:23 by victde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libs/minilibx/mlx.h"
#include "../libs/ft_printf/ft_printf.h"
#include "../libs/get_next_line/get_next_line.h"
#include "../libs/lib_ft/libft.h"
#include <fcntl.h>

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECT 'C'
# define EXIT 'E'

#define SPRITE_SIZE 32

#define FLOOR_SPRITE "/assets/sprites/floor.xpm"
#define WALL_SPRITE "/assets/sprites/wall.xpm"
#define COLLECTIBLE_SPRITE "/assets/sprites/collectible.xpm"
#define EXIT_SPRITE "/assets/sprites/exit.xpm"
#define PLAYER_SPRITE "/assets/sprites/player.xpm"

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100

#define KEY_UP 65362
#define KEY_LEFT 65361
#define KEY_DOWN 65364
#define KEY_RIGHT 65363

#define ESC 65307

// ESTRUTURA DE DADOS PARA USO DA MINILIBX STATUS
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
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
typedef struct s_player
{
	int	direction;
	int	x;
	int	y;
	int	steps;
} t_player_position;

//MAPA
typedef struct s_map
{
	char	**grid;//vetor
	int		width;//largura
	int		height;//altura
	int		total_c;//total de coletaveis
	int		total_p;// total de p 
	int		total_e;//total de saídas
}	t_map;

typedef struct s_path_data
{
	int	collected;
	int	exit_found;
}	t_path_data;

//GLOBAL GAME STATUS
typedef struct s_game
{
	t_player_position	player;
	t_mlx				mlx;
	t_map				map;
	t_img				img;
}	t_game;

int		is_true_element(char c);
int		map_elements(char **grid);
int		validate_elements_count(t_game *game);
int		check_valid_path(t_game *game);
int		map_read(t_game *game, const char *map_path);
int		validate_map(t_game *game);
int		map_check_extension(const char *filename, const char *extension);
int		put_error(char *message);
int		load_sprites(t_game *game);
void	free_sprites(t_game *game);

/* Protótipos - Renderização */
void	render_game(t_game *game);
/* Protótipos - Input */
int		key_press(int keycode, t_game *game);
/* Protótipos - Cleanup */
void	cleanup_game(t_game *game);
void	exit_game(t_game *game, char *message);

#endif