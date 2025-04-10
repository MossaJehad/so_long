/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:57:19 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/10 16:57:19 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map_copy, int x, int y, t_map_count *count)
{
	if (y < 0 || x < 0 || !map_copy[y] || !map_copy[y][x]
		|| map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		count->reached_collectibles++;
	else if (map_copy[y][x] == 'E')
		count->reached_exit++;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, count);
	flood_fill(map_copy, x - 1, y, count);
	flood_fill(map_copy, x, y + 1, count);
	flood_fill(map_copy, x, y - 1, count);
}

char	**create_map_copy(char **map)
{
	char	**map_copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	map_copy = malloc(sizeof(char *) * (i + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map_copy[i] = strdup(map[i]);
		if (!map_copy[i])
		{
			while (i > 0)
				free(map_copy[--i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	find_player_start(char **map_copy, int *start_x, int *start_y)
{
	int	i;
	int	j;

	i = 0;
	*start_x = -1;
	*start_y = -1;
	while (map_copy[i])
	{
		j = 0;
		while (map_copy[i][j])
		{
			if (map_copy[i][j] == 'P')
			{
				*start_x = j;
				*start_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	free_map_copy(char **map_copy)
{
	int	i;

	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
}

int	is_path_valid(char **map, t_map_count *count)
{
	char	**map_copy;
	int		start_x;
	int		start_y;
	int		valid;

	map_copy = create_map_copy(map);
	if (!map_copy)
		return (0);
	find_player_start(map_copy, &start_x, &start_y);
	count->reached_collectibles = 0;
	count->reached_exit = 0;
	flood_fill(map_copy, start_x, start_y, count);
	valid = (count->reached_collectibles == count->collectible
			&& count->reached_exit == count->exit);
	free_map_copy(map_copy);
	return (valid);
}
