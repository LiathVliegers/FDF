/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:50:19 by livliege          #+#    #+#             */
/*   Updated: 2024/03/06 18:50:47 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

void allocate_memory_map(t_map_data* map)
{
	int		i;

	map->z_values = (int **)malloc(sizeof(int*) * map->height);
	if (map->z_values == NULL)
		return (ft_putstr_fd("ERROR: Memory allocation failed\n", STDERR_FILENO));
	i = 0;
	while (i < map->height)
	{
		map->z_values[i] = (int*)malloc(sizeof(int) * map->width);
		if (map->z_values[i] == NULL)
			return (ft_putstr_fd("ERROR: Memory allocation failed\n", STDERR_FILENO));
		i++;
	}
}