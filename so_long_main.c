/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:37 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/10 16:57:53 by mhasoneh         ###   ########.fr       */
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

void	init_game_images(t_data *data)
{
	data->img_player = mlx_xpm_file_to_image(data->mlx, "assets/player.xpm",
			&data->img_width, &data->img_height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "assets/wall.xpm",
			&data->img_width, &data->img_height);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "assets/floor.xpm",
			&data->img_width, &data->img_height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "assets/exit.xpm",
			&data->img_width, &data->img_height);
	data->img_coin = mlx_xpm_file_to_image(data->mlx, "assets/coin.xpm",
			&data->img_width, &data->img_height);
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
