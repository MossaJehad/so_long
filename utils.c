/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:43 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/21 17:04:01 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nUnable to open file\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
		ft_free_so(&line);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

char	**load_map(const char *filename)
{
	int		fd;
	int		line_count;
	char	**map;

	line_count = count_lines(filename);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	fd = open_map_file(filename);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}
	read_map_lines(fd, map);
	close(fd);
	return (map);
}

void	display_move_count(t_data *data)
{
	char	*count_str;

	count_str = ft_itoa(data->move_count);
	if (count_str)
	{
		write(1, "Move count: ", 12);
		write(1, count_str, ft_strlen(count_str));
		write(1, "\n", 1);
		free(count_str);
	}
}

void	render_tile(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_floor, j
		* data->img_width, i * data->img_height);
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_wall, j
			* data->img_width, i * data->img_height);
	else if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_player, j
			* data->img_width, i * data->img_height);
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_coin, j
			* data->img_width, i * data->img_height);
	else if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_exit, j
			* data->img_width, i * data->img_height);
}

void	render_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data->mlx, data->mlx_win);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			render_tile(data, i, j);
			j++;
		}
		i++;
	}
}
