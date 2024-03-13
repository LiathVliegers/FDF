/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:44 by livliege          #+#    #+#             */
/*   Updated: 2024/03/13 19:56:09 by livliege         ###   ########.fr       */
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
			ft_printf("x = %d ", map->points[y][x].x);
			ft_printf("y = %d ", map->points[y][x].y);
			ft_printf("z = %d\n", map->points[y][x].z);
			// ft_printf("%X ", map->points[y][x].colour);
			x++;
		}
		// ft_printf("\n");
		y++;
	}
}



// ----------------------------------------------------


