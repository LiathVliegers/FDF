/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:50:19 by livliege          #+#    #+#             */
/*   Updated: 2024/03/13 19:20:57 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	validate_map_name(char *path, t_map_data* map)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(path) - 1;
	const char *ext = "fdf.";
	while (ext[i])
	{
		if (j == 0 || path[j] != ext[i])
			ft_exit(4);	// 4: ERROR: Invalid map file
		j--;
		i++;
	}
	if (ft_strrchr(path, '/'))
		path = ft_strrchr(path, '/') + 1;
	map->title = ft_strjoin("LIATH'S FDF!	map: ", path);
}

void allocate_memory_map(t_map_data* map)
{
	int		i;

	map->points = (t_point **)malloc(sizeof(t_point*) * map->height);
	if (map->points == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed
	i = 0;
	while (i < map->height)
	{
		map->points[i] = (t_point*)malloc(sizeof(t_point) * map->width);
		if (map->points[i] == NULL)
			ft_exit(2);	// 2: ERROR: Memory allocation failed
		i++;
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
		points_row[i].z = ft_atoi(split_line[j]);
		i++;
		j++;
	}
	ft_free_matrix(split_line);
}

