/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapversieFUCKINGSPLITFUCK.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:50:29 by livliege          #+#    #+#             */
/*   Updated: 2024/04/09 16:09:29 by livliege         ###   ########.fr       */
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

