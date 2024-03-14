/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:27:43 by livliege          #+#    #+#             */
/*   Updated: 2024/03/14 10:32:42 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define MAX(a, b)(a > b ? a : b)
#define MOD(a)(a < 0 ? -a : a)

void bresenham_line(float x, float y, float x1, float y1, t_map_data *map)
{
	float x_step;
	float y_step;
	int max;
	uint32_t colour;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	
	colour = 0xFFFFFF;
	while((int)(x - x1) || (int)(y - y1))
	{
		mlx_put_pixel(map->image, x, y, colour);
		x += x_step;
		y += y_step;
	}
}


// void	draw_terrain(t_map_data *map)
// {
// 	// size of the lines is the amout of points (the width of the array) / IMG_WIDTH
// 	// 
	
// 	int x;
// 	int y;
	
// 	x = 0;
// 	y = 0;
	
// 	while (y < map->height)
// 	{
// 		x = 0;
// 		while (x < map->width)
// 		{
// 			x++;
// 		}
// 		y++;
// 	}
// }


void	fill_image(t_map_data *map)
{
	for (uint32_t x = 0; x < map->image->width; ++x)
	{
		for (uint32_t y = 0; y < map->image->height; ++y)
		{
			uint32_t color = 0x00FFFFFF;
			mlx_put_pixel(map->image, x, y, color);
		}
	}
}

void	rose_curve(t_map_data *map)
{
	int colour = 0xFFFFFFFF;
	float n = 5;
	float d = 8;
	float k = n / d;
	float angle = 0;
	float radius;
	int x;
	int y;
	
	while (angle < 361)
	{
		radius = 500 * cos(k * angle);
		x = radius * cos(angle);
		y = radius * sin(angle);
		mlx_put_pixel(map->image, x + (WIDTH / 2) - OFFSET, y + (HEIGHT / 2) - OFFSET, colour);
		angle += 0.01;
		colour += 2550;
	}	
}


void make_grid(t_map_data* map)
{
	float x;
	float y;
	float grid;

	x = 0;
	y = 0;
	grid = 99.99;
	while (y <= IMG_HEIGHT)
	{
		x = 0;
		while (x <= IMG_WIDTH)
		{
			bresenham_line(x, 0, x, IMG_HEIGHT, map);
			x += grid;
		}
		bresenham_line(0, y, IMG_WIDTH, y, map);
		y += grid;
	}
}
