/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:15:43 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/11 17:21:50 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/mlx/mlx.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

enum
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53
};

typedef struct s_gamedata
{
	void	*mlx;
	void	*mlx_window;

	char	*chosen_map;
	char	**map;
	char	**mapcopy;

	int		map_width;
	int		map_height;

	int		image_size;

	int		current_x;
	int		current_y;
	int		collectible_size;
	int		collectible_count;
	int		player_move_count;
	int		player_spawn_point_count;
	int		exit_count;

	char	directions;
	char	*direction_paths;
}	t_gamedata;

int		event_key(int keycode, t_gamedata *gamedata);

int		check_argc(int argc, char **argv);
int		get_height(t_gamedata *gamedata);
int		get_width(t_gamedata *gamedata);
int		map_lenght(t_gamedata *gamedata);
void	read_map(char *argv, t_gamedata *gamedata);

void	move_character_up(t_gamedata *gamedata);
void	move_character_down(t_gamedata *gamedata);
void	move_character_right(t_gamedata *gamedata);
void	move_character_left(t_gamedata *gamedata);
void	render_map(t_gamedata *gamedata);
void	xpm_control(t_gamedata *gamedata);
void	xpm_control2(t_gamedata *gamedata);
void	file_control(t_gamedata *gamedata, char *path);
void	identfy_player_directions(t_gamedata *gamedata, void *img);
void	object_path(t_gamedata *gamedata);
void	identfy_player(t_gamedata *gamedata, int x, int y);
void	identfy_exit(t_gamedata *gamedata, int x, int y);
void	identfy_collectible(t_gamedata *gamedata, int x, int y);
void	identfy_wall(t_gamedata *gamedata, int x, int y);
void	identfy_background(t_gamedata *gamedata, int x, int y);
void	identfy_map(t_gamedata *gamedata, int x, int y, char obj);
void	start_init(t_gamedata *gamedata);
void	player_movement(t_gamedata *gamedata, int current_x, int current_y);
void	get_initial_informations(t_gamedata *gamedata);
int		exit_game(t_gamedata *gamedata, int exit_mode);
void	exit_modes(int exit_mode);
void	map_control(t_gamedata *gamedata);
void	check_map_validate(t_gamedata *gamedata, int row_size, int column_size);
void	floodfill(t_gamedata *gamedata, int i, int j);
void	last_control(t_gamedata *gamedata);
void	free_map(char **map);
void	norminette_validate(t_gamedata *gamedata, int i, int j);
void	game_start_init(t_gamedata *gamedata);

#endif
