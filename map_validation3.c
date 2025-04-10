/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:00:00 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/10 16:57:36 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_map_elements(char **map, t_map_count *count)
{
	int	m[2];

	count->player = 0;
	count->exit = 0;
	count->collectible = 0;
	m[0] = 0;
	while (map[m[0]])
	{
		m[1] = 0;
		while (map[m[0]][m[1]])
		{
			if (map[m[0]][m[1]] == '\n')
				m[1]++;
			else if (map[m[0]][m[1]] == 'P')
				count->player++;
			else if (map[m[0]][m[1]] == 'E')
				count->exit++;
			else if (map[m[0]][m[1]] == 'C')
				count->collectible++;
			else if (map[m[0]][m[1]] != '0' && map[m[0]][m[1]] != '1')
				count->player = -1;
			m[1]++;
		}
		m[0]++;
	}
}

int	check_player_count(t_map_count *count)
{
	if (count->player != 1)
	{
		write(2, "Error: Map must contain exactly one player 'P'\n", 47);
		return (0);
	}
	return (1);
}

int	check_exit_count(t_map_count *count)
{
	if (count->exit != 1)
	{
		write(2, "Error: only 1 exit should be exist\n", 36);
		return (0);
	}
	return (1);
}

int	check_collectible_count(t_map_count *count)
{
	if (count->collectible < 1)
	{
		write(2, "Error: Map must contain at least one collectible 'C'\n", 54);
		return (0);
	}
	return (1);
}

int	has_valid_elements(char **map, t_map_count *count)
{
	count_map_elements(map, count);
	if (count->player == -1)
		return (0);
	if (!check_player_count(count))
		return (0);
	if (!check_exit_count(count))
		return (0);
	if (!check_collectible_count(count))
		return (0);
	return (1);
}
