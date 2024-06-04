/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:30:14 by liath             #+#    #+#             */
/*   Updated: 2024/06/04 19:03:22 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// window and menu size CODAM:
# define WIDTH 3500
# define HEIGHT 2000

# define MENU_WIDTH 700
# define IMG_WIDTH 2800

// window and menu size HOME:
// # define WIDTH 1750
// # define HEIGHT 800

// # define MENU_WIDTH 350
// # define IMG_WIDTH 1400

// # define MENU_WIDTH (WIDTH / 5)
// # define IMG_WIDTH (WIDTH - MENU_WIDTH)

# include <MLX42/MLX42.h>
# include <math.h>
# include <stdbool.h>
# include "lib_liath.h"

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	bool		last_point;
	uint32_t	colour;
}	t_point;

typedef struct s_map_data
{
	mlx_t			*window;
	mlx_image_t		*image;
	mlx_image_t		*menu_image;
	mlx_texture_t	*menu_texture;

	int				height;
	int				width;
	char			*title;
	char			*full_map_buffer;
	char			**map_lines;
	t_point			**points;

	float			scale;
	float			z_scale;
	float			centre_x;
	float			centre_y;
	float			angle;
	int				x_offset;
	int				y_offset;
	bool			is_isometric;

	float			temp_ax;
	float			temp_ay;
	float			temp_bx;
	float			temp_by;
	float			new_ax;
	float			new_ay;
	float			new_bx;
	float			new_by;
}	t_map_data;

uint32_t	get_colour(char *colour);
int32_t		ft_pixel_colour(int32_t r, int32_t g, int32_t b, int32_t a);
int			get_r(int rgba);
int			get_g(int rgba);
int			get_b(int rgba);
int			get_a(int rgba);

void		fill_canvas(t_map_data *map);
void		draw_fdf(t_map_data *map);

float		get_max(float a, float b);
float		get_mod(float a);

void		set_defaults(char *file_path, t_map_data *map);
void		set_position(t_map_data *map);
void		key_is_pressed(void *data);

void		parse_map_lines(t_map_data *map);
void		parse_map_points(t_map_data *map);
char		*validate_map_name(char *file_path);
void		read_map(t_map_data *map, char *file_path);

void		allocate_map_lines(t_map_data *map);
void		allocate_and_copy_line(t_map_data *map, int i, int j, int width);

void		clear_everything(t_map_data *map);
void		ft_free_points_matrix(t_point **points, t_map_data *map);
void		ft_free_matrix(char **lines);
void		ft_free_lines_matrix(char **map_lines, t_map_data *map);
void		ft_exit(char *error_message);

// debugging:
// void		print_map(t_map_data *map);
// void		rose_curve(t_map_data *map);
#endif
