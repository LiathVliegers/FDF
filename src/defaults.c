/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:47:35 by liath             #+#    #+#             */
/*   Updated: 2024/06/03 15:46:30 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_position(t_map_data *map)
{
	map->x_offset = 800;
	map->y_offset = 300;
	if (map->height >= 400)
		map->scale = 1.5;
	if (map->height >= 300 && map->height < 400)
		map->scale = 2.5;
	if (map->height >= 200 && map->height < 300)
		map->scale = 4.0;
	if (map->height >= 100 && map->height < 200)
		map->scale = 8.0;
	if (map->height >= 10 && map->height < 100)
		map->scale = 30.0;
	else if (map->height < 10)
		map->scale = 60.0;
	map->z_scale = 1.0;
	map->angle = 0.60;
	map->is_isometric = true;
}

void	set_defaults(char *file_path, t_map_data *map)
{
	map->title = validate_map_name(file_path);
	allocate_map_lines(map);
	parse_map_lines(map);
	parse_map_points(map);
	set_position(map);
}
