/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapversieFUCKINGSPLITFUCK.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:50:29 by livliege          #+#    #+#             */
/*   Updated: 2024/04/10 16:25:54 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

char	*validate_map_name(char *file_path)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(file_path) - 1;
	const char *ext = "fdf.";
	while (ext[i])
	{
		if (j == 0 || file_path[j] != ext[i])
			ft_exit(4);	// 4: ERROR: Invalid map file
		j--;
		i++;
	}
	if (ft_strrchr(file_path, '/'))
		file_path = ft_strrchr(file_path, '/') + 1;
	ft_printf("%s function finished\n", __FUNCTION__ );
	return(ft_strjoin("LIATH'S FDF! map: ", file_path));

}

void	fill_point_values(t_point* points, char** split_line, int y)
{
	int		i;
	char*	comma;
	
	i = 0;
	while (split_line[i] != NULL)
	{
		points[i].x = i;
		points[i].y = y;
		points[i].last_point = 0;
		points[i].z = ft_atoi(split_line[i]);
		comma = ft_strchr(split_line[i], ',');
		if (comma)
			points[i].colour = get_colour(comma + 1);
		else
			points[i].colour = 0xFFFFFFFF;
		i++;
	}
	points[i - 1].last_point = 1;
}
// HERE IS THE PROBLEM!
void	parse_map_points(t_map_data* map)
{
	int i;
	int width;
	char** split_line;
	
	map->points = (t_point**)malloc(sizeof (t_point*) * map->height);
	if (map->points == NULL)
		ft_exit(2);
	i = 0;
	while (i < map->height)
	{
		width = 0;
		split_line = ft_split(map->map_lines[i], ' ');
		
		// ft_printf("%d split done. \n", i);

		map->points[i] = (t_point*)malloc(sizeof (t_point) * map->width);
		if (map->points == NULL)
			ft_exit(2);
		fill_point_values(map->points[i], split_line, i);
		
		ft_free_matrix(split_line);
		i++;
	}
	ft_printf("%s function finished\n", __FUNCTION__ );
}

void get_map_width(t_map_data* map)
{
	int i;
	int width;

	i = 0;
	while (i < map->height)
	{
		width = ft_wordcount(map->map_lines[i], ' ');
		if (map->width == 0)
			map->width = width;
		if (width > map->width)
			ft_exit(6);
		i++;
	}
	ft_printf("%s function finished\n", __FUNCTION__ );
}

void set_defaults(char *file_path, t_map_data* map)
{
	map->title = validate_map_name(file_path);
	
	get_map_width(map);
	parse_map_points(map);		// here we get x, y, z and colour values
	
	map->x_offset = WIDTH / 3;
	map->y_offset = HEIGHT / 3;
	map->scale = 50.0 ;
	map->z_scale = 1.0;
	map->angle = 1.0;
	map->is_isometric = 1;
	ft_printf("%s function finished\n", __FUNCTION__ );

}


// void allocate_map_lines(t_map_data* map) 
// {
// 	map->map_lines = (char**)malloc(sizeof(char*) * map->height);
// 	if (map->map_lines == NULL)
// 		ft_exit(2);
// }

void allocate_map_lines(t_map_data* map) 
{
	map->map_lines = (char**)malloc(sizeof(char*) * 501);
	if (map->map_lines == NULL)
		ft_exit(2);
}

// void allocate_map_per_line(t_map_data* map, int i, int width) 
// {
// 	map->map_lines[i] = (char*)malloc(sizeof(char) * (width + 1));
// 	if (map->map_lines[i] == NULL)
// 		ft_exit(2);
// }

void read_map(t_map_data *map, char* file_path)
{
	int fd;
	int i;
	
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_exit(3);
	allocate_map_lines(map);
	i = 0;
	map->map_lines[i] = get_next_line(fd);
	if (map->map_lines[i] == NULL)
	{
		ft_exit(5);
		close(fd);
	}
	while (map->map_lines[i] != NULL)
	{
		i++;
		map->map_lines[i] = get_next_line(fd);
	}
	close(fd);
	map->height = i;
	set_defaults(file_path, map);
}




// laatste wat ik heb gedaan op codam:

#include "../inc/fdf.h"

char	*validate_map_name(char *file_path)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(file_path) - 1;
	const char *ext = "fdf.";
	while (ext[i])
	{
		if (j == 0 || file_path[j] != ext[i])
			ft_exit(4);	// 4: ERROR: Invalid map file
		j--;
		i++;
	}
	if (ft_strrchr(file_path, '/'))
		file_path = ft_strrchr(file_path, '/') + 1;
	return(ft_strjoin("LIATH'S FDF! map: ", file_path));
}

void	fill_point_values(t_point* points, char** split_line, int y)
{
	int i;
	char *comma;
	
	i = 0;
	while (split_line[i] != NULL)
	{
		points[i].x = i;
		points[i].y = y;
		points[i].last_point = 0;
		points[i].z = ft_atoi(split_line[i]);
		comma = ft_strchr(split_line[i], ',');
		if (comma)
			points[i].colour = get_colour(comma + 1);
		else
			points[i].colour = 0xFFFFFFFF;
		i++;
	}
	points[i - 1].last_point = 1;
}

// HERE IS THE PROBLEM!
void	parse_map_points(t_map_data* map)
{
	int i;
	int width;
	char** split_line;

	map->points = (t_point**)malloc(sizeof (t_point*) * map->height);
	if (map->points == NULL)
		ft_exit(2);
	i = 0;
	while (i < map->height)
	{
		width = 0;
		split_line = ft_split(map->map_lines[i], ' ');
		while(split_line[width] != NULL)
			width++;
		if (map->width == 0)
			map->width = width;
		if (width > map->width)
			ft_exit(6);
		map->points[i] = (t_point*)malloc(sizeof (t_point) * width);
		if (map->points == NULL)
			ft_exit(2);
		fill_point_values(map->points[i], split_line, i);
		ft_free_matrix(split_line);
		i++;
	}
}

void allocate_map_lines(t_map_data* map) 
{
	map->map_lines = (char**)malloc(sizeof(char*) * map->height);
	if (map->map_lines == NULL)
		ft_exit(2);
}

void allocate_map_per_line(t_map_data* map, int i, int width) 
{
	map->map_lines[i] = (char*)malloc(sizeof(char) * (width + 1));
	if (map->map_lines[i] == NULL)
		ft_exit(2);
}


void set_defaults(char *file_path, t_map_data* map)
{
	map->title = validate_map_name(file_path);
	// parse_map_lines(map); 		// here we get the map width and height
	parse_map_points(map);		// here we get x, y, z and colour values
	map->x_offset = WIDTH / 3;
	map->y_offset = HEIGHT / 3;
	map->scale = 50.0;
	map->z_scale = 1.0;
	map->angle = 1.0;
	map->is_isometric = 1;
}

void read_map_lines(t_map_data *map, char* file_path)
{
	int fd;
	int i;
	
	allocate_map_lines(map);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_exit(3);
	i = 0;
	map->map_lines[i] = get_next_line(fd);
	if (map->map_lines[i] == NULL)
	{
		ft_exit(5);
		close(fd);
	}
	while (map->map_lines[i] != NULL)
	{
		i++;
		map->map_lines[i] = get_next_line(fd);
	}
	close(fd);
	// map->height = i;
	set_defaults(file_path, map);
}

// void get_map_height(t_map_data *map, char* file_path)
// {
// 	int i;

// 	i = 0;
	
// 	while (map->full_map_buffer[i] != '\0')
// 	{
// 		if (map->full_map_buffer[i] == '\n')
// 			map->height++;
// 		i++;
// 	}
// 	read_map_lines(map,file_path);
// }

void read_map(t_map_data *map, char* file_path)
{
	char buffer[100001];
	int bytes_read;
	int fd;
	int i;
	// char *temp;

	i = 0;
	bytes_read = 1;
	ft_bzero(buffer, 100001);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_exit(3);
	bytes_read = read(fd, buffer, 100000);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			map->height++;
		i++;
	}
	
	// temp = ft_strjoin("", "");
	// while (bytes_read > 0)
	// {
	// 	ft_bzero(buffer, 100001);
	// 	bytes_read = read(fd, buffer, 100000);
	// 	if (bytes_read < 0)
	// 		ft_exit(5);
	// 	map->full_map_buffer = ft_strjoin(temp, buffer);
	// 	free(temp);
	// 	temp = map->full_map_buffer;
	// }
	// free(temp);
	close(fd);
	read_map_lines(map,file_path);

	// get_map_height(map, file_path);
}


// void parse_map_lines(t_map_data* map) 
// {
// 	int i;
// 	int j;
// 	int width;
	
// 	i = 0;
// 	j = 0;
// 	width = 0;
// 	while (map->full_map_buffer[i] != '\0')
// 	{
// 		if (map->full_map_buffer[i] == '\n')
// 		{
// 			allocate_map_per_line(map, j, width);
// 			ft_strlcpy(map->map_lines[j], map->full_map_buffer + i - width, width + 1);
// 			width = 0;
// 			j++;
// 		} 
// 		else
// 			width++;
// 		i++;
// 	}
// 	if (width > 0)
// 	{
// 		allocate_map_per_line(map, j, width);
// 		ft_strlcpy(map->map_lines[j], map->full_map_buffer + i - width, width + 1);
// 	}
// }


// void read_map(t_map_data *map, char* file_path)
// {
// 	int fd;
// 	char *line;
// 	char *temp;
	
// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 0)
// 		ft_exit(3);
// 	line = get_next_line(fd);
// 	if (line == NULL)
// 	{
// 		ft_exit(5);
// 		close(fd);
// 	}
// 	temp = ft_strjoin("", "");
// 	while (line != NULL)
// 	{
// 		map->height++;
// 		map->full_map_buffer = ft_strjoin(temp, line);
// 		free(temp);
// 		free(line);
// 		temp = map->full_map_buffer;
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	set_defaults(file_path, map);
// }
