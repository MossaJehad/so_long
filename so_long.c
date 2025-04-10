/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:39 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/10 16:57:58 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keycode, t_data *data)
{
	if (keycode == 65307)
		close_window(keycode, data);
	else if (keycode == 119)
		move_player(data, 0, -1);
	else if (keycode == 115)
		move_player(data, 0, 1);
	else if (keycode == 97)
		move_player(data, -1, 0);
	else if (keycode == 100)
		move_player(data, 1, 0);
	return (0);
}

void	destroy_images(t_data *data)
{
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
}

int	close_window(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		destroy_images(data);
		if (data->map)
			free_map(data->map);
		if (data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		exit(0);
	}
	return (0);
}

int	close_button(t_data *data)
{
	destroy_images(data);
	if (data->map)
		free_map(data->map);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
