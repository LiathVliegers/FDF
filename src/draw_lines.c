/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:27:43 by livliege          #+#    #+#             */
/*   Updated: 2024/03/19 16:22:36 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define MAX(a, b)(a > b ? a : b)
#define MOD(a)(a < 0 ? -a : a)

void bresenham_line(float x, float y, float x1, float y1, t_map_data *map, uint32_t colour)
{
	float x_step;
	float y_step;
	int max;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	
	while((int)(x - x1) || (int)(y - y1))
	{
		if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
			mlx_put_pixel(map->image, x, y, colour);
		x += x_step;
		y += y_step;
	}
}


void	draw_FDF(t_map_data *map)
{
	int x;
	int y;

	// declare point a and point b instead of what i have now
	

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{	
			if ((y + 1) < map->height)
				bresenham_line(((map->points[y][x].x  * map->scale) + map->x_offset), ((map->points[y][x].y  * map->scale) + map->y_offset), \
				((map->points[y][x].x  * map->scale) + map->x_offset), (((map->points[y][x].y + 1) * map->scale) + map->y_offset), map, map->points[y][x].colour);
			if (map->points[y][x].last_point == 0)
				bresenham_line(((map->points[y][x].x * map->scale) + map->x_offset), ((map->points[y][x].y  * map->scale) + map->y_offset), \
				(((map->points[y][x].x + 1) * map->scale) + map->x_offset), ((map->points[y][x].y * map->scale) + map->y_offset), map, map->points[y][x].colour);
			if (map->points[y][x].last_point == 1)
				break ;
			x++;
		}
		y++;
	}
}

