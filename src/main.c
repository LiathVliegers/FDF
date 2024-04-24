/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liath <liath@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 14:13:17 by livliege          #+#    #+#             */
/*   Updated: 2024/04/24 18:39:15 by liath            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void print_menu(t_map_data *map)
{
	map->menu_texture = mlx_load_png("./img/FDF(3).png");
	if (!map->menu_texture)
        ft_exit(7); // ERROR: Loading the menu failed
	map->menu_image = mlx_texture_to_image(map->window, map->menu_texture);
	if (!map->menu_image)
        ft_exit(7); // ERROR: Loading the image (menu) failed
	mlx_resize_image(map->menu_image, MENU_WIDTH, HEIGHT);
	if (mlx_image_to_window(map->window, map->menu_image, 0, 0) < 0)
        ft_exit(7); // ERROR: Loading the window (menu) failed
}

void	create_window(t_map_data* map)
{
	map->window = mlx_init(WIDTH, HEIGHT, map->title, false);
	// MAKE SURE TO PROTECT ALL THIS SHIT!
	map->image = mlx_new_image(map->window, WIDTH - MENU_WIDTH, HEIGHT);
	mlx_image_to_window(map->window, map->image, MENU_WIDTH, 0);

	print_menu(map);
	draw_FDF(map);
	// rose_curve(map);
	
	mlx_loop_hook(map->window, key_is_pressed, map);
	mlx_loop(map->window);
	
	// delete or free menu
	mlx_delete_image(map->window, map->menu_image);
	mlx_delete_texture(map->menu_texture);
	
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