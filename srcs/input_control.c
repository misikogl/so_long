/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 19:36:05 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/15 21:19:00 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_modes(int exit_mode)
{
	if (exit_mode == 0)
		perror("Error\n");
	if (exit_mode == 1)
		ft_printf("🪐🪐🪐🪐THE CATS ARE SAFE🪐🪐🪐🪐");
	if (exit_mode == 2)
		ft_printf("THE CATS NEED YOUR HELP!!!");
	if (exit_mode == 3)
		ft_printf ("Error\nTHE GAME ACCEPTS ONLY ONE PLAYER!!!");
	if (exit_mode == 4)
		ft_printf ("Error\nTHE COLLECTIBLES MUST BE MORE THAN ZERO!!!");
	if (exit_mode == 5)
		ft_printf("Error\nTHE FILE MUST BE '.xpm'!!!\n");
	if (exit_mode == 6)
		ft_printf("Error\nTHE GAME ACCEPTS ONLY ONE EXIT!!!");
}

int	exit_game(t_gamedata *gamedata, int exit_mode)
{
	(void)gamedata;
	exit_modes(exit_mode);
	exit(EXIT_SUCCESS);
}

int	event_key(int keycode, t_gamedata *gamedata)
{
	if (keycode == W)
		move_character_up(gamedata);
	if (keycode == S)
		move_character_down(gamedata);
	if (keycode == D)
		move_character_right(gamedata);
	if (keycode == A)
		move_character_left(gamedata);
	if (keycode == ESC)
		exit_game(gamedata, 2);
	return (0);
}

int	check_argc(int argc, char **argv)
{
	int	map_len;

	if (argc < 2)
	{
		ft_printf("Error\nWHERE İS THE MAP!!!");
		return (0);
	}
	if (argc > 2)
	{
		ft_printf("Error\nTOO MANY ARGUMENTS");
		return (0);
	}
	map_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_len - 4], ".ber", 4))
	{
		ft_printf("Error\nMAP EXTENSION MUST BE '.ber'");
		return (0);
	}
	return (1);
}

void	file_control(t_gamedata *gamedata, char *path)
{
	int	file;

	file = open(path, O_RDWR);
	if (file <= 0)
	{
		close(file);
		exit_game(gamedata, 0);
	}
	close(file);
}
