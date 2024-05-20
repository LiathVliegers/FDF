/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liath <liath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:47:35 by liath             #+#    #+#             */
/*   Updated: 2024/05/20 16:07:34 by liath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_position(t_map_data *map)
{
	map->x_offset = WIDTH / (map->width);
	map->y_offset = HEIGHT / (map->height);
	map->scale = 30.0;
	map->z_scale = 1.0;
	map->angle = 1.0;
	map->is_isometric = 0;
}

void	set_defaults(char *file_path, t_map_data *map)
{
	map->title = validate_map_name(file_path);
	allocate_map_lines(map);
	parse_map_lines(map);
	parse_map_points(map);
	set_position(map);
}
