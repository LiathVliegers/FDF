/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:50:19 by livliege          #+#    #+#             */
/*   Updated: 2024/03/07 16:21:56 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	validate_map_name(char *path, t_map_data* map)
{
    // int		i;

	// i = ft_strlen(path) - 1;
	// // TODO: GET MILAN TO BREAK MY MAP VALIDATION (because vincent couldn't muhahaha)
	// if ((i + 1) < 4 || (!((path[i] == 'f') && (path[i - 1] == 'd') && (path[i - 2] == 'f') && (path[i - 3] == '.'))))
	// 	ft_exit(4);
    // if (ft_strrchr(path, '/'))
	// 	path = ft_strrchr(path, '/') + 1;
	// map->title = ft_strjoin("LIATH'S FDF!	map: ", path);

// / -----------------------------------------

	int		i;
	int		j;

	i = 0;
	j = ft_strlen(path) - 1;
	const char *ext = "fdf.";
	while (ext[i])
	{
		if (j == 0 || path[j] != ext[i])
			ft_exit(4);	
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
		ft_exit(2);
	i = 0;
	while (i < map->height)
	{
		map->points[i] = (t_point*)malloc(sizeof(t_point) * map->width);
		if (map->points[i] == NULL)
			ft_exit(2);
		i++;
	}
}

void fill_map(t_point* points_row, char* line, t_map_data* map)
{
	char	**split_line;
	int 	i;
	int 	j;

	split_line = ft_split(line, ' ');
	if (split_line == NULL)
		ft_exit(2);
	i = 0;
	j = 0;

	while (split_line[j] != NULL)
	{
		if (split_line[j][0] != '\n')
			points_row[i].z = ft_atoi(split_line[j]);
		free(split_line[j]);
		i++;
		j++;
	}
	while (split_line[j] == NULL && i < map->width)
	{
		points_row[i].z = 0;
		i++;
	}
	free(split_line);
}

void free_map(t_map_data* map)
{
	int i;
	
	i = 0;
    while (i < map->height) 
	{
        free(map->points[i]);
		i++;
    }
    free(map->points);
	free(map->title);
    free(map);
}
