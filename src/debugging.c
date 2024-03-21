/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:44 by livliege          #+#    #+#             */
/*   Updated: 2024/03/21 16:45:45 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void print_map(t_map_data* map)
{
	int x;
	int y;

	ft_printf("title: %s\n", map->title);
	ft_printf("height: %d\n", map->height);
	ft_printf("width: %d\n", map->width);

	ft_printf("x_offset: %d\n", map->x_offset);
	ft_printf("y_offset: %d\n", map->y_offset);
	
	ft_printf("scale: %d\n", (int)map->scale);
	ft_printf("z_scale: %d\n", (int)map->z_scale);
	ft_printf("angle: %d\n", (int)map->angle);

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			// ft_printf("%d ", (int)map->points[y][x].x);
			// ft_printf("%d ", (int)map->points[y][x].y);
			ft_printf("%d ", (int)map->points[y][x].z);
			// ft_printf("%d ", map->points[y][x].last_point);
			// ft_printf("%X ", map->points[y][x].colour);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}


void	fill_image(t_map_data *map)
{
	for (uint32_t x = 0; x < map->image->width; ++x)
	{
		for (uint32_t y = 0; y < map->image->height; ++y)
		{
			uint32_t color = 0x000000FF;
			mlx_put_pixel(map->image, x, y, color);
		}
	}
}

void	rose_curve(t_map_data *map)
{
	int colour = 0xFFFF00FF;
	float n = 2;
	float d = 9;
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
		// colour += 2550;
	}	
}



// ----------------------------------------------------


// void	print_menu(t_map_data *map)
// {
// 	char *menu;

// 	menu = "up, down, left, right: move picture";
// 	mlx_string_put(map.mlx_ptr, map.win_ptr, 10, 5, 0x03fc35, menu);
	
// }


