/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:33:51 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/02/27 15:33:51 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *mlx, void *mlx_win)
{
	mlx_destroy_window(mlx, mlx_win);
	mlx_loop_end(mlx);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	image;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 420, 360, "Hello world!");
	image.img = mlx_new_image(mlx, 420, 360);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
				&image.line_length, &image.endian);
	my_mlx_pixel_put(&image, 50, 50, 0x00FC0000);
	mlx_put_image_to_window(mlx, mlx_win, image.img, 50, 50);

	mlx_hook(mlx_win, 17, 0, close_window, mlx);
	mlx_loop(mlx);
}
