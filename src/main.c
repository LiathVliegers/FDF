/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livliege <livliege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:46:53 by livliege          #+#    #+#             */
/*   Updated: 2024/03/25 13:14:10 by livliege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"





void	create_window(t_map_data* map)
{
	map->window = mlx_init(WIDTH, HEIGHT, map->title, false);
	map->image = mlx_new_image(map->window, WIDTH, HEIGHT);
	mlx_image_to_window(map->window, map->image, 0, 0);
	
	// fill_image(map);
	// make_grid(map);
	// rose_curve(map);
	draw_FDF(map);
	
	mlx_loop_hook(map->window, key_is_pressed, map);
	mlx_loop(map->window);
	mlx_terminate(map->window);
}

int	main (int argc, char** argv)
{
	t_map_data	*map;

	if (argc != 2)
		ft_exit(1);	// 1: ERROR: Incorrect number of arguments

	map = (t_map_data*)malloc(sizeof(t_map_data));
	if (map == NULL)
		ft_exit(2);	// 2: ERROR: Memory allocation failed

	parse_map_file(argv[1], map);
	
	print_map(map);
	
	create_window(map);
	
	free_map(map);
}



