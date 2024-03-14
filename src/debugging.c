/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:47:44 by livliege          #+#    #+#             */
/*   Updated: 2024/03/14 10:19:38 by livliege         ###   ########.fr       */
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
			// ft_printf("x = %d ", map->points[y][x].x);
			// ft_printf("y = %d ", map->points[y][x].y);
			// ft_printf("z = %d\n", map->points[y][x].z);
			ft_printf("%d ", map->points[y][x].z);
			// ft_printf("%X ", map->points[y][x].colour);
			x++;
		}
		ft_printf("\n");
		y++;
	}
}



// ----------------------------------------------------


// void	print_menu(t_map_data *map)
// {
// 	char *menu;

// 	menu = "up, down, left, right: move picture";
// 	mlx_string_put(map.mlx_ptr, map.win_ptr, 10, 5, 0x03fc35, menu);
	
// }