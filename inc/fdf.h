
#ifndef FDF_H
# define FDF_H

// window size:
#define WIDTH 3500
#define HEIGHT 2000

# include <MLX42/MLX42.h>
# include <math.h>
# include "lib_liath.h"
// # include <stdbool.h>
// # include <errno.h>

typedef struct s_point
{
	float		x;
	float 		y;
	float		z;
	int			last_point;
	uint32_t	colour;
} t_point;

typedef struct s_map_data
{
	mlx_t		*window;
	mlx_image_t	*image;
	mlx_image_t		*menu_image;
	mlx_texture_t	*menu_texture;

	int			height;
	int			width;
	char		*title;
	char		*full_map_buffer;
	char		**map_lines;
	t_point		**points;

	float 		scale;
	float		z_scale;
	float 		angle;
	int			x_offset;
	int			y_offset;
	int			is_isometric;
} t_map_data;

// alleen de functie die in een andere file staat moet hier komen, 
// de rest moeten static functions zijn, want die kunnen niet aangeroepen worden vanuit een andere file
// = kleinere kans op naam-clashing :D

void		read_map(t_map_data *map, char* file_path);
void		ft_exit(int error_code);
void		clear_everything(t_map_data *map);
void		ft_free_matrix(char **lines);
uint32_t	get_colour(char* colour);
void		key_is_pressed(void *data);
void		draw_FDF(t_map_data *map);

// debugging:
void		print_map(t_map_data* map);
void		rose_curve(t_map_data *map);

#endif
