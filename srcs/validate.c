/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:03:52 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/15 20:21:37 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	xpm_control(t_gamedata *gamedata)
{
	int	fd_bground;
	int	fd_collectible;
	int	fd_exit;
	int	fd_wall;

	fd_bground = open("xpms/background/background.xpm", O_RDWR);
	fd_collectible = open("xpms/collectible/cat.xpm", O_RDWR);
	fd_exit = open("xpms/exit/exit.xpm", O_RDWR);
	fd_wall = open("xpms/walls/wall.xpm", O_RDWR);
	if (fd_bground <= 0 || fd_collectible <= 0 || fd_exit <= 0 || fd_wall <= 0)
	{
		close(fd_bground);
		close(fd_collectible);
		close(fd_exit);
		close(fd_wall);
		exit_game(gamedata, 5);
	}
	close(fd_bground);
	close(fd_collectible);
	close(fd_exit);
	close(fd_wall);
}

void	xpm_control2(t_gamedata *gamedata)
{
	int	fd_player;

	fd_player = open("xpms/player/player_down.xpm", O_RDWR);
	fd_player = open("xpms/player/player_left.xpm", O_RDWR);
	fd_player = open("xpms/player/player_right.xpm", O_RDWR);
	fd_player = open("xpms/player/player_up.xpm", O_RDWR);
	if (fd_player <= 0)
	{
		close(fd_player);
		exit_game(gamedata, 5);
	}
	close(fd_player);
}

void	map_control(t_gamedata *gamedata)
{
	int	i;
	int	j;

	i = gamedata->current_x;
	j = gamedata->current_y;
	check_map_validate(gamedata, get_height(gamedata), get_width(gamedata) - 1);
	floodfill(gamedata, i, j);
	last_control(gamedata);
	if (gamedata->player_spawn_point_count != 1)
		exit_game(gamedata, 3);
	if (gamedata->collectible_size < 1)
		exit_game(gamedata, 4);
	if (gamedata->exit_count != 1)
		exit_game(gamedata, 6);
}

void	check_map_validate(t_gamedata *gamedata, int column_size, int row_size)
{
	int	i;
	int	j;

	i = 0;
	while (gamedata->map[i])
	{
		j = 0;
		while (gamedata->map[i][j])
		{
			if (i == column_size && gamedata->map[i][j] != '1')
				exit_game(gamedata, 0);
			if (j == row_size && gamedata->map[i][j] != '1')
				exit_game(gamedata, 0);
			norminette_validate(gamedata, i, j);
			j++;
		}
		if (row_size != j - 1)
			exit_game(gamedata, 3);
		i++;
	}
}

void	norminette_validate(t_gamedata *gamedata, int i, int j)
{
	if (i == 0 && gamedata->map[i][j] != '1')
		exit_game(gamedata, 0);
	if (j == 0 && gamedata->map[i][j] != '1')
		exit_game(gamedata, 0);
	if (gamedata->map[i][j] != '0' && gamedata->map[i][j] != 'P' && \
			gamedata->map[i][j] != 'C' && gamedata->map[i][j] != 'E' && \
			gamedata->map[i][j] != '1')
		exit_game(gamedata, 0);
}
