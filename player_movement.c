/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:34 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/10 16:57:44 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_data *data, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	if (!is_valid_move(data, new_x, new_y))
		return ;
	handle_collectible(data, new_x, new_y);
	if (is_exit(data, new_x, new_y))
		return ;
	update_player_position(data, new_x, new_y);
	data->move_count++;
	render_map(data);
	display_move_count(data);
}

int	is_valid_move(t_data *data, int x, int y)
{
	if (x < 0 || y < 0 || !data->map[y] || !data->map[y][x]
		|| data->map[y][x] == '1')
		return (0);
	return (1);
}

void	handle_collectible(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
	{
		data->collectibles_collected++;
		data->map[y][x] = '0';
		write(1, "Collectible picked up!\n", 23);
	}
}

int	is_exit(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'E')
	{
		if (data->collectibles_collected == data->collectibles_count)
		{
			data->move_count++;
			display_move_count(data);
			write(1, "Congratulations! You reached the exit!\n", 39);
			close_window(65307, data);
			return (1);
		}
		else
		{
			write(1, "Exit reached, but collect all items first!\n", 44);
			return (0);
		}
	}
	return (0);
}

void	update_player_position(t_data *data, int new_x, int new_y)
{
	if (data->player_x == data->exit_x && data->player_y == data->exit_y)
	{
		data->map[data->player_y][data->player_x] = 'E';
	}
	else
	{
		data->map[data->player_y][data->player_x] = '0';
	}
	data->player_x = new_x;
	data->player_y = new_y;
	data->map[data->player_y][data->player_x] = 'P';
}
