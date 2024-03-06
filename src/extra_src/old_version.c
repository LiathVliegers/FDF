
#include "../inc/lib_liath.h"
#include "../inc/fdf.h"


int		get_map_columns(int fd)
{
	int 	total_cols;
	char*	row;
	char**	row_elements;

	total_cols = 0;
	row = get_next_line(fd);

	if (row == NULL)
		return (-1);
	
	row_elements = ft_split(row, ' ');

	while (row_elements[total_cols] != NULL)
		total_cols++;

	return (total_cols);
}

// buffersize of 4000 works, smaller gets weird. but im tired and i need to sleep so ill look at it later gvd!
int 	get_map_rows(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int 	total_rows;
	int 	i;

	bytes_read = 1;
	total_rows = 0;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		buffer[bytes_read] = '\0';
		i = 0;
		while (buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
			{
				total_rows++;
			}
			i++;
		}
	}
	return (total_rows + 1);
}

void	print_int_map(int** map, int rows, int cols)
{
	int 			x;
	int 			y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			ft_printf("%d", map[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}

void	ft_load_map(int fd, int total_rows, int total_cols)
{
	char*			line;
	char** 			temp_map;
	int**			map;
	int				row; //x
	int 			col; //y

	row = 0;
	line = NULL;
    map = (int **)malloc(total_rows * sizeof(int *));
    if (map == NULL) 
		return (ft_putstr_fd("ERROR: memory allocation failed\n", STDERR_FILENO));
   
	line = get_next_line(fd);
	if (line == NULL && row == 0)
		return (ft_putstr_fd("ERROR: empty .fdf map file\n", STDERR_FILENO));
	while (line != NULL)
	{
		ft_printf("%s\n", line);
		temp_map = ft_split(line, ' ');
		col = 0;
		map[row] = (int *)malloc(total_cols * sizeof(int));
        if (map[row] == NULL) 
			return (ft_putstr_fd("ERROR: memory allocation failed\n", STDERR_FILENO));

		while (temp_map[col] != NULL)
		{
			map[row][col] = ft_atoi(temp_map[col]);
			free(temp_map[col]);
			col++;
		}
		free(temp_map);
		free(line);
		row++;
		ft_printf("%d\n", fd);

		line = get_next_line(fd);
		ft_printf("TEST2!!!1!\n");
	}

	// print_int_map(map, row, col); 				// TAKE THIS OUT
	return ;
}

int		ft_open_fd(char* file_name)
{
	int		fd;
	char*	path;
	int		total_rows;		// x
	int 	total_cols;		// y
	
	path = ft_strjoin("maps/", file_name);
	
	fd = open(path, O_RDONLY);
	ft_printf("%d\n", fd);
	total_cols = get_map_columns(fd);	// this function closes the fd
	close(fd);
	ft_printf("total cols: %d\n", total_cols);	// TAKE THIS OUT
	fd = open(path, O_RDONLY);
	ft_printf("%d\n", fd);
	total_rows = get_map_rows(fd);		// this function closes the fd
	close(fd);

	ft_printf("total rows: %d\n", total_rows);	// TAKE THIS OUT
	
	fd = open(path, O_RDONLY);
	ft_printf("%d\n", fd);
	free(path);

	if (fd < 2)
		return (ft_putstr_fd("ERROR: can't open fd file.\n", STDERR_FILENO), -1);

	ft_load_map(fd, total_cols, total_rows);

	close(fd);
	return (0);
}

int main(int argc, char** argv)
{

	if(argc != 2)
		return (ft_putstr_fd("ERROR: missing argument, include a valid .fdf file\n", STDERR_FILENO), -1);

	ft_open_fd(argv[1]);

	return (0);
}

// --------------------------------------------------------------------------------------

#include "../inc/lib_liath.h"
#include "../inc/fdf.h"


#define WIDTH 3000
#define HEIGHT 2000

// MY PROGRAM DOES:
// takes a file as argument, opens it and reads the lines, and puts the numbers in an 2d int array.
// opens a window.
// closes the wintow when you press esc.

void ft_hook(void* param)
{
	mlx_t*	mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int main(int argc, char** argv)
{
	mlx_t* 	window;
	// int** 	map;


	if(argc != 2)
	{
		// ft_printf("ERROR: No arguments given, please include a .fdf file from the maps directory as argument\n");
		ft_putstr_fd("ERROR BITCH\n", STDERR_FILENO);
		return (0);
	}

	ft_open_fd(argv[1]);

	// creates a window, with a set width, height, name, and bool for if it's resizable
	window = mlx_init(WIDTH, HEIGHT, "LIATH'S FDF!", false);

	mlx_loop_hook(window, ft_hook, window);
	mlx_loop(window);
	mlx_terminate(window);

	return (0);
}



// --------------------------------------------------------------------------------------



#include "../inc/lib_liath.h"
#include "../inc/fdf.h"

#define MAX_ROWS 20
#define MAX_COLS 20

void	ft_load_map(int fd)
{
	char*			line;
	char** 			temp_map;
	int				map[MAX_ROWS][MAX_COLS];
	int				row;	// x
	int 			col;	// y
	int 			x;		// printing purposes only TAKE THIS OUT
	int 			y;		// printing purposes only TAKE THIS OUT
	
	row = 0;
	line = get_next_line(fd);
	if (line == NULL && row == 0)
	{
		ft_printf("ERROR: empty .fdf map file\n");
		return ;
	}
	while (line != NULL)
	{
		// ft_printf("%s", line);
		temp_map = ft_split(line, ' ');
		col = 0;
		while (temp_map[col] != NULL)
		{
			map[row][col] = ft_atoi(temp_map[col]);
			free(temp_map[col]);
			col++;
		}
		free(temp_map);
		free(line);
		row++;
		line = get_next_line(fd);
	}
	
	// print 2d int array TAKE THIS OUT
	x = 0;
	while (x < row)
	{
		y = 0;
		while (y < col)
		{
			ft_printf("%d", map[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
	return ;
}

int		ft_open_fd(char* file_name)
{
	int				fd;
	char*			path;
	
	path = ft_strjoin("maps/", file_name);
	ft_printf("path to map: %s\n", path);
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 2)
	{
		ft_printf("ERROR: can not open fd file. fd = %d\n", fd);
		//stop program
		return (0);
	}
	ft_printf("fd = %d\n", fd);
	ft_load_map(fd);
	close(fd);
	return (0);
}