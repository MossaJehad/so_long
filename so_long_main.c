/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:37 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/19 15:42:44 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player_position(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				data->player_x = j;
				data->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	init_game_images(t_data *data)
{
	data->img_player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_player)
		return (0);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_wall)
		return (0);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_floor)
		return (0);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_exit)
		return (0);
	data->img_coin = mlx_xpm_file_to_image(data->mlx, "assets/coin.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_coin)
		return (0);
	return (1);
}

int	validate_images(t_data *data)
{
	if (!data->img_player || !data->img_wall || !data->img_floor
		|| !data->img_exit || !data->img_coin)
	{
		write(2, "Error: Failed to load images\n", 29);
		if (data->img_player)
			mlx_destroy_image(data->mlx, data->img_player);
		if (data->img_wall)
			mlx_destroy_image(data->mlx, data->img_wall);
		if (data->img_floor)
			mlx_destroy_image(data->mlx, data->img_floor);
		if (data->img_exit)
			mlx_destroy_image(data->mlx, data->img_exit);
		if (data->img_coin)
			mlx_destroy_image(data->mlx, data->img_coin);
		return (0);
	}
	return (1);
}

void	make_data(t_data *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->img_player = NULL;
	data->img_wall = NULL;
	data->img_floor = NULL;
	data->img_exit = NULL;
	data->img_coin = NULL;
	data->img_height = 0;
	data->img_width = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->exit_x = 0;
	data->exit_y = 0;
	data->map = NULL;
	data->move_count = 0;
	data->collectibles_count = 0;
	data->collectibles_collected = 0;
}

void	check_name(char *name)
{
	char	*ber;
	int		i;
	int		j;

	if (ft_strlen(name) < 4)
	{
		write(2, "Error\nmap must name .ber\n", 25);
		exit(1);
	}
	i = 0;
	j = 3;
	ber = ".ber";
	while (name[i])
		i++;
	while (j >= 0)
	{
		if (ber[j--] != name[--i])
		{
			write(2, "Error\nmap must be name .ber\n", 28);
			exit(1);
		}
	}
}
