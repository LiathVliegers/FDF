
#include "../inc/lib_liath.h"
#include "../inc/fdf.h"


int		get_map_columns(int fd)
{
	int total_cols = 30;

	close(fd);

	return (total_cols);
}

// buffersize of 4000 works, smaller gets weird. but im tired and i need to sleep so ill look at it later gvd!
int 	get_map_rows(int fd)
{
	char	buffer[1000 + 1];
	int		bytes_read;
	int 	total_rows;
	int 	i;

	bytes_read = 1;

	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 1000);
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
	close(fd);
	return (total_rows + 1);
}

void	print_int_map(int** map, int row, int col)
{
	int 			x;
	int 			y;

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
}

void	ft_load_map(int fd, int total_rows, int total_cols)
{
	char*			line;
	char** 			temp_map;
	int**			map;
	int				row; //x
	int 			col; //y

	row = 0;
    map = (int **)malloc(total_rows * sizeof(int *));
    if (map == NULL) 
	{
        ft_printf("ERROR: memory allocation failed\n");
        return ;
    }
	line = get_next_line(fd);
	if (line == NULL && row == 0)
	{
		ft_printf("ERROR: empty .fdf map file\n");
		return ;
	}
	while (line != NULL)
	{
		temp_map = ft_split(line, ' ');
		col = 0;
		map[row] = (int *)malloc(total_cols * sizeof(int));
        if (map[row] == NULL) 
		{
            ft_printf("ERROR: memory allocation failed\n");
            return ;
        }
		while (temp_map[col] != NULL)
		{
			map[row][col] = ft_atoi(temp_map[col]);
			col++;
		}
		free(temp_map);
		free(line);
		row++;
		line = get_next_line(fd);
	}

	print_int_map(map, row, col); 				// TAKE THIS OUT
	return ;
}

int		ft_open_fd(char* file_name)
{
	int		fd;
	char*	path;
	int		total_rows;		// x
	int 	total_cols;		// y
	
	path = ft_strjoin("maps/", file_name);
	ft_printf("path to map: %s\n", path);		// TAKE THIS OUT
	
	fd = open(path, O_RDONLY);
	total_cols = get_map_columns(fd);	// this function closes the fd
	ft_printf("total cols: %d\n", total_cols);	// TAKE THIS OUT
	
	fd = open(path, O_RDONLY);
	total_rows = get_map_rows(fd);		// this function closes the fd
	ft_printf("total rows: %d\n", total_rows);	// TAKE THIS OUT
	
	fd = open(path, O_RDONLY);
	free(path);
	if (fd < 2)
	{
		ft_printf("ERROR: can not open fd file. fd = %d\n", fd);
		return (0);
	}
	ft_printf("fd = %d\n", fd);				// TAKE THIS OUT
	

	ft_load_map(fd, total_cols, total_rows);
	close(fd);
	return (0);
}

int main(int argc, char** argv)
{

	if(argc != 2)
	{
		ft_printf("ERROR: No arguments given, please include a .fdf file from the maps directory as argument\n");
		return (0);
	}

	ft_open_fd(argv[1]);

	return (0);
}