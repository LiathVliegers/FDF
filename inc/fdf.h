
#ifndef FDF_H
# define FDF_H

// window size:
#define WIDTH 3000
#define HEIGHT 2000
#define OFFSET 200
#define IMG_WIDTH WIDTH - (OFFSET * 2)
#define IMG_HEIGHT HEIGHT - (OFFSET * 2)


# include <MLX42/MLX42.h>
# include <math.h>
# include "lib_liath.h"
// # include <stdbool.h>
// # include <errno.h>

typedef struct s_point
{
	int			x;
	int 		y;
	int			z;
	uint32_t	colour;
} t_point;

typedef struct s_map_data
{
	int			height;
	int			width;
	char		*title;
	t_point		**points;

	mlx_t		*window;
	mlx_image_t	*image;
} t_map_data;

// alleen de functie die in een andere file staat moet hier komen, 
// de rest moeten static functions zijn, want die kunnen niet aangeroepen worden vanuit een andere file
// = kleinere kans op naam-clashing :D
void	free_map(t_map_data* map);
void	allocate_memory_map(t_map_data* map);
int		get_map_height(char* file_path);
int		get_map_width(char* file_path);
void	fill_map(t_point* points_row, char* line);
void	ft_free_matrix(char **matrix);
void	parse_map_file(char* file_path, t_map_data* map);
void	validate_map_name(char *path, t_map_data* map);
void	ft_exit(int error_code);
uint32_t get_colour(char* line);
void bresenham_line(float x, float y, float x1, float y1, t_map_data *map);
void	fill_points_x_and_y(t_map_data *map);

// TAKE THESE OUT:
int32_t ft_pixel_colour(int32_t r, int32_t g, int32_t b, int32_t a);
void	print_map(t_map_data* map);
void	rose_curve(t_map_data *map);
void 	make_grid(t_map_data* map);
void	fill_image(t_map_data *map);


#endif
