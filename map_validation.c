/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:28 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/21 17:06:15 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	size_t	len;
	int		i;
	size_t	line_len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	if (len > 0 && map[0][len - 1] == '\n')
		len--;
	i = 1;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if (line_len > 0 && map[i][line_len - 1] == '\n')
		{
			line_len--;
		}
		if (line_len != len)
			return (0);
		i++;
	}
	return (1);
}

int	check_map_dimensions(char **map)
{
	int	height;
	int	width;

	height = 0;
	while (map[height])
		height++;
	if (height < 3)
		return (0);
	if (!map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (width > 0 && map[0][width - 1] == '\n')
		width--;
	if (width < 3)
		return (0);
	return (1);
}

int	check_horizontal_walls(char **map, int width, int height)
{
	int	i;
	int	map_width;

	map_width = ft_strlen(map[0]);
	if (map_width > 0 && map[0][map_width - 1] == '\n')
		map_width--;
	i = 0;
	while (i < width)
	{
		if (i >= (int)ft_strlen(map[0]) || (map[0][i] == '\n'
			&& i == (int)ft_strlen(map[0]) - 1) || map[0][i] != '1')
			return (0);
		if (i >= (int)ft_strlen(map[height - 1]) || (map[height - 1][i] == '\n'
			&& i == (int)ft_strlen(map[height - 1]) - 1) || map[height
			- 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_vertical_walls(char **map, int width, int height)
{
	int		j;
	size_t	current_line_len;

	j = 0;
	while (j < height)
	{
		current_line_len = ft_strlen(map[j]);
		if (current_line_len > 0 && map[j][current_line_len - 1] == '\n')
			current_line_len--;
		if (map[j][0] != '1')
			return (0);
		if (current_line_len < (size_t)width || map[j][width - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	has_valid_walls(char **map)
{
	int	height;
	int	width;

	height = 0;
	while (map[height])
		height++;
	if (height == 0 || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	if (width <= 0)
		return (0);
	if (width > 0 && map[0][width - 1] == '\n')
		width--;
	if (!check_map_dimensions(map))
		return (0);
	if (!check_horizontal_walls(map, width, height))
		return (0);
	if (!check_vertical_walls(map, width, height))
		return (0);
	return (1);
}
