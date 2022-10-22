/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 00:12:58 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/11 16:53:09 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floodfill(t_gamedata *gamedata, int i, int j)
{
	if (gamedata->current_x < 0 || \
			gamedata->current_x >= get_height(gamedata) || \
			gamedata->current_y < 0 || \
			gamedata->current_y >= get_width(gamedata))
		return ;
	if (gamedata->mapcopy[i][j] == 'E')
		gamedata->mapcopy[i][j] = '1';
	if (gamedata->mapcopy[i][j] == '1')
		return ;
	if (gamedata->mapcopy[i][j] == 'C' || gamedata->mapcopy[i][j] == 'E' || \
			gamedata->mapcopy[i][j] == '0' || gamedata->mapcopy[i][j] == 'P')
		gamedata->mapcopy[i][j] = '1';
	floodfill(gamedata, i + 1, j);
	floodfill(gamedata, i - 1, j);
	floodfill(gamedata, i, j + 1);
	floodfill(gamedata, i, j - 1);
}

void	last_control(t_gamedata *gamedata)
{
	int	i;
	int	j;

	i = 0;
	while (gamedata->mapcopy[i])
	{
		j = 0;
		while (gamedata->mapcopy[i][j])
		{
			if (gamedata->mapcopy[i][j] == 'C' || \
					gamedata->mapcopy[i][j] == 'E')
				exit_game(gamedata, 0);
			j++;
		}
		i++;
	}
}
