/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 01:15:21 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/11 16:44:14 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_character_up(t_gamedata *gamedata)
{
	gamedata->directions = 'W';
	player_movement(gamedata, gamedata->current_x - 1, gamedata->current_y);
}

void	move_character_down(t_gamedata *gamedata)
{
	gamedata->directions = 'S';
	player_movement(gamedata, gamedata->current_x + 1, gamedata->current_y);
}

void	move_character_right(t_gamedata *gamedata)
{
	gamedata->directions = 'D';
	player_movement(gamedata, gamedata->current_x, gamedata->current_y + 1);
}

void	move_character_left(t_gamedata *gamedata)
{
	gamedata->directions = 'A';
	player_movement(gamedata, gamedata->current_x, gamedata->current_y - 1);
}

void	player_movement(t_gamedata *gamedata, int current_x, int current_y)
{
	if (gamedata->map[current_x][current_y] != 'E' && \
			gamedata->map[current_x][current_y] != '1')
	{
		if (gamedata->map[current_x][current_y] == 'C' && \
				gamedata->collectible_size != gamedata->collectible_count)
			gamedata->collectible_count += 1;
		gamedata->map[gamedata->current_x][gamedata->current_y] = '0';
		gamedata->current_x = current_x;
		gamedata->current_y = current_y;
		gamedata->map[current_x][current_y] = 'P';
		gamedata->player_move_count += 1;
		render_map(gamedata);
		ft_printf("MOVES: %d \n", gamedata->player_move_count);
	}
	else if (gamedata->collectible_size == gamedata->collectible_count && \
			gamedata->map[current_x][current_y] == 'E')
	{
		gamedata->player_move_count += 1;
		ft_printf("MOVES: %d \n", gamedata->player_move_count);
		exit_game(gamedata, 1);
	}
}
