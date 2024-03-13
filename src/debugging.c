/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:44 by livliege          #+#    #+#             */
/*   Updated: 2024/03/13 18:00:02 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void print_map(t_map_data* map)
{
	int x;
	int y;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf("%d ", map->points[y][x].z);
			// ft_printf("%X ", map->points[y][x].colour);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}






// ----------------------------------------------------

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
	
	while (angle < 3610)
	{
		radius = 500 * cos(k * angle);
		x = radius * cos(angle);
		y = radius * sin(angle);
		mlx_put_pixel(map->image, x + (WIDTH / 2), y + (HEIGHT / 2), colour);
		angle += 0.001;
		colour += 20000;
	}	
}


void make_grid(t_map_data* map)
{
	int x;
	int y;
	int grid;

	x = 0;
	y = 0;
	grid = 100;
	while (y <= HEIGHT)
	{
		x = 0;
		while (x <= WIDTH)
		{
			bresenham_line(x, 0, x, HEIGHT, map);
			x += grid;
		}
		bresenham_line(0, y, WIDTH, y, map);
		y += grid;
	}
}