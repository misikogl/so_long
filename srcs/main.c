/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 03:13:11 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/11 16:42:53 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_start_init(t_gamedata *gamedata)
{
	gamedata->mlx = NULL;
	gamedata->mlx_window = NULL;
	gamedata->chosen_map = NULL;
	gamedata->map = NULL;
	gamedata->mapcopy = NULL;
	gamedata->map_width = 0;
	gamedata->map_height = 0;
	gamedata->image_size = 0;
	gamedata->current_x = 0;
	gamedata->current_y = 0;
	gamedata->collectible_size = 0;
	gamedata->collectible_count = 0;
	gamedata->player_move_count = 0;
	gamedata->player_spawn_point_count = 0;
	gamedata->exit_count = 0;
	gamedata->directions = 'W';
	gamedata->direction_paths = NULL;
}

int	main(int argc, char **argv)
{
	t_gamedata	*gamedata;

	if (!check_argc(argc, argv))
		return (0);
	gamedata = malloc(sizeof(t_gamedata));
	if (!gamedata)
		perror("Error\n");
	game_start_init(gamedata);
	gamedata->mlx = mlx_init();
	file_control(gamedata, argv[1]);
	xpm_control(gamedata);
	xpm_control2(gamedata);
	read_map(argv[1], gamedata);
	map_control(gamedata);
	render_map(gamedata);
	mlx_hook(gamedata->mlx_window, 2, 1L << 0, event_key, gamedata);
	mlx_hook(gamedata->mlx_window, 17, 1L << 17, exit_game, gamedata);
	system("leaks so_long");
	mlx_loop(gamedata->mlx);
}
