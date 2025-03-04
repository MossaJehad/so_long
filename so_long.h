/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:40:37 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/03/04 16:23:29 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

#include <stdlib.h>
#include <unistd.h> 
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "minilibx/mlx.h"

typedef struct	s_data {
	void    *mlx;
    void    *mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	close_window(void *mlx, void *mlx_win);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif