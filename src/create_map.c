/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:50:19 by livliege          #+#    #+#             */
/*   Updated: 2024/03/06 20:49:43 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	validate_map_name(char *path, t_map_data* map)
{
    int		i;

	i = ft_strlen(path) - 1;
	// TODO: GET MILAN TO BREAK MY MAP VALIDATION (because vincent couldn't muhahaha)
	if ((i + 1) < 4 || (!((path[i] == 'f') && (path[i - 1] == 'd') && (path[i - 2] == 'f') && (path[i - 3] == '.'))))
		ft_exit(4);
    while (i >= 0 && path[i] != '/')
        i--;
    i++;
	map->title = ft_strjoin("LIATH'S FDF!	map: ", path + i);
}

void allocate_memory_map(t_map_data* map)
{
	int		i;

	map->z_values = (int **)malloc(sizeof(int*) * map->height);
	if (map->z_values == NULL)
		ft_exit(2);
	i = 0;
	while (i < map->height)
	{
		map->z_values[i] = (int*)malloc(sizeof(int) * map->width);
		if (map->z_values[i] == NULL)
			ft_exit(2);
		i++;
	}
}

void fill_map(int* z_value, char* line, t_map_data* map)
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
			z_value[i] = ft_atoi(split_line[j]);
		free(split_line[j]);
		i++;
		j++;
	}
	while (split_line[j] == NULL && i < map->width)
	{
		z_value[i] = 0;
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
        free(map->z_values[i]);
		i++;
    }
    free(map->z_values);
	free(map->title);
    free(map);
}
