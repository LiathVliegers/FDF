/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:50:29 by livliege          #+#    #+#             */
/*   Updated: 2024/05/14 17:47:19 by livliege         ###   ########.fr       */
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
			ft_exit(4);
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

void allocate_and_copy_line(t_map_data* map, int i, int j, int width) 
{
	map->map_lines[j] = (char*)malloc(sizeof(char) * (width + 1));
	if (map->map_lines[j] == NULL)
		ft_exit(2);
	ft_strlcpy(map->map_lines[j], map->full_map_buffer + i - width, width + 1);
}

void parse_map_lines(t_map_data* map) 
{
	int i;
	int j;
	int width;
	
	i = 0;
	j = 0;
	width = 0;
	while (map->full_map_buffer[i] != '\0')
	{
		if (map->full_map_buffer[i] == '\n')
		{
			if (map->full_map_buffer[i + 1] == '\n')
				ft_exit(4);
			allocate_and_copy_line(map, i, j, width);
			width = 0;
			j++;
		} 
		else
			width++;
		i++;
	}
	if (width > 0)
		allocate_and_copy_line(map, i, j, width);
}

void set_position(t_map_data* map)
{
	map->x_offset = WIDTH / (map->width);
	map->y_offset = HEIGHT / (map->height);
	// map->x_offset = 20;
	// map->y_offset = 200;
	map->scale = 50.0;
// this one is good for the julia! but i need to adjust it for the smaller maps.
	// map->scale = map->width / 100;
	map->z_scale = 1.0;
	map->angle = 1.0;
	map->is_isometric = 0;
}

void set_defaults(char *file_path, t_map_data* map)
{
	map->title = validate_map_name(file_path);
	allocate_map_lines(map);
	parse_map_lines(map);
	parse_map_points(map);
	set_position(map);
}

void read_map(t_map_data *map, char* file_path)
{
	int fd;
	char *line;
	char *temp;
	
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_exit(3);
	line = get_next_line(fd);
	if (line == NULL)
	{
		ft_exit(5);
		close(fd);
	}
	temp = ft_strjoin("", "");
	while (line != NULL)
	{
		map->height++;
		map->full_map_buffer = ft_strjoin(temp, line);
		free(temp);
		free(line);
		temp = map->full_map_buffer;
		line = get_next_line(fd);
	}
	close(fd);
	set_defaults(file_path, map);
}
