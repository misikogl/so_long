/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:35:44 by misikogl          #+#    #+#             */
/*   Updated: 2022/10/11 16:47:26 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_height(t_gamedata *gamedata)
{
	int		i;
	int		fd;
	char	c;

	i = 0;
	fd = open(gamedata->chosen_map, O_RDONLY);
	if (fd < 0)
		exit_game(gamedata, 0);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	close (fd);
	return (i + 1);
}

int	get_width(t_gamedata *gamedata)
{
	int		j;
	int		fd;
	char	c;

	j = 0;
	fd = open(gamedata->chosen_map, O_RDONLY);
	if (fd < 0)
		exit_game(gamedata, 0);
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		j++;
	}
	close(fd);
	return (j);
}

int	map_lenght(t_gamedata *gamedata)
{
	int		i_read;
	int		fd;
	char	c;

	i_read = 0;
	fd = open(gamedata->chosen_map, O_RDONLY);
	if (fd < 0)
		exit_game(gamedata, 0);
	while (read(fd, &c, 1))
		i_read++;
	close(fd);
	return (i_read);
}

void	get_initial_informations(t_gamedata *gamedata)
{
	int	i;
	int	j;

	i = 0;
	while (gamedata->map[i])
	{
		j = 0;
		while (gamedata->map[i][j])
		{
			if (gamedata->map[i][j] == 'C')
				gamedata->collectible_size += 1;
			if (gamedata->map[i][j] == 'E')
				gamedata->exit_count += 1;
			if (gamedata->map[i][j] == 'P')
			{
				gamedata->player_spawn_point_count += 1;
				gamedata->current_x = i;
				gamedata->current_y = j;
			}
			j++;
		}
		i++;
	}
}

void	read_map(char *argv, t_gamedata *gamedata)
{
	int		fd;
	int		len;
	char	*mapp;

	gamedata->chosen_map = argv;
	fd = open(gamedata->chosen_map, O_RDONLY);
	if (fd < 0)
		exit_game(gamedata, 0);
	len = map_lenght(gamedata);
	mapp = malloc(sizeof(char) * len + 1);
	read(fd, mapp, len);
	mapp[len] = '\0';
	gamedata->map = ft_split(mapp, '\n');
	gamedata->mapcopy = ft_split(mapp, '\n');
	gamedata->map_width = 64 * get_width(gamedata);
	gamedata->map_height = 64 * get_height(gamedata);
	gamedata->mlx_window = mlx_new_window(gamedata->mlx, gamedata->map_width, \
			gamedata->map_height, "Catnap the alien cats!");
	get_initial_informations(gamedata);
	close(fd);
	free(mapp);
}
