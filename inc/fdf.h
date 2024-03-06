
#ifndef FDF_H
# define FDF_H

// window size:
#define WIDTH 3000
#define HEIGHT 2000

# include <MLX42/MLX42.h>
# include "lib_liath.h"
// # include <stdbool.h>
// # include <errno.h>

typedef struct s_map_data
{
	char	*title;
	int		height;
	int		width;
	int		**z_values;
} t_map_data;

typedef struct s_point
{
	int	z;
	int	colour;
} t_point;

// alleen de functie die in een andere file staat moet hier komen, 
// de rest moeten static functions zijn, want die kunnen niet aangeroepen worden vanuit een andere file
// = kleinere kans op naam-clashing :D
void print_map(t_map_data* map);
void free_map(t_map_data* map);
void allocate_memory_map(t_map_data* map);
int get_map_height(char* file_path);
int get_map_width(char* file_path);
void fill_map(int* z_value, char* line, t_map_data* map);
void parse_map_file(char* file_path, t_map_data* map);
void	validate_map_name(char *path, t_map_data* map);
void	ft_exit(int error_code);






#endif
