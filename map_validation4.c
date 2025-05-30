/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:00:00 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/05/01 16:49:25 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(char **map)
{
	t_map_count	count;

	if (!map)
		return (0);
	if (!is_rectangular(map))
	{
		write(2, "Error\nMap is not complete!\n", 29);
		return (0);
	}
	if (!has_valid_walls(map))
	{
		write(2, "Error\nMap is not surrounded by walls\n", 39);
		return (0);
	}
	if (!has_valid_elements(map, &count))
	{
		write(2, "Error\nMap has invalid elements\n", 33);
		return (0);
	}
	if (!is_path_valid(map, &count))
	{
		write(2, "Error\nNot all collectibles or exit are reachable\n", 51);
		return (0);
	}
	return (1);
}

void	find_positions(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->player_x = -1;
	data->player_y = -1;
	data->exit_x = -1;
	data->exit_y = -1;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			check_and_set_pos(data, i, j);
			if (data->player_x != -1 && data->exit_x != -1)
				return ;
			j++;
		}
		i++;
	}
}

void	check_and_set_pos(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		data->player_x = j;
		data->player_y = i;
	}
	else if (data->map[i][j] == 'E')
	{
		data->exit_x = j;
		data->exit_y = i;
	}
}

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nUnable to open file\n", 28);
		return (-1);
	}
	return (fd);
}

void	process_map_line(char **map, int *i, char *line)
{
	int	j;

	if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	map[*i] = ft_strdup(line);
	if (!map[*i])
	{
		j = 0;
		while (j < *i)
		{
			free(map[j]);
			j++;
		}
	}
	(*i)++;
	free(line);
}
