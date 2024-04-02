/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:42 by livliege          #+#    #+#             */
/*   Updated: 2024/03/21 15:14:29 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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
			map->points[y][x].x = (float)x;
			map->points[y][x].y = (float)y;
			map->points[y][x].last_point = 0;
			x++;
		}
		y++;
		map->points[y - 1][x - 1].last_point = 1;
	}
}

void fill_map(t_point* points_row, char* line)
{
	char	**split_line;
	int 	i;
	int 	j;

	split_line = ft_split(line, ' ');
	if (split_line == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed
	i = 0;
	j = 0;
	while (split_line[j] != NULL)
	{
		if (ft_strchr(split_line[j], ','))
			points_row[i].colour = get_colour(split_line[j]);
		else if (!(ft_strchr(split_line[j], ',')))
			points_row[i].colour = 0xFFFFFFFF; // white?
			// points_row[i].colour = 255; // white?
		points_row[i].z = (float)ft_atoi(split_line[j]);
		i++;
		j++;
	}
	ft_free_matrix(split_line);
}

void set_defaults(char* file_path, t_map_data *map)
{
	validate_map_name(file_path, map);
	map->height = get_map_height(file_path);
	map->width = get_map_width(file_path);
	map->x_offset = WIDTH / 3;
	map->y_offset = HEIGHT / 3;
	map->scale = 50.0;
	map->z_scale = 1.0;
	map->angle = 1.0;
}

void parse_map_file(char* file_path, t_map_data* map)
{
	int		i;
	int		fd;
	char	*line;
	
	set_defaults(file_path, map);
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



