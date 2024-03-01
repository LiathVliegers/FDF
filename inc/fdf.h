
#ifndef FDF_H
# define FDF_H

# include <stdbool.h>
# include <MLX42/MLX42.h>

void	ft_load_map(int fd, int total_rows, int total_cols);
// void	ft_load_map(int fd);
int		ft_open_fd(char* file_name);



// extra functions in the extra.c file:
void	print_int_map(int** map, int row, int col);

#endif
