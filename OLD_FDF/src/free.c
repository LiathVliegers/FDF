/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:02:24 by livliege          #+#    #+#             */
/*   Updated: 2024/03/13 18:02:42 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

void	ft_free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}