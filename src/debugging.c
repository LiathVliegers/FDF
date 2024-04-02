/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 15:48:48 by livliege          #+#    #+#             */
/*   Updated: 2024/04/02 15:46:24 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


void print_map(t_map_data* map)
{
	ft_printf("title:	%s\n", map->title);
	ft_printf("height:	%d\n", map->height);
	ft_printf("width:	%d\n", map->width);
	ft_printf("scale: %d\n", (int)map->scale);
	ft_printf("x_offset: %d\n", (int)map->x_offset);
	ft_printf("y_offset: %d\n", (int)map->y_offset);
	// ft_printf("full buffer:	\n%s\n", map->full_map_buffer);

	// // print map lines (strings)
	// int i = 0;
	// while (i < map->height)
	// {
	// 	ft_printf("lines: %s\n", map->map_lines[i]);
	// 	i++;
	// }

	int y;
	int x;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			// ft_printf("y = %d ", (int)map->points[y][x].y);
			// ft_printf("x = %d ", (int)map->points[y][x].x);
			
			ft_printf("%d ", (int)map->points[y][x].z);
			// ft_printf("%d ", map->points[y][x].last_point);
			// ft_printf("colour = %X ", map->points[y][x].colour);
			// ft_printf("\n");
			x++;
		}
		ft_printf("\n"); // use this for the z values
		y++;
	}
}


