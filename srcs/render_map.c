/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:58:34 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/11 16:47:56 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	object_path(t_gamedata *gamedata)
{
	char	*path;

	if (gamedata->directions == 'W')
		path = "xpms/player/player_up.xpm";
	if (gamedata->directions == 'A')
		path = "xpms/player/player_left.xpm";
	if (gamedata->directions == 'S')
		path = "xpms/player/player_down.xpm";
	if (gamedata->directions == 'D')
		path = "xpms/player/player_right.xpm";
	gamedata->direction_paths = path;
}

void	identfy_map(t_gamedata *gamedata, int x, int y, char obj)
{
	if (obj == '1' || obj == 'E' || obj == '0' || obj == 'C' || obj == 'P')
		identfy_background(gamedata, x, y);
	if (obj == '1')
		identfy_wall(gamedata, x, y);
	if (obj == 'P')
	{
		object_path(gamedata);
		identfy_player(gamedata, x, y);
	}
	if (obj == 'C')
		identfy_collectible(gamedata, x, y);
	if (obj == 'E')
		identfy_exit(gamedata, x, y);
}

void	render_map(t_gamedata *gamedata)
{
	int	i;
	int	j;
	int	x;
	int	y;

	mlx_clear_window(gamedata->mlx, gamedata->mlx_window);
	i = 0;
	y = 0;
	while (gamedata->map[i])
	{
		x = 0;
		j = 0;
		while (gamedata->map[i][j])
		{
			identfy_map(gamedata, x, y, gamedata->map[i][j]);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
