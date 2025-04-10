/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 23:31:28 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/10 16:57:10 by mhasoneh         ###   ########.fr       */
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
	if (map[0][len - 1] == '\n')
		len--;
	i = 1;
	while (map[i])
	{
		line_len = ft_strlen(map[i]);
		if (map[i][line_len - 1] == '\n')
			line_len--;
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
	width = 0;
	while (map[0][width] && map[0][width] != '\n')
		width++;
	if (width < 3)
		return (0);
	return (1);
}

int	check_horizontal_walls(char **map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_vertical_walls(char **map, int width, int height)
{
	int	j;

	j = 0;
	while (j < height)
	{
		if (map[j][0] != '1' || map[j][width - 1] != '1')
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
	width = 0;
	while (map[0][width] && map[0][width] != '\n')
		width++;
	if (!check_map_dimensions(map))
		return (0);
	if (!check_horizontal_walls(map, width, height))
		return (0);
	if (!check_vertical_walls(map, width, height))
		return (0);
	return (1);
}
