/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:17:15 by livliege          #+#    #+#             */
/*   Updated: 2024/06/03 18:34:18 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	parallel_calculation(t_point *a, t_point *b, t_map_data *map)
{
	float	angle;

	angle = map->angle;
	map->temp_ax = a->x - map->centre_x;
	map->temp_ay = a->y - map->centre_y;
	map->temp_bx = b->x - map->centre_x;
	map->temp_by = b->y - map->centre_y;
	map->new_ax = map->temp_ax * cos(angle) - map->temp_ay * sin(angle);
	map->new_ay = map->temp_ax * sin(angle) + map->temp_ay * cos(angle);
	map->new_bx = map->temp_bx * cos(angle) - map->temp_by * sin(angle);
	map->new_by = map->temp_bx * sin(angle) + map->temp_by * cos(angle);
	a->x = map->new_ax + map->centre_x;
	a->y = map->new_ay + map->centre_y;
	b->x = map->new_bx + map->centre_x;
	b->y = map->new_by + map->centre_y;
}

void	isometric_calculation(t_point *a, t_point *b, t_map_data *map)
{
	map->temp_ax = a->x - map->centre_x;
	map->temp_ay = a->y - map->centre_y;
	map->temp_bx = b->x - map->centre_x;
	map->temp_by = b->y - map->centre_y;
	a->x = (map->temp_ax - map->temp_ay) * cos(map->angle);
	a->y = (map->temp_ax + map->temp_ay) * sin(map->angle) - a->z;
	b->x = (map->temp_bx - map->temp_by) * cos(map->angle);
	b->y = (map->temp_bx + map->temp_by) * sin(map->angle) - b->z;
	a->x += map->centre_x;
	a->y += map->centre_y;
	b->x += map->centre_x;
	b->y += map->centre_y;
}

void	init_point_values(t_point *a, t_point *b, t_map_data *map)
{
	map->centre_x = (map->width - 1) * map->scale / 2.0;
	map->centre_y = (map->height - 1) * map->scale / 2.0;
	a->x *= map->scale;
	a->y *= map->scale;
	b->x *= map->scale;
	b->y *= map->scale;
	a->z *= map->z_scale;
	b->z *= map->z_scale;
	if (map->is_isometric == true)
		isometric_calculation(a, b, map);
	if (map->is_isometric == false)
		parallel_calculation(a, b, map);
	a->x += map->x_offset;
	a->y += map->y_offset;
	b->x += map->x_offset;
	b->y += map->y_offset;
}

void	bresenham_line(t_point a, t_point b, t_map_data *map)
{
	float	step_x;
	float	step_y;
	float	max;

	init_point_values(&a, &b, map);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = get_max(get_mod(step_x), get_mod(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x >= 0 && a.y >= 0 && a.x < IMG_WIDTH && a.y < HEIGHT)
			mlx_put_pixel(map->image, a.x, a.y, a.colour);
		a.x += step_x;
		a.y += step_y;
	}
}

void	draw_fdf(t_map_data *map)
{
	int		y;
	int		x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((y + 1) < map->height)
				bresenham_line(map->points[y][x], map->points[y + 1][x], map);
			if (map->points[y][x].last_point == false)
				bresenham_line(map->points[y][x], map->points[y][x + 1], map);
			if (map->points[y][x].last_point == true)
				break ;
			x++;
		}
		y++;
	}
}
