/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:00:00 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/19 15:46:02 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	setup_map(t_data *data, char *map_path)
{
	t_map_count	count;

	data->map = load_map(map_path);
	if (!data->map)
	{
		write(2, "Error: Failed to load map\n", 25);
		return (0);
	}
	if (!validate_map(data->map))
	{
		free_map(data->map);
		return (0);
	}
	has_valid_elements(data->map, &count);
	data->collectibles_count = count.collectible;
	data->collectibles_collected = 0;
	find_positions(data);
	return (1);
}

int	setup_window(t_data *data)
{
	int	map_height;
	int	map_width;

	map_height = 0;
	while (data->map[map_height])
		map_height++;
	map_width = 0;
	if (data->map[0])
		map_width = strlen(data->map[0]);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->img_width = 64;
	data->img_height = 64;
	data->mlx_win = mlx_new_window(data->mlx, map_width * data->img_width,
			map_height * data->img_height, "So Long");
	if (data->mlx_win == NULL)
		return (0);
	return (1);
}

void	initialize_game(t_data *data)
{
	data->move_count = 0;
	render_map(data);
	mlx_hook(data->mlx_win, 17, 0, close_button, data);
	mlx_key_hook(data->mlx_win, handle_input, data);
	mlx_loop(data->mlx);
}

int	handle_window_error(t_data *data)
{
	destroy_images(data);
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		data->mlx_win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
	if (data->map)
		free_map(data->map);
	write(2, "Error: Failed in mlx\n", 22);
	return (1);
}

int	main(int ac, char *av[])
{
	t_data	data;

	make_data(&data);
	if (ac != 2 || !av[1])
	{
		write(2, "Error please choose a map\n", 26);
		return (0);
	}
	check_name(av[1]);
	if (!setup_map(&data, av[1]))
		return (1);
	if (!setup_window(&data))
		return (handle_window_error(&data));
	if (!init_game_images(&data))
	{
		close_button(&data);
		return (1);
	}
	initialize_game(&data);
	return (0);
}
