/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhasoneh <mhasoneh@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:14:02 by mhasoneh          #+#    #+#             */
/*   Updated: 2025/04/21 14:40:46 by mhasoneh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h> 
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>
# include "libft/libft.h"
# include <mlx.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_map_count
{
	int	player;
	int	exit;
	int	collectible;
	int	reached_collectibles;
	int	reached_exit;
}				t_map_count;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_coin;
	int		img_height;
	int		img_width;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	char	**map;
	int		move_count;
	int		collectibles_count;
	int		collectibles_collected;
}				t_data;

void	read_map_lines(int fd, char **map);
char	*read_buffer(int fd, char *buffer, int *byte);
char	*process_line(char *line, char *buffer);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		open_map_file(const char *filename);
void	process_map_line(char **map, int *i, char *line);
char	**load_map(const char *filename);
void	display_move_count(t_data *data);
void	render_map(t_data *data);
int		count_lines(const char *filename);
void	render_tile(t_data *data, int i, int j);

int		is_rectangular(char **map);
int		check_map_dimensions(char **map);
int		check_horizontal_walls(char **map, int width, int height);
int		check_vertical_walls(char **map, int width, int height);
int		has_valid_walls(char **map);

void	flood_fill(char **map_copy, int x, int y, t_map_count *count);
char	**create_map_copy(char **map);
void	find_player_start(char **map_copy, int *start_x, int *start_y);
void	free_map_copy(char **map_copy);
int		is_path_valid(char **map, t_map_count *count);

void	count_map_elements(char **map, t_map_count *count);
int		check_player_count(t_map_count *count);
int		check_exit_count(t_map_count *count);
int		check_collectible_count(t_map_count *count);
int		has_valid_elements(char **map, t_map_count *count);

int		validate_map(char **map);

int		handle_input(int keycode, t_data *data);
int		close_window(int keycode, t_data *data);
int		close_button(t_data *data);
void	free_map(char **map);
void	destroy_images(t_data *data);

void	find_player_position(t_data *data);
int		init_game_images(t_data *data);
int		validate_images(t_data *data);

int		setup_map(t_data *data, char *map_path);
int		setup_window(t_data *data);
void	initialize_game(t_data *data);
int		handle_window_error(t_data *data);

void	move_player(t_data *data, int dx, int dy);
int		is_valid_move(t_data *data, int x, int y);
void	handle_collectible(t_data *data, int x, int y);
int		is_exit(t_data *data, int x, int y);
void	update_player_position(t_data *data, int new_x, int new_y);
void	find_positions(t_data *data);
void	check_and_set_pos(t_data *data, int i, int j);
char	*rbuff(int fd, char *line);
char	*cleaner(char *line);
void	check_name(char *name);
void	make_data(t_data *data);
void	ft_free_so(char	**ptr);

#endif