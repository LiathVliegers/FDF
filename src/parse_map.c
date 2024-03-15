/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:42 by livliege          #+#    #+#             */
/*   Updated: 2024/03/15 16:16:13 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


void parse_map_file(char* file_path, t_map_data* map)
{
	int		i;
	int		fd;
	char	*line;
	
	validate_map_name(file_path, map);
	map->height = get_map_height(file_path);
	map->width = get_map_width(file_path);
	allocate_memory_map(map);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_exit(3);
	i = 0;
	line = get_next_line(fd);
	// protect get_next_line
	while (line != NULL && i < map->height)
	{
		fill_map(map->points[i], line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	fill_points_x_and_y(map);
	free(line);
	close(fd);
}


void	fill_points_x_and_y(t_map_data *map)
{
	int x;
	int y;
	
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->points[y][x].x = x;
			map->points[y][x].y = y;
			map->points[y][x].last_point = 0;
			x++;
		}
		y++;
		map->points[y - 1][x - 1].last_point = 1;
	}
	// checks if the map is more high or more broad (yesh yesh my english very good), and sets the scale accordingly. I'll change this later
	if (map->height > map->width)
		map->scale = (HEIGHT / map->height);
	else if (map->height <= map->width)
		map->scale = (HEIGHT / map->width);
	map->x_offset = 0;
	map->y_offset = 0;
}
