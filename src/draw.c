/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:17:15 by livliege          #+#    #+#             */
/*   Updated: 2024/04/03 16:02:38 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define MAX(a, b)(a > b ? a : b)
#define MOD(a)(a < 0 ? -a : a)

void	bresenham_line(t_point a, t_point b, t_map_data *map)
{
	float	step_x;
	float	step_y;
	float	max;
	
	// zoom
	a.x *= map->scale;
	a.y *= map->scale;
	b.x *= map->scale;
	b.y *= map->scale;
	a.z *= map->z_scale;
	b.z *= map->z_scale;

	// isometric shit
	if (map->is_isometric > 0)
	{
		a.x = (a.x - a.y) * cos(map->angle);
		a.y = (a.x + a.y) * sin(map->angle) - a.z;
		b.x = (b.x - b.y) * cos(map->angle);
		b.y = (b.x + b.y) * sin(map->angle) - b.z;
	}
	
	// add offset
	a.x += map->x_offset;
	a.y += map->y_offset;
	b.x += map->x_offset;
	b.y += map->y_offset;

	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = MAX(MOD(step_x), MOD(step_y));
	step_x /= max;
	step_y /= max;

	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x >= 0 && a.y >= 0 && a.x < WIDTH && a.y < HEIGHT)
			mlx_put_pixel(map->image, a.x, a.y, a.colour);
		a.x += step_x;
		a.y += step_y;
	}
}


void draw_FDF(t_map_data *map)
{
	int		y;
	int		x;
	
	print_menu(map);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if ((y + 1) < map->height)
				bresenham_line(map->points[y][x], map->points[y + 1][x], map);
			if (map->points[y][x].last_point == 0)
				bresenham_line(map->points[y][x], map->points[y][x + 1], map);
			if (map->points[y][x].last_point == 1)
				break ;
			x++;
		}
		y++;
	}
}

// functie die de x punten returned (horizontale lijn) 
// functie die de y punten berekend, verticale lijn (fml)
// then you have a map
// dan kijken naar de octave van de bresenham line algorithm joepie
// thank you jisse
// No worries <3

