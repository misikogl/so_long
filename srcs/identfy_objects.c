/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identfy_objects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:40:33 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/09 23:50:35 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	identfy_background(t_gamedata *gamedata, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(gamedata->mlx, \
			"./xpms/background/background.xpm", \
			&gamedata->image_size, &gamedata->image_size);
	if (img == NULL)
		exit_game(gamedata, 0);
	mlx_put_image_to_window(gamedata->mlx, gamedata->mlx_window, img, x, y);
}

void	identfy_wall(t_gamedata *gamedata, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(gamedata->mlx, "./xpms/walls/wall.xpm", \
			&gamedata->image_size, &gamedata->image_size);
	if (img == NULL)
		exit_game(gamedata, 0);
	mlx_put_image_to_window(gamedata->mlx, gamedata->mlx_window, img, x, y);
}

void	identfy_collectible(t_gamedata *gamedata, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(gamedata->mlx, "./xpms/collectible/cat.xpm", \
			&gamedata->image_size, &gamedata->image_size);
	if (img == NULL)
		exit_game(gamedata, 0);
	mlx_put_image_to_window(gamedata->mlx, gamedata->mlx_window, img, x, y);
}

void	identfy_exit(t_gamedata *gamedata, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(gamedata->mlx, "./xpms/exit/exit.xpm", \
			&gamedata->image_size, &gamedata->image_size);
	if (img == NULL)
		exit_game(gamedata, 0);
	mlx_put_image_to_window(gamedata->mlx, gamedata->mlx_window, img, x, y);
}

void	identfy_player(t_gamedata *gamedata, int x, int y)
{
	void	*img;

	img = mlx_xpm_file_to_image(gamedata->mlx, gamedata->direction_paths, \
			&gamedata->image_size, &gamedata->image_size);
	if (img == NULL)
		exit_game(gamedata, 0);
	mlx_put_image_to_window(gamedata->mlx, gamedata->mlx_window, img, x, y);
}
