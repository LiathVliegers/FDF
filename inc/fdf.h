
#ifndef FDF_H
# define FDF_H

# include <MLX42/MLX42.h>
# include "lib_liath.h"
// # include <stdbool.h>
// # include <errno.h>

typedef struct s_map_data
{
	int height;
	int width;
	int **z_values;
} t_map_data;

typedef struct s_vector
{
	int x;
	int y;
	int z;
} t_vector;

#endif
