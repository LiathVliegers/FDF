/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:46:53 by livliege          #+#    #+#             */
/*   Updated: 2024/03/06 13:42:53 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
PLAN van aanpak:

1.	open file with the correct path 
2.	parse the map:
	- get height
	- get width
	- malloc that shit and free when we're done
	- atoi the string to ints and put in int** array (or struct array)
	- make array of structs with x, y, z values of the points

	how?:
	get next line = first line
	we now have the y = 0, we can use ft_split to get the amount of x elements. 
	We check the string at the x locations and use atoi to get the int value (z)
	every time we check one index lower, we increment x
	for every index in an array of structs of type Point we document the y, the x, and the z
	then we get out of the function and we parsed the first line succesfully
	we then increment y, and keep doing this untill get_next_line returns NULL
	now we have an array of structs Point that stores all values of x, y and z.

	when we draw, we check the value of x and y for the position, and the value of z for the height
	
	
3.	- open a window with the name of the file
4.	- create an image with the grid and display this in the window
5.	- 
6.	
7.	
8.	
9.	
10.	
11.	
12.	
13.	
	not ideal to read the fd more than once
*/

#include "../inc/fdf.h"

void print_map(t_map_data* map)
{
	int x;
	int y;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf("%d ", map->z_values[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

int get_height(char* file_path)
{
	int		fd;
	int		height;
	char	*line;
	
	height = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO), -1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		return (ft_putstr_fd("ERROR: empty map\n", STDERR_FILENO), 0);
	}
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	ft_printf("height: %d\n", height);
	return (height);
}
int get_width(char* file_path)
{
	int		i;
	int		fd;
	int		width;
	char	*line;
	char	**split_line;
	
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO), -1);
	line = get_next_line(fd);
	if (line == NULL)
	{
		return (ft_putstr_fd("ERROR: empty map\n", STDERR_FILENO), 0);
	}
	split_line = ft_split(line, ' ');
	i = 0;
	width = 0;
	while (split_line[i] != NULL && split_line[i][0] != '\n')
	{
		width++;
		free(split_line[i]);
		i++;
	}
	// if (split_line[i][0] == '\n')
	// // {
	// // 	free(split_line[i]);
	// // }
	free(split_line);
	free(line);
	ft_printf("width: %d\n", width);
	return (width);
	// CHECK IF EVERY LINE IS THE SAME, IF NOT, UPDATE THE NEW WIDTH!
}

void allocate_memory(t_map_data* map)
{
	int		i;

	map->z_values = (int **)malloc(sizeof(int*) * map->height);
	if (map->z_values == NULL)
		return (ft_putstr_fd("ERROR: Memory allocation failed\n", STDERR_FILENO)); // exit?
	i = 0;
	while (i < map->height)
	{
		map->z_values[i] = (int*)malloc(sizeof(int) * map->width);
		if (map->z_values[i] == NULL)
			return (ft_putstr_fd("ERROR: Memory allocation failed\n", STDERR_FILENO)); // exit?
		i++;
	}
}

void fill_map(int* z_value, char* line)
{
	char	**split_line;
	int 	i;

	split_line = ft_split(line, ' ');
	if (split_line == NULL)
		return (ft_putstr_fd("ERROR: Memory allocation failed\n", STDERR_FILENO)); // exit?
	i = 0;
	while (split_line[i] != NULL  && split_line[i][0] != '\n')
	{
		z_value[i] = ft_atoi(split_line[i]);
		free(split_line[i]);
		i++;
	}
	// if (split_line[i][0] == '\n')
	// {
	// 	free(split_line[i]);
	// }
	free(split_line);
}


void parse_file(char* file_path, t_map_data* map)
{
	int		i;
	int		fd;
	char	*line;
	
	line = NULL;
	map->height = get_height(file_path);
	if (map->height <= 0)
		exit(1);
	map->width = get_width(file_path);
	if (map->width <= 0)
		exit(1);
	allocate_memory(map);
	fd = open(file_path, O_RDONLY);

	if (fd < 0)
		return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO));
	i = 0;
	line = get_next_line(fd);
	while (line != NULL && i < map->height)
	{
		fill_map(map->z_values[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	// TODO: CLOSE ALL FD'S IN A BETTER WAY
	close(3);
	close(4);
	close(fd);
}

int main (int argc, char** argv)
{
	t_map_data* map;
	int i;

	if (argc != 2)
		return (ft_putstr_fd("ERROR: invalid fd\n", STDERR_FILENO), 1);
	map = (t_map_data*)malloc(sizeof(t_map_data));
	if (map == NULL)
		return (ft_putstr_fd("ERROR: Memory allocation failed\n", STDERR_FILENO), 1);
	parse_file(argv[1], map);

	print_map(map);
	
	// Free allocated memory
	i = 0;
    while (i < map->height) 
	{
        free(map->z_values[i]);
		i++;
    }
    free(map->z_values);
    free(map);
	return (0);
}

