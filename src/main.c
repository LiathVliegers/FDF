/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:13:17 by livliege          #+#    #+#             */
/*   Updated: 2024/04/03 15:56:47 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	create_window(t_map_data* map)
{
	map->window = mlx_init(WIDTH, HEIGHT, map->title, false);
	map->image = mlx_new_image(map->window, WIDTH, HEIGHT);
	mlx_image_to_window(map->window, map->image, 0, 0);
	
	// draw_FDF(map);
	// rose_curve(map);
	
	mlx_loop_hook(map->window, key_is_pressed, map);
	mlx_loop(map->window);
	mlx_terminate(map->window);
}

int	main (int argc, char** argv)
{
	t_map_data	*map;

	if (argc != 2)
		ft_exit(1);	// 1: ERROR: Incorrect number of arguments

	map = (t_map_data*)ft_calloc(sizeof(t_map_data), 1);
	if (map == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed

	read_map(map, argv[1]);
	
	// print_map(map);
	
	create_window(map);
	
	clear_everything(map);
}





