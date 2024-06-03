/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:48:48 by livliege          #+#    #+#             */
/*   Updated: 2024/06/03 15:59:00 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// functie die de x punten returned (horizontale lijn) 
// functie die de y punten berekend, verticale lijn (fml)
// then you have a map
// dan kijken naar de octave van de bresenham line algorithm joepie
// thank you jisse
// No worries <3

// check if a and point b have same colour
// if not: calculate distnace between the points, NO.
// Never mind.
// jawel you can do it :)
// oke :(

#include "../inc/fdf.h"

void	print_map(t_map_data *map)
{
	int	y;
	int	x;

	ft_printf("title:	%s\n", map->title);
	ft_printf("height:	%d\n", map->height);
	ft_printf("width:	%d\n", map->width);
	ft_printf("scale: %d\n", (int)map->scale);
	ft_printf("x_offset: %d\n", (int)map->x_offset);
	ft_printf("y_offset: %d\n", (int)map->y_offset);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_printf("y = %d ", (int)map->points[y][x].y);
			ft_printf("x = %d ", (int)map->points[y][x].x);
			ft_printf("\n");
			x++;
		}
		y++;
	}
}

void	rose_curve(t_map_data *map)
{
	int		colour;
	float	n;
	float	d;
	float	k;
	float	angle;
	float	radius;
	int		x;
	int		y;

	n = 5;
	d = 6;
	k = n / d;
	angle = 0;
	colour = 0xFFFF00FF;
	while (angle < 3610)
	{
		radius = 500 * cos(k * angle);
		x = radius * cos(angle);
		y = radius * sin(angle);
		mlx_put_pixel(map->image, x + (WIDTH / 2), y + (HEIGHT / 2), colour);
		angle += 0.001;
		colour += 2550;
	}
}
