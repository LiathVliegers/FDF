/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liath <liath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:48:58 by liath             #+#    #+#             */
/*   Updated: 2024/05/20 16:07:38 by liath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	allocate_map_lines(t_map_data *map)
{
	map->map_lines = (char **)malloc(sizeof(char *) * map->height);
	if (map->map_lines == NULL)
		ft_exit(2);
}

void	allocate_and_copy_line(t_map_data *map, int i, int j, int width)
{
	map->map_lines[j] = (char *)malloc(sizeof(char) * (width + 1));
	if (map->map_lines[j] == NULL)
		ft_exit(2);
	ft_strlcpy(map->map_lines[j], map->full_map_buffer + i - width, width + 1);
}
